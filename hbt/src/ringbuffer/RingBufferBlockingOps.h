// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#include "hbt/src/ringbuffer/RingBuffer.h"

#include <thread>

namespace facebook::hbt::ringbuffer {

struct RetryParams {
  std::chrono::milliseconds timeout;
  std::optional<std::chrono::milliseconds> wait_dur;

  static RetryParams makeDefault() {
    return RetryParams{
        std::chrono::milliseconds(500), std::chrono::milliseconds(50)};
  }
};

/// Returns true if succeded before timeout.
[[nodiscard]] bool waitForFunction(
    std::function<bool()> done_function,
    std::optional<RetryParams> opt_params) {
  RetryParams params = opt_params.value_or(RetryParams::makeDefault());
  auto deadline = std::chrono::high_resolution_clock::now() + params.timeout;
  while (!done_function()) {
    if (deadline < std::chrono::high_resolution_clock::now()) {
      return false;
    }
    // else will retry after waiting.
    // Note that wait_dur == nullopt means do not yield (active wait).
    if (params.wait_dur.has_value()) {
      std::this_thread::sleep_for(*params.wait_dur);
    }
  }
  return true;
}

enum WriteType { SizedChunk, SizedWrite };

template <class TProducer, WriteType kWriteType>
ssize_t blockingWrite(
    TProducer& p,
    const std::string& str,
    std::optional<RetryParams> opt_params) {
  RetryParams params = opt_params.value_or(RetryParams::makeDefault());
  auto deadline = std::chrono::high_resolution_clock::now() + params.timeout;
  ssize_t ret;
  do {
    if constexpr (kWriteType == WriteType::SizedChunk) {
      ret = p.template writeSizedChunk<uint32_t>(str);
    } else {
      static_assert(kWriteType == WriteType::SizedWrite);
      ret = p.write(str.c_str(), str.length());
    }
    if (0 <= ret) {
      return ret;
    } else if (ret == -EINVAL) {
      HBT_THROW_EINVAL() << "Invalid write size for RingBuffer";
    }
    // else will retry after waiting.
    // Note that wait_dur == nullopt means do not yield (active wait).
    if (params.wait_dur.has_value()) {
      std::this_thread::sleep_for(*params.wait_dur);
    }
  } while (deadline >= std::chrono::high_resolution_clock::now());
  HBT_THROW_SYSTEM(-ret)
      << "Timeout of " << params.timeout.count()
      << " ms has expired while waiting to write on RingBuffer";
  return ret;
};

enum class ReadType {
  // Read data that contains a size preffix.
  SizedChunk,
  // Read the given amount of data.
  SizedRead,
  // Read until a line break.
  Line
};

template <class TConsumer, class TRet, ReadType kReadType>
std::optional<TRet> blockingRead(
    TConsumer& c,
    std::optional<ssize_t> len,
    std::optional<RetryParams> opt_params) {
  RetryParams params = opt_params.value_or(RetryParams::makeDefault());
  auto end = std::chrono::high_resolution_clock::now() + params.timeout;
  std::error_code err;
  do {
    // Read according to kReadType.
    if constexpr (kReadType == ReadType::SizedChunk) {
      auto [ret, obj] = c.template readSizedChunk<uint32_t, TRet>();
      if (ret >= 0) {
        return obj;
      } else {
        HBT_THROW_EINVAL_IF(ret == -EINVAL)
            << "Invalid read size for RingBuffer";
        err = toErrorCode(-ret);
      }
    } else if constexpr (kReadType == ReadType::SizedRead) {
      if (len.has_value() && *len > 0) {
        if (auto [ret, b] = c.template read<TRet>(*len); 0 <= ret) {
          return *b;
        } else {
          err = toErrorCode(-ret);
        }
      } else {
        if (auto [ret, b] =
                c.template readChunk<true, 0x0 /* unused */, TRet>();
            0 <= ret) {
          return *b;
        } else {
          err = toErrorCode(-ret);
        }
      }
    } else {
      static_assert(kReadType == ReadType::Line);
      auto [ret, b] = c.template readChunk<false, '\n', TRet>();
      if (0 <= ret) {
        return *b;
      } else {
        err = toErrorCode(-ret);
      }
    }
    // else will retry after waiting.
    // Note that wait_dur == nullopt means do not yield (active wait).
    if (params.wait_dur.has_value()) {
      std::this_thread::sleep_for(*params.wait_dur);
    }
  } while (end >= std::chrono::high_resolution_clock::now());
  HBT_THROW_SYSTEM_CODE(err)
      << "Timeout of " << params.timeout.count()
      << " ms has expired while waiting to read on RingBuffer";
  return std::nullopt;
};

} // namespace facebook::hbt::ringbuffer
