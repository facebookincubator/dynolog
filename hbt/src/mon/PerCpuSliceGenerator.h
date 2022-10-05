// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#pragma once
// Reordering of these includes can lead to broken builds, so we disable
// formatting.
/* clang-format off */
#include "hbt/src/common/System.h"
#include "hbt/src/perf_event/PerCpuThreadSwitchGenerator.h"
#include "hbt/src/phase/PerCpuPhaseLogger.h"
#include "hbt/src/tagstack/Slicer.h"
#include "hbt/src/tagstack/Stream.h"
#include "hbt/src/tagstack/PerfEventStream.h"
#include "hbt/src/tagstack/TscConverterStream.h"

#include <variant>
/* clang-format on */

namespace facebook::hbt::mon {

/// Recursive nesting of BinaryCombinator with <NLevels>.
/// Allowing to combine 2^NLevels instances of TStream in a tree-like
/// structure.
template <class TStream, int NLevels>
struct TNestedBinaryCombinator {
  using Type = tagstack::stream::BinaryCombinator<
      typename TNestedBinaryCombinator<TStream, NLevels - 1>::Type>;
};

/// Base case of recursive template for the case 2^0=1. This case
/// is a simple TStream, so no BinaryCombinator needed.
template <class TStream>
struct TNestedBinaryCombinator<TStream, 0> {
  using Type = TStream;
};

/// Generate per CPU slices by combining all tagstack Events in
/// the system as follows:
///   1. All CPU thread switch generator are combined together into
///     an auxiliar ring buffer.
///   2. tagstack events stored in <phases_per_cpu_rb>, coming from
///     PerCpuPhaseLoggers are combined together, providing a single
///     stream for events from all CPUs.
///   3. Combine events from (1) and (2) and feed them to the slicer.
///
/// To avoid stalling the pipeline due to intermitent producers (producers
/// that produce in bursts followed by long periods of no activity) or producer
/// not active in a monitored CPUs, the user can provide a
/// <pipeline_max_delay>. Any input to the pipeline (thread switches or
/// phase logger) that do not produce in a CPU for pipeline_max_delay or
/// longer is assumed to have nothing to produce.
///
/// That way slicer can simply run behind the latest event in the pipeline by
/// <pipeline_max_delay> time units and any input to the slicer that do
/// not produce and stalls can be safely ignored.
///
/// The value of <pipeline_max_delay> is a trade-off between buffer sizes,
/// pipeline responsiveness (the smaller, the smaller the delay between
/// event and estimation) and robustness (the longer, the less likely
/// the pipeline is disturbed). Probably a few seconds is a good choice.
///
/// <kNestingLevel> indicates the number of levels in the tree created
/// to combine events from multiple CPUs. 2^<kNestingLevel> is the maximum
/// number of CPUs that this class can support.
template <unsigned kNestingLevel, class TSlices>
class PerCpuSliceGeneratorConstNumCpus {
 public:
  // Types for streams that combine thread switch events from all CPUs.
  using TPerCpuThreadGenerator = perf_event::PerCpuThreadSwitchGenerator;
  using TCpuThreadGenerator = typename TPerCpuThreadGenerator::TCpuGenerator;
  using TThreadSwitchStream = tagstack::stream::
      PerfEventStream<TCpuThreadGenerator, TCpuThreadGenerator::RbExtraData>;

  using TThreadSwitchBinaryCombinator =
      typename TNestedBinaryCombinator<TThreadSwitchStream, kNestingLevel>::
          Type;

  // Types for streams that combine phase events from all CPUs.
  using TPhasesRingBuffer =
      typename phase::PerCpuPhaseLogger::TPerCpuRingBuffer;
  using TPhasesPerCpuRingBuffer =
      typename phase::PerCpuPhaseLogger::TPerCpuRingBuffer;
  using TPhasesExtraData = typename TPhasesRingBuffer::TExtraData;
  using TPhaseLoggerStream = tagstack::stream::
      TscConverterStream<TCpuThreadGenerator, TPhasesExtraData>;
  using TPhaseBinaryCombinator =
      typename TNestedBinaryCombinator<TPhaseLoggerStream, kNestingLevel>::Type;

  // Type to combine thread switch and phase switch.
  using TStreamCombinator = tagstack::stream::
      Combinator<TThreadSwitchBinaryCombinator, TPhaseBinaryCombinator>;

  using TSlicer = tagstack::slice::Slicer<TStreamCombinator, TSlices>;
  using TGroupedSlices = typename TSlicer::TGroupedSlices;

