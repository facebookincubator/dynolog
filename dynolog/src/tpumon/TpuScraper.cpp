/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include "dynolog/src/tpumon/TpuScraper.h"

#include <curl/curl.h>
#include <fmt/format.h>
#include <glog/logging.h>

#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <mutex>
#include <string_view>
#include <utility>

namespace dynolog::tpumon {

namespace {

// libcurl requires a one-time global init before any other curl call.
// OtlpMetricsLogger already calls this in some builds, but TpuScraper
// may be constructed on TPU pods that don't use the OTLP metrics path
// (they use the OTLP logs path via OtlpLogger). Use a mutex-guarded
// boolean rather than std::once_flag / std::call_once to keep dynolog
// OSS-compatible without folly and to avoid the once_flag lint.
void ensureCurlGlobalInit() {
  static std::mutex init_mu;
  static bool initialized = false;
  std::lock_guard<std::mutex> lock(init_mu);
  if (initialized) {
    return;
  }
  const CURLcode rc = curl_global_init(CURL_GLOBAL_DEFAULT);
  if (rc != CURLE_OK) {
    LOG(ERROR) << "TpuScraper: curl_global_init() failed: "
               << curl_easy_strerror(rc);
  }
  initialized = true;
}

size_t curlWriteToString(char* ptr, size_t size, size_t nmemb, void* userdata) {
  const size_t total = size * nmemb;
  auto* out = static_cast<std::string*>(userdata);
  try {
    out->append(ptr, total);
  } catch (const std::exception& ex) {
    LOG(ERROR) << "TpuScraper: exception in curlWriteToString: " << ex.what();
    return 0;
  }
  return total;
}

bool nameMatchesAllowlist(
    std::string_view name,
    const std::vector<std::string>& allowlist) {
  if (allowlist.empty()) {
    return true;
  }
  for (const auto& prefix : allowlist) {
    if (name.rfind(prefix, 0) == 0) { // starts_with (C++17)
      return true;
    }
  }
  return false;
}

// Skip leading whitespace in `s`.
void skipWhitespace(std::string_view& s) {
  size_t i = 0;
  while (i < s.size() && (s[i] == ' ' || s[i] == '\t')) {
    ++i;
  }
  s.remove_prefix(i);
}

// Parse a single Prometheus label-value string starting at the opening quote.
// Advances `s` past the closing quote. Returns false on malformed input.
// Handles \\, \", \n escapes per the spec.
bool parseLabelValue(std::string_view& s, std::string& out) {
  if (s.empty() || s.front() != '"') {
    return false;
  }
  s.remove_prefix(1);
  out.clear();
  while (!s.empty()) {
    const char c = s.front();
    if (c == '"') {
      s.remove_prefix(1);
      return true;
    }
    if (c == '\\') {
      if (s.size() < 2) {
        return false;
      }
      const char esc = s[1];
      if (esc == 'n') {
        out.push_back('\n');
      } else {
        // Covers \\ and \", and any other char passes through literally.
        out.push_back(esc);
      }
      s.remove_prefix(2);
      continue;
    }
    out.push_back(c);
    s.remove_prefix(1);
  }
  return false; // unterminated string
}

// Parse a `key="value",key2="value2"` label block starting AFTER the opening
// '{' and ending AT the matching '}'. Advances `s` past the '}'.
bool parseLabels(
    std::string_view& s,
    std::unordered_map<std::string, std::string>& labels) {
  while (!s.empty()) {
    skipWhitespace(s);
    if (s.empty()) {
      return false;
    }
    if (s.front() == '}') {
      s.remove_prefix(1);
      return true;
    }
    // Read label name up to '='.
    size_t eq = s.find('=');
    if (eq == std::string_view::npos) {
      return false;
    }
    std::string key(s.substr(0, eq));
    s.remove_prefix(eq + 1);
    std::string value;
    if (!parseLabelValue(s, value)) {
      return false;
    }
    labels.emplace(std::move(key), std::move(value));
    skipWhitespace(s);
    if (!s.empty() && s.front() == ',') {
      s.remove_prefix(1);
    }
  }
  return false;
}

// Parse a numeric value token. Returns false if the value is a
// non-finite Prometheus special (+Inf, -Inf, NaN) — those samples are
// dropped rather than propagated as sentinel doubles.
bool parseValue(std::string_view s, double& out) {
  skipWhitespace(s);
  if (s.empty()) {
    return false;
  }
  // Take up to next whitespace / end of line as the numeric token.
  size_t end = 0;
  while (end < s.size() && s[end] != ' ' && s[end] != '\t') {
    ++end;
  }
  const std::string token(s.substr(0, end));
  if (token == "+Inf" || token == "-Inf" || token == "Inf" || token == "NaN") {
    return false;
  }
  char* endp = nullptr;
  const double v = std::strtod(token.c_str(), &endp);
  if (endp == token.c_str()) {
    return false;
  }
  if (!std::isfinite(v)) {
    return false;
  }
  out = v;
  return true;
}

} // namespace

std::vector<TpuSample> parsePrometheusText(const std::string& body) {
  std::vector<TpuSample> out;
  out.reserve(64);
  size_t pos = 0;
  while (pos < body.size()) {
    const size_t nl = body.find('\n', pos);
    const size_t end = (nl == std::string::npos) ? body.size() : nl;
    std::string_view line(body.data() + pos, end - pos);
    pos = end + 1;

    // Trim trailing \r for CRLF endpoints.
    if (!line.empty() && line.back() == '\r') {
      line.remove_suffix(1);
    }
    if (line.empty()) {
      continue;
    }
    if (line.front() == '#') {
      continue; // HELP / TYPE / free-form comments
    }

    // Extract metric name (up to '{' or whitespace).
    size_t name_end = 0;
    while (name_end < line.size() && line[name_end] != '{' &&
           line[name_end] != ' ' && line[name_end] != '\t') {
      ++name_end;
    }
    if (name_end == 0) {
      VLOG(2) << "TpuScraper: skipping malformed line (no name): " << line;
      continue;
    }
    TpuSample sample;
    sample.name.assign(line.data(), name_end);
    std::string_view rest = line.substr(name_end);

    if (!rest.empty() && rest.front() == '{') {
      rest.remove_prefix(1);
      if (!parseLabels(rest, sample.labels)) {
        VLOG(2) << "TpuScraper: skipping malformed labels: " << line;
        continue;
      }
    }
    double value = 0.0;
    if (!parseValue(rest, value)) {
      VLOG(2) << "TpuScraper: skipping unparseable value: " << line;
      continue;
    }
    sample.value = value;
    out.push_back(std::move(sample));
  }
  return out;
}

TpuScraper::TpuScraper(
    std::string url,
    int timeout_ms,
    std::vector<std::string> allowlist)
    : url_{std::move(url)},
      timeout_ms_{timeout_ms},
      allowlist_{
          allowlist.empty()
              ? std::vector<
                    std::
                        string>{std::begin(kDefaultTpuMetricAllowlist), std::end(kDefaultTpuMetricAllowlist)}
              : std::move(allowlist)} {
  ensureCurlGlobalInit();
}

std::vector<TpuSample> TpuScraper::scrape() {
  failing_ = false;
  last_error_.clear();

  CURL* curl = curl_easy_init();
  if (curl == nullptr) {
    failing_ = true;
    last_error_ = "curl_easy_init() returned nullptr";
    LOG(ERROR) << "TpuScraper: " << last_error_;
    return {};
  }

  std::string body;
  body.reserve(64 * 1024);

  curl_easy_setopt(curl, CURLOPT_URL, url_.c_str());
  curl_easy_setopt(curl, CURLOPT_HTTPGET, 1L);
  curl_easy_setopt(curl, CURLOPT_TIMEOUT_MS, static_cast<long>(timeout_ms_));
  curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT_MS, static_cast<long>(1000));
  curl_easy_setopt(curl, CURLOPT_NOSIGNAL, 1L);
  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, curlWriteToString);
  curl_easy_setopt(curl, CURLOPT_WRITEDATA, &body);

  const CURLcode rc = curl_easy_perform(curl);
  long http_code = 0;
  curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);
  curl_easy_cleanup(curl);

  if (rc != CURLE_OK) {
    failing_ = true;
    last_error_ = fmt::format("curl_easy_perform: {}", curl_easy_strerror(rc));
    LOG_EVERY_N(ERROR, 60) << "TpuScraper: " << last_error_ << " (url=" << url_
                           << ")";
    return {};
  }
  if (http_code < 200 || http_code >= 300) {
    failing_ = true;
    last_error_ = fmt::format("HTTP {}", http_code);
    LOG_EVERY_N(ERROR, 60) << "TpuScraper: " << last_error_ << " (url=" << url_
                           << ")";
    return {};
  }

  auto samples = parsePrometheusText(body);
  if (!allowlist_.empty()) {
    samples.erase(
        std::remove_if(
            samples.begin(),
            samples.end(),
            [this](const TpuSample& s) {
              return !nameMatchesAllowlist(s.name, allowlist_);
            }),
        samples.end());
  }
  return samples;
}

} // namespace dynolog::tpumon
