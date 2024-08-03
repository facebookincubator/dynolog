// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#pragma once

#include <chrono>
#include <ctime>
#include <functional>
#include <iomanip>
#include <iostream>
#include <optional>
#include <sstream>
#include <string>
#include <system_error>

#include <sys/types.h>
#include <unistd.h>

// A metric could define a function to reduce multiple event values.
// ReducerFunc type is used as the reducer functor for these values.
// - note that events will always be uint64_t as that is the type
//   used by the kernel perf_event system call.
using ReducerFunc =
    std::function<std::optional<double>(const std::vector<uint64_t>&)>;

// Branch hint macros. C++20 will include them as part of language.
#define __hbt_likely(x) __builtin_expect(!!(x), 1)
#define __hbt_unlikely(x) __builtin_expect(!!(x), 0)

template <class TStream>
TStream& LogCtxt(TStream& oss) {
  oss << "pid: " << ::getpid() << " on ";
  // Put date and time.
  auto p = std::chrono::system_clock::now();
  auto t_c = std::chrono::system_clock::to_time_t(p);
  oss << std::put_time(std::localtime(&t_c), "%F %T");
  // Put microseconds.
  oss << "."
      << std::chrono::duration_cast<std::chrono::microseconds>(
             p.time_since_epoch())
              .count() %
          1'000'000
      << " ";
  return oss;
}

/// Auxiliar class to build exception, fill up it's what message and throw
/// in a single line. Usually uses as r-value so that destructor is called
/// at end of line that created it, throwing the desired exception.
/// (See HBT_THROW).
template <class TException>
class ExceptionThrower final {
 public:
  template <class... TArgs>
  ExceptionThrower(TArgs&&... non_what) {
    ex_builder_ = [&](const std::string& what) {
      return TException(std::move(non_what)..., what);
    };
  }

  // Throw exception on destructor, when l-value instance goes of scope
  // and stream has been written. Use noexcept(false) to inform the compiler
  // that it's ok to throw in destructor.
  ~ExceptionThrower() noexcept(false) {
    throw ex_builder_("\"" + oss_.str() + "\"");
  }

  std::ostream& getStream() {
    return oss_;
  }

 protected:
  std::function<TException(const std::string&)> ex_builder_;
  std::ostringstream oss_;
};

//
// Exception for knwon errors in the environment that can be fixed at the
// user interface or daemon level, usually caused by environment's
// misconfiguration or unexpected state.
//
class EnvironmentError : public std::exception {
 public:
  enum class Type {
    // No capabilities to open perf_event event.
    // Either need perf_event_paranoid or CAP_TRACING.
    MissingPerfEventCaps,
    // Shared-Memory Segment already exists.
    ShmExists,
    // No enough memory. Possibility because memory usage
    // will exceed RLIMI.
    NoMemory,
  };

  explicit EnvironmentError(Type type, const std::string& what)
      : std::exception(), type_{type}, what_{what} {}

  virtual const char* what() const noexcept override {
    return what_.c_str();
  }

  auto type() const noexcept {
    return type_;
  }

 protected:
  Type type_;
  std::string what_;
};

//
// Macros to throw commonly used exceptions.
//
#define HBT_STRINGIFY(s) #s
#define HBT_EXPAND_TO_STR(s) HBT_STRINGIFY(s)

#define HBT_LOG_LOC __FILE__ ":" HBT_EXPAND_TO_STR(__LINE__)
#define HBT_LOG_PREFFIX "In " << __func__ << " at " HBT_LOG_LOC

#define HBT_THROW(ex_type, ...)                               \
  LogCtxt(ExceptionThrower<ex_type>(__VA_ARGS__).getStream()) \
      << HBT_LOG_PREFFIX << ". "

#define HBT_THROW_EINVAL() HBT_THROW(std::invalid_argument)
#define HBT_THROW_EINVAL_IF(cond) \
  if (__hbt_unlikely(cond))       \
  HBT_THROW_EINVAL() << "\t" << HBT_STRINGIFY(cond) << ". "

