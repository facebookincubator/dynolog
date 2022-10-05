#pragma once

#include <atomic>
#include <memory>
#include <thread>

// TriggerableTread is a wrapper around thread class and its main idea is to
// make constructed threads to wait for a certain event. In the beginning a
// bunch of TriggerableThread objects are constructed referencing to the
// same std::atomic<int>& mentioned as the latch and pre-initialized to zero.
// All the threads are waiting when latch value changed to non-zero and start
// execution of worker function.

namespace {

class TriggerableThread : public std::thread {
 public:
  using TLatchPtr = std::shared_ptr<std::atomic<int>>;

 public:
  template <class Fn, class... Args>
  TriggerableThread(TLatchPtr latch, Fn&& fn, Args&&... args)
      : std::thread([=]() {
          while (!latch->load()) {
          }
          fn(&args...);
        }) {}

  TriggerableThread(const TriggerableThread&) = delete;
  TriggerableThread(TriggerableThread&&) = default;
  TriggerableThread& operator=(TriggerableThread&&) = default;
  TriggerableThread& operator=(const TriggerableThread&) = delete;
};

} // end of namespace