  PerCpuSliceGeneratorConstNumCpus(
      std::shared_ptr<TPhasesPerCpuRingBuffer> phases_per_cpu_rb,
      std::shared_ptr<TPerCpuThreadGenerator> per_cpu_thread_gen,
      std::unique_ptr<TGroupedSlices>&& grouped_slices)
      : per_cpu_thread_generator_{per_cpu_thread_gen},
        phases_per_cpu_rb_{phases_per_cpu_rb} {
    HBT_ARG_CHECK(phases_per_cpu_rb != nullptr);
    HBT_ARG_CHECK(per_cpu_thread_generator_ != nullptr);
    HBT_ARG_CHECK(grouped_slices != nullptr);
    HBT_ARG_CHECK_EQ(
        phases_per_cpu_rb_->getCpuSet(),
        per_cpu_thread_generator_->getMonCpus());
    HBT_ARG_CHECK_EQ(getMonCpus().max_cpu_id + 1, grouped_slices->size());

    //
    // Initialize streams:
    //   1. Per-cpu streams for thread switches are combined together.
    //   2. Per-cpu streams for phases are combined together.
    //   3. The two resulting streams are then combined and fed to Slicer.
    //

    auto thread_sw_streams =
        std::vector<std::unique_ptr<TThreadSwitchStream>>{};
    auto phase_streams = std::vector<std::unique_ptr<TPhaseLoggerStream>>{};

    for_each_cpu(cpu, getMonCpus()) {
      HBT_DCHECK_GE(cpu, 0);
      HBT_DCHECK_LT(cpu, kMaxCpus);

      auto thread_sw_gen = per_cpu_thread_generator_->getCpuGeneratorPtr(cpu);
      auto thread_sw_cpu_rb = thread_sw_gen->getOutput();
      thread_sw_streams.push_back(std::make_unique<TThreadSwitchStream>(
          thread_sw_cpu_rb, thread_sw_gen));

      auto phases_cpu_rb = phases_per_cpu_rb_->getCpuRingBuffer(cpu);
      phase_streams.push_back(
          std::make_unique<TPhaseLoggerStream>(phases_cpu_rb, thread_sw_gen));
    }

    auto thread_sw_multi_input = tagstack::stream::
        makeBinaryTree<TThreadSwitchBinaryCombinator, TThreadSwitchStream>(
            thread_sw_streams);

    auto phases_multi_input = tagstack::stream::
        makeBinaryTree<TPhaseBinaryCombinator, TPhaseLoggerStream>(
            phase_streams);

    // Connect the thread switch and phase streams.
    auto slicer_input = std::make_unique<TStreamCombinator>(
        thread_sw_multi_input, phases_multi_input);

    // Create the slicer.
    slicer_ = std::make_unique<TSlicer>(
        std::move(slicer_input), std::move(grouped_slices));
  }

  void open(size_t perf_event_per_cpu_num_pages) {
    per_cpu_thread_generator_->open(perf_event_per_cpu_num_pages);
  }

  void close() {
    per_cpu_thread_generator_->close();
  }

  bool isOpen() const {
    return per_cpu_thread_generator_->isOpen();
  }

  void enable() {
    return per_cpu_thread_generator_->enable();
  }

  void disable() {
    return per_cpu_thread_generator_->disable();
  }

  bool isEnabled() const {
    return per_cpu_thread_generator_->isEnabled();
  }

  /// Push events through pipeline into slicer.
  unsigned processNext(unsigned batch_size, TimeStamp stop_ts) {
    HBT_DCHECK(slicer_ != nullptr);

    unsigned num_processed, total_processed = 0;
    do {
      num_processed = slicer_->processNext(batch_size, stop_ts);
      // HBT_LOG_INFO() << "PerCpuSliceGenerator::processNext"
      //    << " num_processed: " << num_processed
      //    << " stop_ts: " << stop_ts
      //    << " last tstamp: " << slicer_->getLastTimeStamp();
      total_processed += num_processed;
    } while (num_processed == batch_size);
    return total_processed;
  }

  auto& getSlicer() {
    HBT_DCHECK(slicer_ != nullptr);
    return *slicer_;
  }

  const auto& getSlicer() const {
    HBT_DCHECK(slicer_ != nullptr);
    return *slicer_;
  }

  const CpuSet& getMonCpus() const noexcept {
    return phases_per_cpu_rb_->getCpuSet();
  }

  TPerCpuThreadGenerator& getPerCpuThreadGenerator() noexcept {
    return *per_cpu_thread_generator_;
  }

  TimeStamp getLastTimeStamp() const noexcept {
    return slicer_->getLastTimeStamp();
  }

  TimeStamp tstampFromTsc(TimeStamp tsc) const noexcept {
    return per_cpu_thread_generator_->tstampFromTsc(tsc);
  }

  TimeStamp now() const noexcept {
    return per_cpu_thread_generator_->now();
  }