#define HBT_THROW_ENVIRONMENT(err) HBT_THROW(EnvironmentError, err)
#define HBT_THROW_ENVIRONMENT_IF(cond, err) \
  if (__hbt_unlikely(cond))                 \
  HBT_THROW_ENVIRONMENT(err) << "\t" << HBT_STRINGIFY(cond) << ". "

#define HBT_THROW_SYSTEM(err) \
  HBT_THROW(std::system_error, err, std::system_category())
#define HBT_THROW_SYSTEM_IF(cond, err) \
  if (__hbt_unlikely(cond))            \
  HBT_THROW_SYSTEM(err) << "\t" << HBT_STRINGIFY(cond) << ". "

#define HBT_THROW_SYSTEM_CODE(err) HBT_THROW(std::system_error, err)
#define HBT_THROW_SYSTEM_CODE_IF(cond, err) \
  if (__hbt_unlikely(cond))                 \
  HBT_THROW_SYSTEM_CODE(err) << "\t" << HBT_STRINGIFY(cond) << ". "

#define HBT_THROW_ASSERT() HBT_THROW(std::runtime_error)
#define HBT_THROW_ASSERT_IF(cond) \
  if (__hbt_unlikely(cond))       \
  HBT_THROW_ASSERT() << "\t" << HBT_STRINGIFY(cond) << ". "

// Conditional throwing exception
#define HBT_THROW_IF_NULLPTR(ptr)     \
  if (__hbt_unlikely(ptr == nullptr)) \
  HBT_THROW_EINVAL() << HBT_STRINGIFY(ptr) << " has nullptr value. "

// Safe-cast to std::error_code
inline std::error_code toErrorCode(ssize_t e) {
  if (__hbt_unlikely(e <= 0)) {
    HBT_THROW_EINVAL() << "\n\tError " << e << " is not a positive number. "
                       << " Is this value really an error?";
  } else if (__hbt_unlikely(e > std::numeric_limits<int>::max())) {
    HBT_THROW_EINVAL() << "\n\tError " << e << " is out of range. "
                       << " Is this really an error?";
  }
  return {static_cast<int>(e), std::system_category()};
}

//
// Simple logging to stderr. This macros can be replaced if a more
// sophisticated logging is used in the future.
// Currently, hbt is meant be used as shared library and to use
// exceptions for error handling, so there is reduced need for logging
// inside the libary.
//
class LogEntry final {
 public:
  ~LogEntry() noexcept {
    std::cerr << oss_.str() << std::endl;
  }

  std::ostream& logPreamble(const std::string& preffix) {
    oss_ << preffix;
    return LogCtxt(oss_);
  }

 protected:
  std::ostringstream oss_;
};

#define HBT_LOG_INFO()                         \
  LogEntry().logPreamble("\033[1m[ hbt info ") \
      << "\n  " << HBT_LOG_PREFFIX << "]\n => \033[0m"
#define HBT_LOG_WARNING()                            \
  LogEntry().logPreamble("\033[1;33m[ hbt warning ") \
      << "\n  " << HBT_LOG_PREFFIX << "]\n => \033[0m"
#define HBT_LOG_ERROR()                            \
  LogEntry().logPreamble("\033[1;31m[ hbt error ") \
      << "\n  " << HBT_LOG_PREFFIX << "]\n => \033[0m"

#define HBT_LOG_INFO_IF(cond) \
  if (__hbt_unlikely(cond))   \
  HBT_LOG_INFO()
#define HBT_LOG_WARNING_IF(cond) \
  if (__hbt_unlikely(cond))      \
  HBT_LOG_WARNING()
#define HBT_LOG_ERROR_IF(cond) \
  if (__hbt_unlikely(cond))    \
  HBT_LOG_ERROR()

#define HBT_DCHECK_NOT_NULLPTR(t)     \
  if (__hbt_unlikely((t) == nullptr)) \
  HBT_THROW_ASSERT() << "\n\tExpected argument to be not null."

#define __HBT_EXPAND_OPD(opd) HBT_STRINGIFY(opd) << " (" << (opd) << ")"

#ifdef NDEBUG
#define HBT_DLOG_INFO() \
  while (false)         \
  HBT_LOG_INFO()
