/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include "dynolog/src/tpumon/TpuScraper.h"

#include <gtest/gtest.h>
#include <stdexcept>
#include <string>
#include <vector>

namespace dynolog::tpumon {
namespace {

// Real exposition captured from tpu-device-plugin v1.35.7-gke.0 on a
// tpu7x-standard-4t node (test-tpu-cluster). Trimmed for the test:
// * 4 bound chips (indices 4-7) carry namespace/pod/container labels
// * memory_bandwidth_utilization is node-only (see plan Appendix A)
// * Go runtime lines are included to exercise the allowlist filter
constexpr const char* kProbeOutputTpu7x =
    R"PROM(# HELP duty_cycle Percent of time when the TPU was actively processing
# TYPE duty_cycle gauge
duty_cycle{accelerator_id="1234567890123456789-4",container="vllm-worker",make="cloud-tpu",model="tpu7x",namespace="test-namespace",pod="test-workload-pod",tpu_topology="2x2x2"} 0
# HELP duty_cycle_node Percent of time when the TPU was actively processing
# TYPE duty_cycle_node gauge
duty_cycle_node{accelerator_id="1234567890123456789-0",make="cloud-tpu",model="tpu7x",tpu_topology="2x2x2"} 0
duty_cycle_node{accelerator_id="1234567890123456789-4",make="cloud-tpu",model="tpu7x",tpu_topology="2x2x2"} 0
# HELP memory_total Total memory available on the TPU in bytes
# TYPE memory_total gauge
memory_total{accelerator_id="1234567890123456789-4",container="vllm-worker",make="cloud-tpu",model="tpu7x",namespace="test-namespace",pod="test-workload-pod",tpu_topology="2x2x2"} 2.03465670656e+11
# HELP memory_used Allocated TPU memory in bytes
# TYPE memory_used gauge
memory_used{accelerator_id="1234567890123456789-4",container="vllm-worker",make="cloud-tpu",model="tpu7x",namespace="test-namespace",pod="test-workload-pod",tpu_topology="2x2x2"} 1.76938736128e+11
# HELP memory_bandwidth_utilization_node Memory bandwidth utilization of the TPU device per node
# TYPE memory_bandwidth_utilization_node gauge
memory_bandwidth_utilization_node{accelerator_id="1234567890123456789-0",make="cloud-tpu",model="tpu7x",tpu_topology="2x2x2"} 42.5
# HELP tensorcore_utilization_node Tensorcore percent utilization of the TPU device per node
# TYPE tensorcore_utilization_node gauge
tensorcore_utilization_node{accelerator_id="1234567890123456789-0",make="cloud-tpu",model="tpu7x",tpu_topology="2x2x2"} 0
# HELP go_goroutines Number of goroutines that currently exist.
# TYPE go_goroutines gauge
go_goroutines 34
process_cpu_seconds_total 5699.87
promhttp_metric_handler_requests_total{code="200"} 37730
)PROM";

// Returns a reference to the matching sample, or aborts the test via
// GTEST fatal ADD_FAILURE + a throw. Return-by-reference avoids the
// nullable-pointer deref pattern that NULLSAFECLANG flags after
// ASSERT_NE (which the static analyzer cannot see through).
const TpuSample& sampleByNameAndAccel(
    const std::vector<TpuSample>& samples,
    const std::string& name,
    const std::string& accel_id) {
  for (const auto& s : samples) {
    if (s.name != name) {
      continue;
    }
    auto it = s.labels.find("accelerator_id");
    if (it != s.labels.end() && it->second == accel_id) {
      return s;
    }
  }
  ADD_FAILURE() << "sample not found: name=" << name
                << " accelerator_id=" << accel_id;
  throw std::runtime_error("sample not found");
}

bool hasSample(
    const std::vector<TpuSample>& samples,
    const std::string& name,
    const std::string& accel_id) {
  for (const auto& s : samples) {
    if (s.name != name) {
      continue;
    }
    auto it = s.labels.find("accelerator_id");
    if (it != s.labels.end() && it->second == accel_id) {
      return true;
    }
  }
  return false;
}

TEST(ParsePrometheusTextTest, ParsesRealTpuDevicePluginExposition) {
  const auto samples = parsePrometheusText(kProbeOutputTpu7x);

  // Bound chip -4 should have BOTH the container-labelled duty_cycle and
  // the node-labelled duty_cycle_node.
  const auto& container_dc =
      sampleByNameAndAccel(samples, "duty_cycle", "1234567890123456789-4");
  EXPECT_EQ(container_dc.labels.at("container"), "vllm-worker");
  EXPECT_EQ(container_dc.labels.at("namespace"), "test-namespace");
  EXPECT_EQ(container_dc.labels.at("model"), "tpu7x");
  EXPECT_EQ(container_dc.labels.at("make"), "cloud-tpu");
  EXPECT_EQ(container_dc.value, 0.0);

  const auto& node_dc =
      sampleByNameAndAccel(samples, "duty_cycle_node", "1234567890123456789-4");
  EXPECT_EQ(node_dc.labels.count("container"), 0u);
  EXPECT_EQ(node_dc.labels.count("pod"), 0u);

  // Unbound chip -0 should only have the node-labelled series.
  EXPECT_FALSE(hasSample(samples, "duty_cycle", "1234567890123456789-0"));
  EXPECT_TRUE(hasSample(samples, "duty_cycle_node", "1234567890123456789-0"));
}

TEST(ParsePrometheusTextTest, ScientificAndPlainNumericValues) {
  const auto samples = parsePrometheusText(kProbeOutputTpu7x);

  const auto& mem_total =
      sampleByNameAndAccel(samples, "memory_total", "1234567890123456789-4");
  EXPECT_DOUBLE_EQ(mem_total.value, 2.03465670656e+11);

  const auto& mem_bw = sampleByNameAndAccel(
      samples, "memory_bandwidth_utilization_node", "1234567890123456789-0");
  EXPECT_DOUBLE_EQ(mem_bw.value, 42.5);
}

TEST(ParsePrometheusTextTest, SkipsCommentsAndBlankLines) {
  const std::string body =
      "# HELP foo bar\n"
      "\n"
      "# TYPE foo gauge\n"
      "foo 1.5\n"
      "\n";
  const auto samples = parsePrometheusText(body);
  ASSERT_EQ(samples.size(), 1u);
  EXPECT_EQ(samples[0].name, "foo");
  EXPECT_DOUBLE_EQ(samples[0].value, 1.5);
}

TEST(ParsePrometheusTextTest, DropsNonFiniteValues) {
  const std::string body =
      "good 1.0\n"
      "posinf +Inf\n"
      "neginf -Inf\n"
      "notanumber NaN\n"
      "good2 2.0\n";
  const auto samples = parsePrometheusText(body);
  ASSERT_EQ(samples.size(), 2u);
  EXPECT_EQ(samples[0].name, "good");
  EXPECT_EQ(samples[1].name, "good2");
}

TEST(ParsePrometheusTextTest, HandlesEscapedLabelValues) {
  const std::string body =
      "foo{key=\"line1\\nline2\",path=\"a\\\\b\",quote=\"say \\\"hi\\\"\"} 42\n";
  const auto samples = parsePrometheusText(body);
  ASSERT_EQ(samples.size(), 1u);
  EXPECT_EQ(samples[0].labels.at("key"), "line1\nline2");
  EXPECT_EQ(samples[0].labels.at("path"), "a\\b");
  EXPECT_EQ(samples[0].labels.at("quote"), "say \"hi\"");
}

TEST(ParsePrometheusTextTest, HandlesCrlfLineEndings) {
  const std::string body = "foo 1\r\nbar 2\r\n";
  const auto samples = parsePrometheusText(body);
  ASSERT_EQ(samples.size(), 2u);
  EXPECT_EQ(samples[0].name, "foo");
  EXPECT_EQ(samples[1].name, "bar");
}

TEST(TpuScraperAllowlistTest, DefaultAllowlistDropsGoRuntimeAndPromhttp) {
  const auto samples = parsePrometheusText(kProbeOutputTpu7x);
  // Sanity: parser preserves Go runtime and promhttp metrics.
  bool found_go = false;
  bool found_promhttp = false;
  for (const auto& s : samples) {
    if (s.name == "go_goroutines") {
      found_go = true;
    }
    if (s.name == "promhttp_metric_handler_requests_total") {
      found_promhttp = true;
    }
  }
  EXPECT_TRUE(found_go);
  EXPECT_TRUE(found_promhttp);

  // Apply the same allowlist filtering logic as TpuScraper::scrape():
  // keep a sample if its name starts with any prefix in
  // kDefaultTpuMetricAllowlist.
  const std::vector<std::string> allowlist(
      std::begin(kDefaultTpuMetricAllowlist),
      std::end(kDefaultTpuMetricAllowlist));
  auto isAllowed = [&allowlist](const TpuSample& s) {
    for (const auto& prefix : allowlist) {
      if (s.name.rfind(prefix, 0) == 0) {
        return true;
      }
    }
    return false;
  };

  std::vector<TpuSample> filtered;
  for (const auto& s : samples) {
    if (isAllowed(s)) {
      filtered.push_back(s);
    }
  }

  // Go runtime and promhttp metrics must be dropped by the allowlist.
  for (const auto& s : filtered) {
    EXPECT_NE(s.name, "go_goroutines");
    EXPECT_NE(s.name, "promhttp_metric_handler_requests_total");
    EXPECT_NE(s.name, "process_cpu_seconds_total");
  }

  // At least one sample from each allowed family should survive.
  bool has_duty = false;
  bool has_tensorcore = false;
  bool has_mem_total = false;
  bool has_mem_used = false;
  bool has_mem_bw = false;
  for (const auto& s : filtered) {
    if (s.name.rfind("duty_cycle", 0) == 0) {
      has_duty = true;
    } else if (s.name.rfind("tensorcore_utilization", 0) == 0) {
      has_tensorcore = true;
    } else if (s.name.rfind("memory_total", 0) == 0) {
      has_mem_total = true;
    } else if (s.name.rfind("memory_used", 0) == 0) {
      has_mem_used = true;
    } else if (s.name.rfind("memory_bandwidth_utilization", 0) == 0) {
      has_mem_bw = true;
    }
  }
  EXPECT_TRUE(has_duty);
  EXPECT_TRUE(has_tensorcore);
  EXPECT_TRUE(has_mem_total);
  EXPECT_TRUE(has_mem_used);
  EXPECT_TRUE(has_mem_bw);
}

} // namespace
} // namespace dynolog::tpumon