  std::ostream& printStatus(std::ostream& os, const cpu_set_t& cpus) const {
    if (CPU_COUNT(&cpus) == 0) {
      return os << "Thread Switch Generator active.\n";
    }

    os << "Thread Switch Generator:\n";
    for_each_cpu_set_t(cpu, cpus) {
      const auto& gen = per_cpu_thread_generator_->getCpuGenerator(cpu);
      os << "\tCPU: " << cpu;

      {
        auto used = gen.usedSizeWeak();
        os << " perf_event rb used size:" << used << "/" << gen.bufferSize()
           << " bytes (" << (used * 100) / gen.bufferSize() << "%)";
      }
      {
        const auto& header = gen.getOutputRef()->getHeader();
        auto used = header.usedSizeWeak();
        os << "\n\t\taux rb used size:" << used << "/"
           << header.kDataPoolByteSize << " bytes ("
           << (used * 100) / header.kDataPoolByteSize << "%)\n";
      }

      os << "\t\tNumber Record (Fork, Comm, Exit): "
         << "(" << gen.getNumRecordFork() << ", " << gen.getNumRecordComm()
         << ", " << gen.getNumRecordExit() << ")\n";

      os << "\t\tNumber Record (Lost, Throttle, Unthrottle): "
         << "(" << gen.getNumRecordLost() << ", " << gen.getNumRecordThrottle()
         << ", " << gen.getNumRecordUnThrottle() << ")\n";

      os << "\t\tNumber Record (Sample, SwitchCpuWide): "
         << "(" << gen.getNumRecordSample() << ", "
         << gen.getNumRecordSwitchCpuWide() << ")\n";
    }

    os << "\nPhase:\n";
    for_each_cpu_set_t(cpu, cpus) {
      const auto& header =
          phases_per_cpu_rb_->getCpuRingBuffer(cpu)->getHeader();
      auto combinator = slicer_->getInputStream();
      os << "\tCPU: " << cpu;
      auto used = header.usedSizeWeak();
      os << " rb used size:" << used << "/" << header.kDataPoolByteSize
         << " bytes (" << (used * 100) / header.kDataPoolByteSize << "%)\n";
    }
    return os;
  }

 protected:
  std::shared_ptr<TPerCpuThreadGenerator> per_cpu_thread_generator_;
  std::shared_ptr<TPhasesPerCpuRingBuffer> phases_per_cpu_rb_;

  std::unique_ptr<TSlicer> slicer_;
};

template <class TSlices>
class PerCpuSliceGenerator {
  template <unsigned kNumLevels>
  using T = PerCpuSliceGeneratorConstNumCpus<kNumLevels, TSlices>;

  using TVariantPerCpuSliceGenerator = std::variant<
      std::unique_ptr<T<2>>, // 2^4 = 4 CPUs
      std::unique_ptr<T<3>>, // 2^3 = 8 CPUs
      std::unique_ptr<T<4>>, // 2^4 = 16 CPUs
      std::unique_ptr<T<5>>, // 2^5 = 32 CPUs
      std::unique_ptr<T<6>>, // 2^6 = 64 CPUs
      std::unique_ptr<T<7>>, // 2^7 = 128 CPUs
      std::unique_ptr<T<8>>, // 2^8 = 256 CPUs
      std::unique_ptr<T<9>>, // 2^9 = 512 CPUs
      std::unique_ptr<T<10>> // 2^10 = 1024 CPUs
      >;

 public:
  /// Most aliases in the template specialization refer to the same types,
  /// define one type as canonical to make it convenient to refer to
  /// common types.
  // XXX: Statically assert that all specialization point to the same types and
  // use the same constants.
  using CanonicalT = T<3>;

  using TPhasesPerCpuRingBuffer = typename CanonicalT::TPhasesPerCpuRingBuffer;
  using TGroupedSlices = typename CanonicalT::TGroupedSlices;
  // This class has a constant write size.
  static constexpr size_t kWriteByteSize = CanonicalT::TSlicer::kWriteByteSize;