#else
// Add a debug mode specific log info. Warnings and errors should always be
// logged.
#define HBT_DLOG_INFO() HBT_LOG_INFO()
#endif

//
// Debug checks.
// Note that non-debug checks are not provided because hbt developers
// must handle all errors explicitly.
//

#define __HBT_DCHECK(a)       \
  if (__hbt_unlikely(!((a)))) \
  HBT_THROW_ASSERT() << "\n\tExpected true for " << __HBT_EXPAND_OPD(a) << ". "

#define __HBT_DCHECK_CMP(a, b, op)                                      \
  if (__hbt_unlikely(!((a)op(b))))                                      \
  HBT_THROW_ASSERT() << "\n\tExpected " << __HBT_EXPAND_OPD(a) << " "   \
                     << HBT_STRINGIFY(op) << " " << __HBT_EXPAND_OPD(b) \
                     << ". "

// Expand macro only in debug mode.
#ifdef NDEBUG

#define _HBT_DCHECK(a) \
  while (false)        \
  __HBT_DCHECK(a)

#define _HBT_DCHECK_CMP(a, b, op) \
  while (false)                   \
  __HBT_DCHECK_CMP(a, b, op)

#else

#define _HBT_DCHECK(a) __HBT_DCHECK(a)

#define _HBT_DCHECK_CMP(a, b, op) __HBT_DCHECK_CMP(a, b, op)

#endif

// Public API for debug checks.
#define HBT_DCHECK(a) _HBT_DCHECK(a)
#define HBT_DCHECK_EQ(a, b) _HBT_DCHECK_CMP(a, b, ==)
#define HBT_DCHECK_NE(a, b) _HBT_DCHECK_CMP(a, b, !=)
#define HBT_DCHECK_LT(a, b) _HBT_DCHECK_CMP(a, b, <)
#define HBT_DCHECK_LE(a, b) _HBT_DCHECK_CMP(a, b, <=)
#define HBT_DCHECK_GT(a, b) _HBT_DCHECK_CMP(a, b, >)
#define HBT_DCHECK_GE(a, b) _HBT_DCHECK_CMP(a, b, >=)

//
// Argument checks
//
#define HBT_ARG_CHECK(a)                                     \
  if (__hbt_unlikely(!((a))))                                \
  HBT_THROW_EINVAL() << "\n\tExpected argument to be true: " \
                     << __HBT_EXPAND_OPD(a) << ". "

#define _HBT_ARG_CMP(a, b, op)                                              \
  if (__hbt_unlikely(!((a)op(b))))                                          \
  HBT_THROW_EINVAL() << "\n\tExpected argument " << __HBT_EXPAND_OPD(a)     \
                     << " " HBT_STRINGIFY(op) << " " << __HBT_EXPAND_OPD(b) \
                     << ". "

#define HBT_ARG_CHECK_EQ(a, b) _HBT_ARG_CMP(a, b, ==)
#define HBT_ARG_CHECK_NE(a, b) _HBT_ARG_CMP(a, b, !=)
#define HBT_ARG_CHECK_LT(a, b) _HBT_ARG_CMP(a, b, <)
#define HBT_ARG_CHECK_LE(a, b) _HBT_ARG_CMP(a, b, <=)
#define HBT_ARG_CHECK_GT(a, b) _HBT_ARG_CMP(a, b, >)
#define HBT_ARG_CHECK_GE(a, b) _HBT_ARG_CMP(a, b, >=)
#define HBT_ARG_CHECK_TRUE(a) _HBT_ARG_CMP(a, true, ==)
#define HBT_ARG_CHECK_FALSE(a) _HBT_ARG_CMP(a, true, !=)

// Define DEXCEPT macro that is noexcept outside of debug mode.
#ifdef NDEBUG
#define DEXCEPT noexcept(true)
#else
#define DEXCEPT noexcept(false)
#endif

// Log the string representation rather than throwing it.
// To be used in contexts where is throwing exceptions is
// not safed.
#define HBT_LOG_EXCEPTION(e)                         \
  HBT_LOG_ERROR() << "Exception in " << __FUNCTION__ \
                  << " . Message: " << e.what() << " "