  template <class... Args>
  PerCpuSliceGenerator(
      std::shared_ptr<TPhasesPerCpuRingBuffer> phases_per_cpu_rb,
      Args&&... args) {
    const auto& cpu_set = phases_per_cpu_rb->getCpuSet();
    HBT_ARG_CHECK_GT(cpu_set.numCpus(), 0);
    auto num_levels = log2NextPow2(cpu_set.numCpus());
    switch (num_levels) {
      case 0:
      case 1:
      case 2:
        variant_per_cpu_slice_gen_ = std::make_unique<T<2>>(
            phases_per_cpu_rb, std::forward<Args>(args)...);
        break;
      case 3:
        variant_per_cpu_slice_gen_ = std::make_unique<T<3>>(
            phases_per_cpu_rb, std::forward<Args>(args)...);
        break;
      case 4:
        variant_per_cpu_slice_gen_ = std::make_unique<T<4>>(
            phases_per_cpu_rb, std::forward<Args>(args)...);
        break;
      case 5:
        variant_per_cpu_slice_gen_ = std::make_unique<T<5>>(
            phases_per_cpu_rb, std::forward<Args>(args)...);
        break;
      case 6:
        variant_per_cpu_slice_gen_ = std::make_unique<T<6>>(
            phases_per_cpu_rb, std::forward<Args>(args)...);
        break;
      case 7:
        variant_per_cpu_slice_gen_ = std::make_unique<T<7>>(
            phases_per_cpu_rb, std::forward<Args>(args)...);
        break;
      case 8:
        variant_per_cpu_slice_gen_ = std::make_unique<T<8>>(
            phases_per_cpu_rb, std::forward<Args>(args)...);
        break;
      case 9:
        variant_per_cpu_slice_gen_ = std::make_unique<T<9>>(
            phases_per_cpu_rb, std::forward<Args>(args)...);
        break;
      case 10:
        variant_per_cpu_slice_gen_ = std::make_unique<T<10>>(
            phases_per_cpu_rb, std::forward<Args>(args)...);
        break;
      default:
        HBT_THROW_EINVAL()
            << "Actual number of CPUs (" << cpu_set.numCpus() << ") requires "
            << num_levels << " levels, but the largest "
            << "specialization of PerCpuSliceGeneratorConstNumCpus<> "
            << "has 10 levels (1024 CPUs). Add an adittional specilization.";
    }
  }

  void open(size_t perf_event_per_cpu_num_pages) {
    std::visit(
        [=](auto&& gen) { gen->open(perf_event_per_cpu_num_pages); },
        variant_per_cpu_slice_gen_);
  }

  void close() {
    std::visit([](auto&& gen) { gen->close(); }, variant_per_cpu_slice_gen_);
  }

  bool isOpen() const {
    return std::visit(
        [](auto&& gen) { return gen->isOpen(); }, variant_per_cpu_slice_gen_);
  }

  void enable() {
    std::visit([](auto&& gen) { gen->enable(); }, variant_per_cpu_slice_gen_);
  }

  void disable() {
    std::visit([](auto&& gen) { gen->disable(); }, variant_per_cpu_slice_gen_);
  }

  bool isEnabled() const {
    return std::visit(
        [](auto&& gen) { return gen->isEnabled(); },
        variant_per_cpu_slice_gen_);
  }

  /// Push events through pipeline into slicer.
  unsigned processNext(unsigned batch_size, TimeStamp stop_ts) {
    return std::visit(
        [=](auto&& gen) { return gen->processNext(batch_size, stop_ts); },
        variant_per_cpu_slice_gen_);
  }

  auto getSlices() {
    return std::visit(
        [](const auto& gen) { return gen->getSlicer().getSlices(); },
        variant_per_cpu_slice_gen_);
  }

  auto getStats() {
    return std::visit(
        [](const auto& gen) { return gen->getSlicer().getStats(); },
        variant_per_cpu_slice_gen_);
  }

  auto getTagStackStatsDump() {
    return std::visit(
        [](const auto& gen) { return gen->getSlicer().getTagStackStatsDump(); },
        variant_per_cpu_slice_gen_);
  }

  const CpuSet& getMonCpus() const noexcept {
    return std::visit(
        [](const auto& gen) -> CpuSet const& { return gen->getMonCpus(); },
        variant_per_cpu_slice_gen_);
  }

  auto& getPerCpuThreadGenerator() noexcept {
    return std::visit(
        [](auto&& gen) -> auto& { return gen->getPerCpuThreadGenerator(); },
        variant_per_cpu_slice_gen_);
  }

  TimeStamp getLastTimeStamp() const noexcept {
    return std::visit(
        [](const auto& gen) { return gen->getLastTimeStamp(); },
        variant_per_cpu_slice_gen_);
  }

  TimeStamp tstampFromTsc(TimeStamp tsc) const noexcept {
    return std::visit(
        [=](const auto& gen) { return gen->tstampFromTsc(tsc); },
        variant_per_cpu_slice_gen_);
  }

  TimeStamp now() const noexcept {
    return std::visit(
        [](const auto& gen) { return gen->now(); }, variant_per_cpu_slice_gen_);
  }

  auto buildTimeStampNsConverter() const {
    return std::visit(
        [](const auto& gen) { return gen->buildTimeStampNsConverter(); },
        variant_per_cpu_slice_gen_);
  }

  std::ostream& printStatus(std::ostream& os, const cpu_set_t& cpus) const {
    std::visit(
        [&](const auto& gen) { gen->printStatus(os, cpus); },
        variant_per_cpu_slice_gen_);
    return os;
  }

 protected:
  TVariantPerCpuSliceGenerator variant_per_cpu_slice_gen_;
};

} // namespace facebook::hbt::mon
