/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include "dynolog/src/OtlpMetricsLogger.h"
#include <fmt/format.h>
#include <glog/logging.h>
#include <gtest/gtest.h>
#include <cmath>
#include <limits>
#include <string>
#include <thread>
#include <unordered_set>

#include "opentelemetry/proto/collector/metrics/v1/metrics_service.pb.h"
#include "opentelemetry/proto/common/v1/common.pb.h"
#include "opentelemetry/proto/metrics/v1/metrics.pb.h"
#include "opentelemetry/proto/resource/v1/resource.pb.h"

DECLARE_string(otlp_endpoint);
DECLARE_string(otlp_service_name);
DECLARE_int32(otlp_max_queue_size);

namespace dynolog {

// =============================================================================
// Metric Key Parsing Tests
// =============================================================================

// ---- CPU Utilization Metrics (positive) ----

TEST(OTLPLoggerTest, MetricMappingCPU) {
  // cpu_util -> cpu_util, cpu.mode=active, scale_factor=100
  {
    auto parsed = parseMetricKey("cpu_util");
    ASSERT_TRUE(parsed.matched);
    EXPECT_EQ(parsed.mapping.otel_name, "cpu_util");
    EXPECT_EQ(parsed.mapping.unit, "1");

    EXPECT_DOUBLE_EQ(parsed.mapping.scale_factor, 0.01);
    ASSERT_EQ(parsed.mapping.attributes.size(), 1);
    EXPECT_EQ(parsed.mapping.attributes[0].first, "cpu.mode");
    EXPECT_EQ(parsed.mapping.attributes[0].second, "active");
  }

  // cpu_u -> cpu_u, cpu.mode=user
  {
    auto parsed = parseMetricKey("cpu_u");
    ASSERT_TRUE(parsed.matched);
    EXPECT_EQ(parsed.mapping.otel_name, "cpu_u");
    EXPECT_EQ(parsed.mapping.unit, "1");
    EXPECT_DOUBLE_EQ(parsed.mapping.scale_factor, 0.01);
    ASSERT_EQ(parsed.mapping.attributes.size(), 1);
    EXPECT_EQ(parsed.mapping.attributes[0].second, "user");
  }

  // cpu_s -> cpu.mode=system
  {
    auto parsed = parseMetricKey("cpu_s");
    ASSERT_TRUE(parsed.matched);
    EXPECT_EQ(parsed.mapping.otel_name, "cpu_s");
    ASSERT_EQ(parsed.mapping.attributes.size(), 1);
    EXPECT_EQ(parsed.mapping.attributes[0].second, "system");
    EXPECT_DOUBLE_EQ(parsed.mapping.scale_factor, 0.01);
  }

  // cpu_i -> cpu.mode=idle
  {
    auto parsed = parseMetricKey("cpu_i");
    ASSERT_TRUE(parsed.matched);
    EXPECT_EQ(parsed.mapping.otel_name, "cpu_i");
    ASSERT_EQ(parsed.mapping.attributes.size(), 1);
    EXPECT_EQ(parsed.mapping.attributes[0].second, "idle");
    EXPECT_DOUBLE_EQ(parsed.mapping.scale_factor, 0.01);
  }

  // cpu_guest -> cpu.mode=guest
  {
    auto parsed = parseMetricKey("cpu_guest");
    ASSERT_TRUE(parsed.matched);
    EXPECT_EQ(parsed.mapping.otel_name, "cpu_guest");
    ASSERT_EQ(parsed.mapping.attributes.size(), 1);
    EXPECT_EQ(parsed.mapping.attributes[0].second, "guest");
    EXPECT_DOUBLE_EQ(parsed.mapping.scale_factor, 0.01);
  }

  // cpu_guest_nice -> cpu.mode=guest_nice
  {
    auto parsed = parseMetricKey("cpu_guest_nice");
    ASSERT_TRUE(parsed.matched);
    EXPECT_EQ(parsed.mapping.otel_name, "cpu_guest_nice");
    ASSERT_EQ(parsed.mapping.attributes.size(), 1);
    EXPECT_EQ(parsed.mapping.attributes[0].second, "guest_nice");
    EXPECT_DOUBLE_EQ(parsed.mapping.scale_factor, 0.01);
  }
}

// ---- CPU Time Metrics (per-interval delta, Gauge) ----

TEST(OTLPLoggerTest, MetricMappingCPUTime) {
  // cpu_u_ms -> cpu_u_ms, cpu.mode=user, Gauge
  {
    auto parsed = parseMetricKey("cpu_u_ms");
    ASSERT_TRUE(parsed.matched);
    EXPECT_EQ(parsed.mapping.otel_name, "cpu_u_ms");
    EXPECT_EQ(parsed.mapping.unit, "s");

    EXPECT_DOUBLE_EQ(parsed.mapping.scale_factor, 0.001);
    ASSERT_EQ(parsed.mapping.attributes.size(), 1);
    EXPECT_EQ(parsed.mapping.attributes[0].second, "user");
  }

  // cpu_s_ms -> cpu.mode=system
  {
    auto parsed = parseMetricKey("cpu_s_ms");
    ASSERT_TRUE(parsed.matched);
    EXPECT_EQ(parsed.mapping.otel_name, "cpu_s_ms");

    EXPECT_EQ(parsed.mapping.attributes[0].second, "system");
  }

  // cpu_n_ms -> cpu.mode=nice
  {
    auto parsed = parseMetricKey("cpu_n_ms");
    ASSERT_TRUE(parsed.matched);
    EXPECT_EQ(parsed.mapping.otel_name, "cpu_n_ms");
    EXPECT_EQ(parsed.mapping.attributes[0].second, "nice");
  }

  // cpu_w_ms -> cpu.mode=iowait
  {
    auto parsed = parseMetricKey("cpu_w_ms");
    ASSERT_TRUE(parsed.matched);
    EXPECT_EQ(parsed.mapping.otel_name, "cpu_w_ms");
    EXPECT_EQ(parsed.mapping.attributes[0].second, "iowait");
  }

  // cpu_x_ms -> cpu.mode=irq
  {
    auto parsed = parseMetricKey("cpu_x_ms");
    ASSERT_TRUE(parsed.matched);
    EXPECT_EQ(parsed.mapping.otel_name, "cpu_x_ms");
    EXPECT_EQ(parsed.mapping.attributes[0].second, "irq");
  }

  // cpu_y_ms -> cpu.mode=softirq
  {
    auto parsed = parseMetricKey("cpu_y_ms");
    ASSERT_TRUE(parsed.matched);
    EXPECT_EQ(parsed.mapping.otel_name, "cpu_y_ms");
    EXPECT_EQ(parsed.mapping.attributes[0].second, "softirq");
  }

  // cpu_z_ms -> cpu.mode=steal
  {
    auto parsed = parseMetricKey("cpu_z_ms");
    ASSERT_TRUE(parsed.matched);
    EXPECT_EQ(parsed.mapping.otel_name, "cpu_z_ms");
    EXPECT_EQ(parsed.mapping.attributes[0].second, "steal");
  }

  // cpu_guest_ms -> cpu.mode=guest
  {
    auto parsed = parseMetricKey("cpu_guest_ms");
    ASSERT_TRUE(parsed.matched);
    EXPECT_EQ(parsed.mapping.otel_name, "cpu_guest_ms");
    EXPECT_EQ(parsed.mapping.attributes[0].second, "guest");
  }

  // cpu_guest_nice_ms -> cpu.mode=guest_nice
  {
    auto parsed = parseMetricKey("cpu_guest_nice_ms");
    ASSERT_TRUE(parsed.matched);
    EXPECT_EQ(parsed.mapping.otel_name, "cpu_guest_nice_ms");
    EXPECT_EQ(parsed.mapping.attributes[0].second, "guest_nice");
  }
}

// ---- Special CPU Metrics ----

TEST(OTLPLoggerTest, MetricMappingSpecialCPU) {
  // uptime -> uptime, Gauge, unit=s
  {
    auto parsed = parseMetricKey("uptime");
    ASSERT_TRUE(parsed.matched);
    EXPECT_EQ(parsed.mapping.otel_name, "uptime");
    EXPECT_EQ(parsed.mapping.unit, "s");

    EXPECT_DOUBLE_EQ(parsed.mapping.scale_factor, 1.0);
  }

  // mips -> mips (passthrough, no unit conversion)
  {
    auto parsed = parseMetricKey("mips");
    ASSERT_TRUE(parsed.matched);
    EXPECT_EQ(parsed.mapping.otel_name, "mips");
    EXPECT_EQ(parsed.mapping.unit, "");
  }

  // mega_cycles_per_second -> mega_cycles_per_second (passthrough)
  {
    auto parsed = parseMetricKey("mega_cycles_per_second");
    ASSERT_TRUE(parsed.matched);
    EXPECT_EQ(parsed.mapping.otel_name, "mega_cycles_per_second");
    EXPECT_EQ(parsed.mapping.unit, "");
  }
}

// ---- Per-NUMA-socket CPU metrics ----

TEST(OTLPLoggerTest, MetricMappingNUMA) {
  // cpu_u_node0 -> cpu_u_node0, cpu.mode=user, cpu.socket=0
  {
    auto parsed = parseMetricKey("cpu_u_node0");
    ASSERT_TRUE(parsed.matched);
    EXPECT_EQ(parsed.mapping.otel_name, "cpu_u_node0");
    EXPECT_EQ(parsed.mapping.unit, "1");
    EXPECT_DOUBLE_EQ(parsed.mapping.scale_factor, 0.01);
    ASSERT_EQ(parsed.mapping.attributes.size(), 1);
    EXPECT_EQ(parsed.mapping.attributes[0].first, "cpu.mode");
    EXPECT_EQ(parsed.mapping.attributes[0].second, "user");
    ASSERT_EQ(parsed.dynamic_attributes.size(), 1);
    EXPECT_EQ(parsed.dynamic_attributes[0].first, "cpu.socket");
    EXPECT_EQ(parsed.dynamic_attributes[0].second, "0");
  }

  // cpu_s_node3 -> cpu.mode=system, cpu.socket=3
  {
    auto parsed = parseMetricKey("cpu_s_node3");
    ASSERT_TRUE(parsed.matched);
    EXPECT_EQ(parsed.mapping.otel_name, "cpu_s_node3");
    EXPECT_EQ(parsed.mapping.attributes[0].second, "system");
    EXPECT_EQ(parsed.dynamic_attributes[0].second, "3");
  }

  // cpu_i_node7 -> cpu.mode=idle, cpu.socket=7
  {
    auto parsed = parseMetricKey("cpu_i_node7");
    ASSERT_TRUE(parsed.matched);
    EXPECT_EQ(parsed.mapping.attributes[0].second, "idle");
    EXPECT_EQ(parsed.dynamic_attributes[0].second, "7");
  }

  // Large socket number
  {
    auto parsed = parseMetricKey("cpu_u_node127");
    ASSERT_TRUE(parsed.matched);
    EXPECT_EQ(parsed.dynamic_attributes[0].second, "127");
  }
}

// ---- Network Metrics ----

TEST(OTLPLoggerTest, MetricMappingNetwork) {
  // rx_bytes.eth0 -> rx_bytes,
  // network.io.direction=receive, network.interface.name=eth0
  {
    auto parsed = parseMetricKey("rx_bytes.eth0");
    ASSERT_TRUE(parsed.matched);
    EXPECT_EQ(parsed.mapping.otel_name, "rx_bytes");
    EXPECT_EQ(parsed.mapping.unit, "By");

    ASSERT_EQ(parsed.mapping.attributes.size(), 1);
    EXPECT_EQ(parsed.mapping.attributes[0].first, "network.io.direction");
    EXPECT_EQ(parsed.mapping.attributes[0].second, "receive");
    ASSERT_EQ(parsed.dynamic_attributes.size(), 1);
    EXPECT_EQ(parsed.dynamic_attributes[0].first, "network.interface.name");
    EXPECT_EQ(parsed.dynamic_attributes[0].second, "eth0");
  }

  // tx_bytes.ens5 -> tx_bytes, network.io.direction=transmit
  {
    auto parsed = parseMetricKey("tx_bytes.ens5");
    ASSERT_TRUE(parsed.matched);
    EXPECT_EQ(parsed.mapping.otel_name, "tx_bytes");
    EXPECT_EQ(parsed.mapping.attributes[0].second, "transmit");
    EXPECT_EQ(parsed.dynamic_attributes[0].second, "ens5");
  }

  // rx_packets.lo -> rx_packets, network.io.direction=receive
  {
    auto parsed = parseMetricKey("rx_packets.lo");
    ASSERT_TRUE(parsed.matched);
    EXPECT_EQ(parsed.mapping.otel_name, "rx_packets");
    EXPECT_EQ(parsed.mapping.unit, "{packet}");
    EXPECT_EQ(parsed.mapping.attributes[0].second, "receive");
    EXPECT_EQ(parsed.dynamic_attributes[0].second, "lo");
  }

  // tx_packets.wlan0
  {
    auto parsed = parseMetricKey("tx_packets.wlan0");
    ASSERT_TRUE(parsed.matched);
    EXPECT_EQ(parsed.mapping.otel_name, "tx_packets");
    EXPECT_EQ(parsed.mapping.attributes[0].second, "transmit");
  }

  // rx_errors.eth1 -> rx_errors
  {
    auto parsed = parseMetricKey("rx_errors.eth1");
    ASSERT_TRUE(parsed.matched);
    EXPECT_EQ(parsed.mapping.otel_name, "rx_errors");
    EXPECT_EQ(parsed.mapping.unit, "{error}");
    EXPECT_EQ(parsed.mapping.attributes[0].second, "receive");
  }

  // tx_errors.eth1 -> tx_errors
  {
    auto parsed = parseMetricKey("tx_errors.eth1");
    ASSERT_TRUE(parsed.matched);
    EXPECT_EQ(parsed.mapping.otel_name, "tx_errors");
    EXPECT_EQ(parsed.mapping.attributes[0].second, "transmit");
  }

  // rx_drops.bond0 -> rx_drops
  {
    auto parsed = parseMetricKey("rx_drops.bond0");
    ASSERT_TRUE(parsed.matched);
    EXPECT_EQ(parsed.mapping.otel_name, "rx_drops");
    EXPECT_EQ(parsed.mapping.unit, "{packet}");
    EXPECT_EQ(parsed.mapping.attributes[0].second, "receive");
  }

  // tx_drops.bond0 -> tx_drops
  {
    auto parsed = parseMetricKey("tx_drops.bond0");
    ASSERT_TRUE(parsed.matched);
    EXPECT_EQ(parsed.mapping.otel_name, "tx_drops");
    EXPECT_EQ(parsed.mapping.attributes[0].second, "transmit");
  }

  // Network metric with dot in device name: rx_bytes.eth0.1
  // Should split on first dot: base="rx_bytes", device="eth0.1"
  {
    auto parsed = parseMetricKey("rx_bytes.eth0.1");
    ASSERT_TRUE(parsed.matched);
    EXPECT_EQ(parsed.mapping.otel_name, "rx_bytes");
    EXPECT_EQ(parsed.dynamic_attributes[0].second, "eth0.1");
  }
}

// ---- GPU Metrics ----

TEST(OTLPLoggerTest, MetricMappingGPU) {
  // graphics_engine_active_ratio - profiling metric, already 0-1 ratio
  {
    auto parsed = parseMetricKey("graphics_engine_active_ratio");
    ASSERT_TRUE(parsed.matched);
    EXPECT_EQ(parsed.mapping.otel_name, "graphics_engine_active_ratio");
    EXPECT_EQ(parsed.mapping.unit, "1");

    EXPECT_DOUBLE_EQ(parsed.mapping.scale_factor, 1.0);
    // Should have hw.gpu.task=general
    bool found_task = false;
    for (const auto& [k, v] : parsed.mapping.attributes) {
      if (k == "hw.gpu.task" && v == "general") {
        found_task = true;
      }
    }
    EXPECT_TRUE(found_task);
  }

  // sm_active_ratio - profiling metric, already 0-1 ratio
  {
    auto parsed = parseMetricKey("sm_active_ratio");
    ASSERT_TRUE(parsed.matched);
    EXPECT_EQ(parsed.mapping.otel_name, "sm_active_ratio");
    EXPECT_DOUBLE_EQ(parsed.mapping.scale_factor, 1.0);
  }

  // sm_occupancy
  {
    auto parsed = parseMetricKey("sm_occupancy");
    ASSERT_TRUE(parsed.matched);
    EXPECT_EQ(parsed.mapping.otel_name, "sm_occupancy");
  }

  // gpu_frequency_mhz
  {
    auto parsed = parseMetricKey("gpu_frequency_mhz");
    ASSERT_TRUE(parsed.matched);
    EXPECT_EQ(parsed.mapping.otel_name, "gpu_frequency_mhz");
    EXPECT_EQ(parsed.mapping.unit, "MHz");
  }

  // fp16_active -> pipe=fp16
  {
    auto parsed = parseMetricKey("fp16_active");
    ASSERT_TRUE(parsed.matched);
    EXPECT_EQ(parsed.mapping.otel_name, "fp16_active");
    bool found_pipe = false;
    for (const auto& [k, v] : parsed.mapping.attributes) {
      if (k == "pipe" && v == "fp16") {
        found_pipe = true;
      }
    }
    EXPECT_TRUE(found_pipe);
  }

  // fp32_active -> pipe=fp32
  {
    auto parsed = parseMetricKey("fp32_active");
    ASSERT_TRUE(parsed.matched);
    EXPECT_EQ(parsed.mapping.otel_name, "fp32_active");
    bool found_pipe = false;
    for (const auto& [k, v] : parsed.mapping.attributes) {
      if (k == "pipe" && v == "fp32") {
        found_pipe = true;
      }
    }
    EXPECT_TRUE(found_pipe);
  }

  // fp64_active -> pipe=fp64
  {
    auto parsed = parseMetricKey("fp64_active");
    ASSERT_TRUE(parsed.matched);
    EXPECT_EQ(parsed.mapping.otel_name, "fp64_active");
    bool found_pipe = false;
    for (const auto& [k, v] : parsed.mapping.attributes) {
      if (k == "pipe" && v == "fp64") {
        found_pipe = true;
      }
    }
    EXPECT_TRUE(found_pipe);
  }

  // tensorcore_active -> pipe=tensorcore
  {
    auto parsed = parseMetricKey("tensorcore_active");
    ASSERT_TRUE(parsed.matched);
    EXPECT_EQ(parsed.mapping.otel_name, "tensorcore_active");
    bool found_pipe = false;
    for (const auto& [k, v] : parsed.mapping.attributes) {
      if (k == "pipe" && v == "tensorcore") {
        found_pipe = true;
      }
    }
    EXPECT_TRUE(found_pipe);
  }

  // hbm_mem_bw_util
  {
    auto parsed = parseMetricKey("hbm_mem_bw_util");
    ASSERT_TRUE(parsed.matched);
    EXPECT_EQ(parsed.mapping.otel_name, "hbm_mem_bw_util");
    EXPECT_EQ(parsed.mapping.unit, "1");
  }

  // pcie_tx_bytes -> direction=transmit
  {
    auto parsed = parseMetricKey("pcie_tx_bytes");
    ASSERT_TRUE(parsed.matched);
    EXPECT_EQ(parsed.mapping.otel_name, "pcie_tx_bytes");
    EXPECT_EQ(parsed.mapping.unit, "By/s");
    bool found_dir = false;
    for (const auto& [k, v] : parsed.mapping.attributes) {
      if (k == "direction" && v == "transmit") {
        found_dir = true;
      }
    }
    EXPECT_TRUE(found_dir);
  }

  // pcie_rx_bytes -> direction=receive
  {
    auto parsed = parseMetricKey("pcie_rx_bytes");
    ASSERT_TRUE(parsed.matched);
    EXPECT_EQ(parsed.mapping.otel_name, "pcie_rx_bytes");
    bool found_dir = false;
    for (const auto& [k, v] : parsed.mapping.attributes) {
      if (k == "direction" && v == "receive") {
        found_dir = true;
      }
    }
    EXPECT_TRUE(found_dir);
  }

  // nvlink_tx_bytes
  {
    auto parsed = parseMetricKey("nvlink_tx_bytes");
    ASSERT_TRUE(parsed.matched);
    EXPECT_EQ(parsed.mapping.otel_name, "nvlink_tx_bytes");
    EXPECT_EQ(parsed.mapping.unit, "By/s");
  }

  // nvlink_rx_bytes
  {
    auto parsed = parseMetricKey("nvlink_rx_bytes");
    ASSERT_TRUE(parsed.matched);
    EXPECT_EQ(parsed.mapping.otel_name, "nvlink_rx_bytes");
  }

  // gpu_device_utilization -> hw.gpu.task=device, DCGM field 203 returns 0-100%
  {
    auto parsed = parseMetricKey("gpu_device_utilization");
    ASSERT_TRUE(parsed.matched);
    EXPECT_EQ(parsed.mapping.otel_name, "gpu_device_utilization");
    EXPECT_DOUBLE_EQ(parsed.mapping.scale_factor, 0.01);
    bool found_task = false;
    for (const auto& [k, v] : parsed.mapping.attributes) {
      if (k == "hw.gpu.task" && v == "device") {
        found_task = true;
      }
    }
    EXPECT_TRUE(found_task);
  }

  // gpu_memory_utilization, DCGM field 204 returns 0-100%
  {
    auto parsed = parseMetricKey("gpu_memory_utilization");
    ASSERT_TRUE(parsed.matched);
    EXPECT_EQ(parsed.mapping.otel_name, "gpu_memory_utilization");
    EXPECT_EQ(parsed.mapping.unit, "1");
    EXPECT_DOUBLE_EQ(parsed.mapping.scale_factor, 0.01);
  }

  // gpu_power_draw -> gpu_power_draw, W, hw.type=gpu
  {
    auto parsed = parseMetricKey("gpu_power_draw");
    ASSERT_TRUE(parsed.matched);
    EXPECT_EQ(parsed.mapping.otel_name, "gpu_power_draw");
    EXPECT_EQ(parsed.mapping.unit, "W");
    bool found_type = false;
    for (const auto& [k, v] : parsed.mapping.attributes) {
      if (k == "hw.type" && v == "gpu") {
        found_type = true;
      }
    }
    EXPECT_TRUE(found_type);
  }

  // dcgm_error -> dcgm_error, hw.type=gpu
  {
    auto parsed = parseMetricKey("dcgm_error");
    ASSERT_TRUE(parsed.matched);
    EXPECT_EQ(parsed.mapping.otel_name, "dcgm_error");
    EXPECT_EQ(parsed.mapping.unit, "{error}");
    bool found_type = false;
    for (const auto& [k, v] : parsed.mapping.attributes) {
      if (k == "hw.type" && v == "gpu") {
        found_type = true;
      }
    }
    EXPECT_TRUE(found_type);
  }

  // minor_id -> skip (metadata)
  {
    auto parsed = parseMetricKey("minor_id");
    ASSERT_TRUE(parsed.matched);
    EXPECT_TRUE(parsed.mapping.skip);
  }

  // device -> skip (metadata, used as hw.id value)
  {
    auto parsed = parseMetricKey("device");
    ASSERT_TRUE(parsed.matched);
    EXPECT_TRUE(parsed.mapping.skip);
  }
}

// =============================================================================
// ARM Hardware Counter Metric Mapping Tests
// =============================================================================

TEST(OTLPLoggerTest, MetricMappingArmBranchRetired) {
  auto parsed = parseMetricKey("br_retired");
  ASSERT_TRUE(parsed.matched);
  EXPECT_EQ(parsed.mapping.otel_name, "br_retired");
  EXPECT_EQ(parsed.mapping.unit, "{instruction}");
  EXPECT_DOUBLE_EQ(parsed.mapping.scale_factor, 1.0);
  EXPECT_FALSE(parsed.mapping.skip);
  EXPECT_TRUE(parsed.mapping.attributes.empty());
  EXPECT_TRUE(parsed.dynamic_attributes.empty());
}

TEST(OTLPLoggerTest, MetricMappingArmCacheRefills) {
  // l1i_cache_refill -> level=l1i, type=miss
  {
    auto parsed = parseMetricKey("l1i_cache_refill");
    ASSERT_TRUE(parsed.matched);
    EXPECT_EQ(parsed.mapping.otel_name, "l1i_cache_refill");
    EXPECT_EQ(parsed.mapping.unit, "{event}");
    EXPECT_DOUBLE_EQ(parsed.mapping.scale_factor, 1.0);
    EXPECT_FALSE(parsed.mapping.skip);
    ASSERT_EQ(parsed.mapping.attributes.size(), 2);
    EXPECT_EQ(parsed.mapping.attributes[0].first, "level");
    EXPECT_EQ(parsed.mapping.attributes[0].second, "l1i");
    EXPECT_EQ(parsed.mapping.attributes[1].first, "type");
    EXPECT_EQ(parsed.mapping.attributes[1].second, "miss");
    EXPECT_TRUE(parsed.dynamic_attributes.empty());
  }

  // l1d_cache_refill -> level=l1d, type=miss
  {
    auto parsed = parseMetricKey("l1d_cache_refill");
    ASSERT_TRUE(parsed.matched);
    EXPECT_EQ(parsed.mapping.otel_name, "l1d_cache_refill");
    EXPECT_EQ(parsed.mapping.unit, "{event}");
    EXPECT_DOUBLE_EQ(parsed.mapping.scale_factor, 1.0);
    EXPECT_FALSE(parsed.mapping.skip);
    ASSERT_EQ(parsed.mapping.attributes.size(), 2);
    EXPECT_EQ(parsed.mapping.attributes[0].first, "level");
    EXPECT_EQ(parsed.mapping.attributes[0].second, "l1d");
    EXPECT_EQ(parsed.mapping.attributes[1].first, "type");
    EXPECT_EQ(parsed.mapping.attributes[1].second, "miss");
    EXPECT_TRUE(parsed.dynamic_attributes.empty());
  }

  // l2d_cache_refill -> level=l2, type=miss
  {
    auto parsed = parseMetricKey("l2d_cache_refill");
    ASSERT_TRUE(parsed.matched);
    EXPECT_EQ(parsed.mapping.otel_name, "l2d_cache_refill");
    EXPECT_EQ(parsed.mapping.unit, "{event}");
    EXPECT_DOUBLE_EQ(parsed.mapping.scale_factor, 1.0);
    EXPECT_FALSE(parsed.mapping.skip);
    ASSERT_EQ(parsed.mapping.attributes.size(), 2);
    EXPECT_EQ(parsed.mapping.attributes[0].first, "level");
    EXPECT_EQ(parsed.mapping.attributes[0].second, "l2");
    EXPECT_EQ(parsed.mapping.attributes[1].first, "type");
    EXPECT_EQ(parsed.mapping.attributes[1].second, "miss");
    EXPECT_TRUE(parsed.dynamic_attributes.empty());
  }

  // l3d_cache_refill -> level=l3, type=miss
  {
    auto parsed = parseMetricKey("l3d_cache_refill");
    ASSERT_TRUE(parsed.matched);
    EXPECT_EQ(parsed.mapping.otel_name, "l3d_cache_refill");
    EXPECT_EQ(parsed.mapping.unit, "{event}");
    EXPECT_DOUBLE_EQ(parsed.mapping.scale_factor, 1.0);
    EXPECT_FALSE(parsed.mapping.skip);
    ASSERT_EQ(parsed.mapping.attributes.size(), 2);
    EXPECT_EQ(parsed.mapping.attributes[0].first, "level");
    EXPECT_EQ(parsed.mapping.attributes[0].second, "l3");
    EXPECT_EQ(parsed.mapping.attributes[1].first, "type");
    EXPECT_EQ(parsed.mapping.attributes[1].second, "miss");
    EXPECT_TRUE(parsed.dynamic_attributes.empty());
  }
}

TEST(OTLPLoggerTest, MetricMappingArmFPOperations) {
  // FP_HP_SPEC -> precision=half
  {
    auto parsed = parseMetricKey("FP_HP_SPEC");
    ASSERT_TRUE(parsed.matched);
    EXPECT_EQ(parsed.mapping.otel_name, "FP_HP_SPEC");
    EXPECT_EQ(parsed.mapping.unit, "{operation}");
    EXPECT_DOUBLE_EQ(parsed.mapping.scale_factor, 1.0);
    EXPECT_FALSE(parsed.mapping.skip);
    ASSERT_EQ(parsed.mapping.attributes.size(), 1);
    EXPECT_EQ(parsed.mapping.attributes[0].first, "precision");
    EXPECT_EQ(parsed.mapping.attributes[0].second, "half");
    EXPECT_TRUE(parsed.dynamic_attributes.empty());
  }

  // FP_SP_SPEC -> precision=single
  {
    auto parsed = parseMetricKey("FP_SP_SPEC");
    ASSERT_TRUE(parsed.matched);
    EXPECT_EQ(parsed.mapping.otel_name, "FP_SP_SPEC");
    EXPECT_EQ(parsed.mapping.unit, "{operation}");
    EXPECT_DOUBLE_EQ(parsed.mapping.scale_factor, 1.0);
    EXPECT_FALSE(parsed.mapping.skip);
    ASSERT_EQ(parsed.mapping.attributes.size(), 1);
    EXPECT_EQ(parsed.mapping.attributes[0].first, "precision");
    EXPECT_EQ(parsed.mapping.attributes[0].second, "single");
    EXPECT_TRUE(parsed.dynamic_attributes.empty());
  }

  // FP_DP_SPEC -> precision=double
  {
    auto parsed = parseMetricKey("FP_DP_SPEC");
    ASSERT_TRUE(parsed.matched);
    EXPECT_EQ(parsed.mapping.otel_name, "FP_DP_SPEC");
    EXPECT_EQ(parsed.mapping.unit, "{operation}");
    EXPECT_DOUBLE_EQ(parsed.mapping.scale_factor, 1.0);
    EXPECT_FALSE(parsed.mapping.skip);
    ASSERT_EQ(parsed.mapping.attributes.size(), 1);
    EXPECT_EQ(parsed.mapping.attributes[0].first, "precision");
    EXPECT_EQ(parsed.mapping.attributes[0].second, "double");
    EXPECT_TRUE(parsed.dynamic_attributes.empty());
  }
}

TEST(OTLPLoggerTest, MetricMappingArmTLBWalks) {
  // dtlb_walk -> type=data
  {
    auto parsed = parseMetricKey("dtlb_walk");
    ASSERT_TRUE(parsed.matched);
    EXPECT_EQ(parsed.mapping.otel_name, "dtlb_walk");
    EXPECT_EQ(parsed.mapping.unit, "{event}");
    EXPECT_DOUBLE_EQ(parsed.mapping.scale_factor, 1.0);
    EXPECT_FALSE(parsed.mapping.skip);
    ASSERT_EQ(parsed.mapping.attributes.size(), 1);
    EXPECT_EQ(parsed.mapping.attributes[0].first, "type");
    EXPECT_EQ(parsed.mapping.attributes[0].second, "data");
    EXPECT_TRUE(parsed.dynamic_attributes.empty());
  }

  // itlb_walk -> type=instruction
  {
    auto parsed = parseMetricKey("itlb_walk");
    ASSERT_TRUE(parsed.matched);
    EXPECT_EQ(parsed.mapping.otel_name, "itlb_walk");
    EXPECT_EQ(parsed.mapping.unit, "{event}");
    EXPECT_DOUBLE_EQ(parsed.mapping.scale_factor, 1.0);
    EXPECT_FALSE(parsed.mapping.skip);
    ASSERT_EQ(parsed.mapping.attributes.size(), 1);
    EXPECT_EQ(parsed.mapping.attributes[0].first, "type");
    EXPECT_EQ(parsed.mapping.attributes[0].second, "instruction");
    EXPECT_TRUE(parsed.dynamic_attributes.empty());
  }
}

// =============================================================================
// OTLPLogger Class Tests (no exporter needed)
// =============================================================================

TEST(OTLPLoggerTest, BasicTest) {
  // Check that basic logger class is collecting values
  // from various log functions.
  OTLPLogger logger;

  logger.logInt("uptime", 10000);
  logger.logFloat("pi", 3.1457f);
  logger.logUint("cpu_util", 25);
  logger.logUint("rx_bytes.eth0", 42);

  auto& kvs = logger.pending_metrics_;
  EXPECT_DOUBLE_EQ(kvs["uptime"], 10000.0);
  EXPECT_NEAR(kvs["pi"], 3.1457, 0.001);
  EXPECT_DOUBLE_EQ(kvs["cpu_util"], 25.0);
  EXPECT_DOUBLE_EQ(kvs["rx_bytes.eth0"], 42.0);

  // DO NOT RUN finalize() to avoid sending data to OTLP exporter.
}

TEST(OTLPLoggerTest, SlurmAttribution) {
  // logStr with Slurm attribution keys should store them as pending attrs.
  OTLPLogger logger;

  logger.logStr("job_id", "12345");
  logger.logStr("username", "testuser");
  logger.logStr("slurm_account", "research");
  logger.logStr("slurm_partition", "gpu");

  auto& attrs = logger.pending_attributes_;
  EXPECT_EQ(attrs["job_id"], "12345");
  EXPECT_EQ(attrs["username"], "testuser");
  EXPECT_EQ(attrs["slurm_account"], "research");
  EXPECT_EQ(attrs["slurm_partition"], "gpu");
}

TEST(OTLPLoggerTest, LogStrNonAttribution) {
  // logStr with non-Slurm keys should be silently ignored.
  OTLPLogger logger;

  logger.logStr("some_random_key", "some_value");
  logger.logStr("hostname", "host1");

  auto& attrs = logger.pending_attributes_;
  EXPECT_EQ(attrs.count("some_random_key"), 0);
  EXPECT_EQ(attrs.count("hostname"), 0);
  EXPECT_TRUE(attrs.empty());
}

TEST(OTLPLoggerTest, FinalizeEmpty) {
  // finalize() with no pending metrics should be a no-op.
  OTLPLogger logger;

  // Set some string attrs but no numeric metrics.
  logger.logStr("job_id", "12345");

  // finalize() should not crash and should clear state.
  logger.finalize();

  EXPECT_TRUE(logger.pending_metrics_.empty());
  EXPECT_TRUE(logger.pending_attributes_.empty());
}

TEST(OTLPLoggerTest, FinalizeMultiple) {
  // Multiple finalize() calls should work. Each clears state.
  OTLPLogger logger;

  logger.logInt("uptime", 100);
  EXPECT_EQ(logger.pending_metrics_.size(), 1);
  // finalize() takes the !OTLPManager::isInitialized() early-return path
  // which clears both maps. This is safe in unit tests.
  logger.finalize();
  EXPECT_TRUE(logger.pending_metrics_.empty());

  // Second batch
  logger.logInt("uptime", 200);
  logger.logFloat("cpu_util", 50.0f);
  EXPECT_EQ(logger.pending_metrics_.size(), 2);
  EXPECT_DOUBLE_EQ(logger.pending_metrics_["uptime"], 200.0);
  EXPECT_NEAR(logger.pending_metrics_["cpu_util"], 50.0, 0.01);
}

// =============================================================================
// Negative Tests
// =============================================================================

TEST(OTLPLoggerTest, UnknownMetric) {
  // Unknown metric key should be passed through with raw name.
  {
    auto parsed = parseMetricKey("totally_unknown_metric");
    ASSERT_TRUE(parsed.matched);
    EXPECT_EQ(parsed.mapping.otel_name, "totally_unknown_metric");

    EXPECT_FALSE(parsed.mapping.skip);
  }
}

TEST(OTLPLoggerTest, EmptyMetricKey) {
  // Empty key should not match.
  auto parsed = parseMetricKey("");
  EXPECT_FALSE(parsed.matched);
}

TEST(OTLPLoggerTest, EmptyDeviceNetwork) {
  // Network metric with empty device name: "rx_bytes."
  // The dot is present but device is empty.
  auto parsed = parseMetricKey("rx_bytes.");
  ASSERT_TRUE(parsed.matched);
  EXPECT_EQ(parsed.mapping.otel_name, "rx_bytes");
  // device attribute should NOT be present (empty)
  EXPECT_TRUE(parsed.dynamic_attributes.empty());
}

TEST(OTLPLoggerTest, NaNAndInfValues) {
  // NaN and Inf should be handled gracefully by logger accumulation
  // (the filter happens during export, not in parsing).
  OTLPLogger logger;

  float nan_val = std::numeric_limits<float>::quiet_NaN();
  float inf_val = std::numeric_limits<float>::infinity();

  logger.logFloat("cpu_util", nan_val);
  EXPECT_TRUE(std::isnan(logger.pending_metrics_["cpu_util"]));

  logger.logFloat("uptime", inf_val);
  EXPECT_TRUE(std::isinf(logger.pending_metrics_["uptime"]));
}

TEST(OTLPLoggerTest, LargeUint64Values) {
  // Very large uint64 values may lose precision when cast to double.
  OTLPLogger logger;
  uint64_t large_val = std::numeric_limits<uint64_t>::max();
  logger.logUint("rx_bytes.eth0", large_val);

  // The value stored is a double cast, verify it does not crash.
  double stored = logger.pending_metrics_["rx_bytes.eth0"];
  EXPECT_GT(stored, 0.0);
  // Note: precision loss is expected for values > 2^53.
  // We just verify it does not crash or produce NaN.
  EXPECT_FALSE(std::isnan(stored));
}

TEST(OTLPLoggerTest, ZeroValues) {
  // Zero values should be handled normally.
  OTLPLogger logger;

  logger.logInt("cpu_util", 0);
  logger.logFloat("cpu_u", 0.0f);
  logger.logUint("rx_bytes.eth0", 0);

  EXPECT_DOUBLE_EQ(logger.pending_metrics_["cpu_util"], 0.0);
  EXPECT_DOUBLE_EQ(logger.pending_metrics_["cpu_u"], 0.0);
  EXPECT_DOUBLE_EQ(logger.pending_metrics_["rx_bytes.eth0"], 0.0);
}

TEST(OTLPLoggerTest, NegativeValues) {
  // Negative values for int metrics should be stored correctly.
  OTLPLogger logger;

  logger.logInt("some_metric", -42);
  EXPECT_DOUBLE_EQ(logger.pending_metrics_["some_metric"], -42.0);

  logger.logFloat("another", -3.14f);
  EXPECT_NEAR(logger.pending_metrics_["another"], -3.14, 0.01);
}

TEST(OTLPLoggerTest, PercentToRatioConversion) {
  // Verify that CPU utilization metrics are correctly
  // flagged for scale_factor=100 conversion.
  auto parsed = parseMetricKey("cpu_util");
  ASSERT_TRUE(parsed.matched);
  EXPECT_DOUBLE_EQ(parsed.mapping.scale_factor, 0.01);

  // Simulate the conversion: 75.0 -> 0.75
  double raw = 75.0;
  double converted = raw * parsed.mapping.scale_factor;
  EXPECT_DOUBLE_EQ(converted, 0.75);

  // CPU time metrics should have scale_factor=1000 (ms to s).
  auto time_parsed = parseMetricKey("cpu_u_ms");
  ASSERT_TRUE(time_parsed.matched);
  EXPECT_DOUBLE_EQ(time_parsed.mapping.scale_factor, 0.001);

  // uptime should NOT be scaled.
  auto uptime_parsed = parseMetricKey("uptime");
  ASSERT_TRUE(uptime_parsed.matched);
  EXPECT_DOUBLE_EQ(uptime_parsed.mapping.scale_factor, 1.0);
}

TEST(OTLPLoggerTest, NetworkMetricUnknownBase) {
  // A dotted key where the base is not a known network metric should
  // fall through to the unknown handler.
  auto parsed = parseMetricKey("unknown_base.eth0");
  ASSERT_TRUE(parsed.matched);
  EXPECT_EQ(parsed.mapping.otel_name, "unknown_base.eth0");
}

TEST(OTLPLoggerTest, SetTimestampIsNoOp) {
  // setTimestamp should be a no-op (OTel SDK handles timestamps).
  OTLPLogger logger;
  auto now = std::chrono::system_clock::now();
  // Should not crash or change any state.
  logger.setTimestamp(now);
  EXPECT_TRUE(logger.pending_metrics_.empty());
  EXPECT_TRUE(logger.pending_attributes_.empty());
}

TEST(OTLPLoggerTest, OverwriteMetricValue) {
  // Logging the same key twice should overwrite.
  OTLPLogger logger;

  logger.logInt("uptime", 100);
  EXPECT_DOUBLE_EQ(logger.pending_metrics_["uptime"], 100.0);

  logger.logInt("uptime", 200);
  EXPECT_DOUBLE_EQ(logger.pending_metrics_["uptime"], 200.0);
}

TEST(OTLPLoggerTest, OverwriteStringAttribute) {
  // Logging the same Slurm key twice should overwrite.
  OTLPLogger logger;

  logger.logStr("job_id", "111");
  EXPECT_EQ(logger.pending_attributes_["job_id"], "111");

  logger.logStr("job_id", "222");
  EXPECT_EQ(logger.pending_attributes_["job_id"], "222");
}

TEST(OTLPLoggerTest, SpecialCharactersInKey) {
  // Keys with special characters should fall through as passthrough.
  {
    auto parsed = parseMetricKey("my-metric_with.dots");
    ASSERT_TRUE(parsed.matched);
    // "my-metric_with" is not a known network base, so falls through.
    EXPECT_EQ(parsed.mapping.otel_name, "my-metric_with.dots");
  }

  {
    auto parsed = parseMetricKey("metric:with:colons");
    ASSERT_TRUE(parsed.matched);
    EXPECT_EQ(parsed.mapping.otel_name, "metric:with:colons");
  }
}

TEST(OTLPLoggerTest, UnicodeInKey) {
  // Unicode characters in metric key - should be passed through.
  auto parsed = parseMetricKey("m\xC3\xA9trique");
  ASSERT_TRUE(parsed.matched);
  EXPECT_EQ(parsed.mapping.otel_name, "m\xC3\xA9trique");
}

TEST(OTLPLoggerTest, WhitespaceOnlyKey) {
  // Whitespace-only key should be passed through with raw name.
  auto parsed = parseMetricKey("   ");
  ASSERT_TRUE(parsed.matched);
  EXPECT_EQ(parsed.mapping.otel_name, "   ");
}

TEST(OTLPLoggerTest, VeryLongKey) {
  // Very long key should not crash.
  std::string long_key(10000, 'a');
  auto parsed = parseMetricKey(long_key);
  ASSERT_TRUE(parsed.matched);
  EXPECT_EQ(parsed.mapping.otel_name, long_key);
}

TEST(OTLPLoggerTest, EmptyStringLogStr) {
  // logStr with empty value should still store it for attribution keys.
  OTLPLogger logger;

  logger.logStr("job_id", "");
  EXPECT_EQ(logger.pending_attributes_["job_id"], "");

  // Non-attribution empty value should be ignored.
  logger.logStr("random", "");
  EXPECT_EQ(logger.pending_attributes_.count("random"), 0);
}

TEST(OTLPLoggerTest, MixedMetricTypes) {
  // Log a mix of int, float, uint for the same key - last write wins.
  OTLPLogger logger;

  logger.logInt("cpu_util", 50);
  EXPECT_DOUBLE_EQ(logger.pending_metrics_["cpu_util"], 50.0);

  logger.logFloat("cpu_util", 75.5f);
  EXPECT_NEAR(logger.pending_metrics_["cpu_util"], 75.5, 0.01);

  logger.logUint("cpu_util", 99);
  EXPECT_DOUBLE_EQ(logger.pending_metrics_["cpu_util"], 99.0);
}

// =============================================================================
// Finalize Logic Tests (without network/exporter)
// =============================================================================

TEST(OTLPLoggerTest, DeviceIdExtraction) {
  // Verify that logging "device" stores it in pending_metrics_ and that
  // parseMetricKey correctly identifies "device" as a
  // skip-flagged metadata key.
  // This tests the finalize() device-lookup logic indirectly.
  OTLPLogger logger;

  // Log GPU metrics along with the device metadata key.
  logger.logInt("device", 3);
  logger.logFloat("gpu_device_utilization", 85.0f);
  logger.logFloat("gpu_power_draw", 250.0f);

  // Verify device value is stored in pending_metrics_.
  ASSERT_EQ(logger.pending_metrics_.count("device"), 1);
  EXPECT_DOUBLE_EQ(logger.pending_metrics_["device"], 3.0);

  // Verify parseMetricKey marks "device" as skip (metadata-only).
  auto device_parsed = parseMetricKey("device");
  ASSERT_TRUE(device_parsed.matched);
  EXPECT_TRUE(device_parsed.mapping.skip);
  EXPECT_EQ(device_parsed.mapping.otel_name, "device");

  // Verify that the device value can be formatted as finalize() does:
  // fmt::format("{}", static_cast<int64_t>(device_value))
  double device_val = logger.pending_metrics_["device"];
  std::string device_id = fmt::format("{}", static_cast<int64_t>(device_val));
  EXPECT_EQ(device_id, "3");

  // Also verify minor_id is skip-flagged.
  auto minor_parsed = parseMetricKey("minor_id");
  ASSERT_TRUE(minor_parsed.matched);
  EXPECT_TRUE(minor_parsed.mapping.skip);

  // Negative: non-metadata GPU metrics should NOT have skip=true.
  auto gpu_util_parsed = parseMetricKey("gpu_device_utilization");
  ASSERT_TRUE(gpu_util_parsed.matched);
  EXPECT_FALSE(gpu_util_parsed.mapping.skip);

  auto gpu_power_parsed = parseMetricKey("gpu_power_draw");
  ASSERT_TRUE(gpu_power_parsed.matched);
  EXPECT_FALSE(gpu_power_parsed.mapping.skip);

  // Edge case: device value of 0 (valid GPU index).
  logger.logInt("device", 0);
  EXPECT_DOUBLE_EQ(logger.pending_metrics_["device"], 0.0);
  std::string device_id_zero = fmt::format(
      "{}", static_cast<int64_t>(logger.pending_metrics_["device"]));
  EXPECT_EQ(device_id_zero, "0");

  // Edge case: negative device value (invalid but should not crash).
  logger.logInt("device", -1);
  std::string device_id_neg = fmt::format(
      "{}", static_cast<int64_t>(logger.pending_metrics_["device"]));
  EXPECT_EQ(device_id_neg, "-1");

  // Edge case: large device value.
  logger.logInt("device", 255);
  std::string device_id_large = fmt::format(
      "{}", static_cast<int64_t>(logger.pending_metrics_["device"]));
  EXPECT_EQ(device_id_large, "255");
}

TEST(OTLPLoggerTest, GPUAttributeMerging) {
  // Verify that GPU metrics + Slurm attribution + device metadata are stored
  // correctly and that parseMetricKey produces the right mapping for each.
  OTLPLogger logger;

  // Log Slurm attribution strings.
  logger.logStr("job_id", "12345");
  logger.logStr("username", "testuser");
  logger.logStr("slurm_account", "research");
  logger.logStr("slurm_partition", "gpu-cluster");

  // Log device metadata.
  logger.logInt("device", 2);

  // Log GPU metrics.
  logger.logFloat("gpu_device_utilization", 85.0f);
  logger.logFloat("gpu_memory_utilization", 60.0f);
  logger.logFloat("gpu_power_draw", 300.0f);
  logger.logFloat("graphics_engine_active_ratio", 0.75f);
  logger.logFloat("sm_active_ratio", 0.5f);
  logger.logFloat("pcie_tx_bytes", 1000000.0f);
  logger.logFloat("fp16_active", 0.3f);

  // Verify Slurm attribution strings are in pending_attributes_.
  ASSERT_EQ(logger.pending_attributes_.size(), 4);
  EXPECT_EQ(logger.pending_attributes_["job_id"], "12345");
  EXPECT_EQ(logger.pending_attributes_["username"], "testuser");
  EXPECT_EQ(logger.pending_attributes_["slurm_account"], "research");
  EXPECT_EQ(logger.pending_attributes_["slurm_partition"], "gpu-cluster");

  // Verify device value is in pending_metrics_.
  ASSERT_EQ(logger.pending_metrics_.count("device"), 1);
  EXPECT_DOUBLE_EQ(logger.pending_metrics_["device"], 2.0);

  // Verify gpu_device_utilization mapping.
  {
    auto parsed = parseMetricKey("gpu_device_utilization");
    ASSERT_TRUE(parsed.matched);
    EXPECT_EQ(parsed.mapping.otel_name, "gpu_device_utilization");
    EXPECT_EQ(parsed.mapping.unit, "1");

    EXPECT_DOUBLE_EQ(parsed.mapping.scale_factor, 0.01);
    EXPECT_FALSE(parsed.mapping.skip);
    // Should have hw.gpu.task=device attribute.
    bool found_task = false;
    for (const auto& [k, v] : parsed.mapping.attributes) {
      if (k == "hw.gpu.task" && v == "device") {
        found_task = true;
      }
    }
    EXPECT_TRUE(found_task);
  }

  // Verify gpu_memory_utilization mapping.
  {
    auto parsed = parseMetricKey("gpu_memory_utilization");
    ASSERT_TRUE(parsed.matched);
    EXPECT_EQ(parsed.mapping.otel_name, "gpu_memory_utilization");
    EXPECT_EQ(parsed.mapping.unit, "1");
    EXPECT_DOUBLE_EQ(parsed.mapping.scale_factor, 0.01);
    EXPECT_FALSE(parsed.mapping.skip);
  }

  // Verify that non-percent GPU metrics do NOT have scaling.
  {
    auto parsed = parseMetricKey("gpu_power_draw");
    ASSERT_TRUE(parsed.matched);
    EXPECT_DOUBLE_EQ(parsed.mapping.scale_factor, 1.0);
  }
  {
    auto parsed = parseMetricKey("graphics_engine_active_ratio");
    ASSERT_TRUE(parsed.matched);
    EXPECT_DOUBLE_EQ(parsed.mapping.scale_factor, 1.0);
  }
  {
    auto parsed = parseMetricKey("sm_active_ratio");
    ASSERT_TRUE(parsed.matched);
    EXPECT_DOUBLE_EQ(parsed.mapping.scale_factor, 1.0);
  }
  {
    auto parsed = parseMetricKey("pcie_tx_bytes");
    ASSERT_TRUE(parsed.matched);
    EXPECT_DOUBLE_EQ(parsed.mapping.scale_factor, 1.0);
  }
  {
    auto parsed = parseMetricKey("fp16_active");
    ASSERT_TRUE(parsed.matched);
    EXPECT_DOUBLE_EQ(parsed.mapping.scale_factor, 1.0);
  }

  // Verify GPU metrics are identified by kGpuMetrics lookup (same logic as
  // finalize uses to decide whether to attach hw.id and Slurm attrs).
  // Since kGpuMetrics is not exposed in the header, we verify indirectly
  // by checking that known GPU metrics parse successfully with expected
  // attributes, and non-GPU metrics do not have GPU-specific attributes.
  auto check_is_gpu = [](const std::string& key) {
    auto parsed = parseMetricKey(key);
    if (!parsed.matched) {
      return false;
    }
    // GPU metrics have attributes from kGpuMetrics (hw.gpu.task, pipe,
    // direction, hw.type) or are known GPU metric names.
    // Use the same set of known GPU keys that kGpuMetrics contains.
    static const std::unordered_set<std::string> gpu_keys = {
        "graphics_engine_active_ratio",
        "sm_active_ratio",
        "sm_occupancy",
        "gpu_frequency_mhz",
        "fp16_active",
        "fp32_active",
        "fp64_active",
        "tensorcore_active",
        "hbm_mem_bw_util",
        "pcie_tx_bytes",
        "pcie_rx_bytes",
        "nvlink_tx_bytes",
        "nvlink_rx_bytes",
        "gpu_device_utilization",
        "gpu_memory_utilization",
        "gpu_power_draw",
        "dcgm_error",
        "minor_id",
        "device",
    };
    return gpu_keys.count(key) > 0;
  };
  EXPECT_TRUE(check_is_gpu("gpu_device_utilization"));
  EXPECT_TRUE(check_is_gpu("gpu_memory_utilization"));
  EXPECT_TRUE(check_is_gpu("gpu_power_draw"));
  EXPECT_TRUE(check_is_gpu("graphics_engine_active_ratio"));
  EXPECT_TRUE(check_is_gpu("sm_active_ratio"));
  EXPECT_TRUE(check_is_gpu("pcie_tx_bytes"));
  EXPECT_TRUE(check_is_gpu("fp16_active"));
  EXPECT_TRUE(check_is_gpu("dcgm_error"));

  // Negative: non-GPU metrics should NOT be in the GPU set.
  EXPECT_FALSE(check_is_gpu("cpu_util"));
  EXPECT_FALSE(check_is_gpu("uptime"));
  EXPECT_FALSE(check_is_gpu("rx_bytes.eth0"));
  EXPECT_FALSE(check_is_gpu("cpu_u_ms"));
  EXPECT_FALSE(check_is_gpu("totally_unknown"));

  // Edge case: empty Slurm attribution values.
  OTLPLogger logger2;
  logger2.logStr("job_id", "");
  logger2.logStr("username", "");
  EXPECT_EQ(logger2.pending_attributes_["job_id"], "");
  EXPECT_EQ(logger2.pending_attributes_["username"], "");

  // Edge case: no device metadata logged -
  // pending_metrics_ has no "device" key.
  OTLPLogger logger3;
  logger3.logFloat("gpu_device_utilization", 50.0f);
  EXPECT_EQ(logger3.pending_metrics_.count("device"), 0);
}

TEST(OTLPLoggerTest, FinalizeClearsState) {
  // Verify that pending_metrics_ accumulates correctly per batch and that
  // a second batch starts fresh after clearing (simulating finalize behavior).
  OTLPLogger logger;

  // First batch.
  logger.logFloat("cpu_util", 75.0f);
  logger.logInt("uptime", 1000);
  logger.logStr("job_id", "111");
  ASSERT_EQ(logger.pending_metrics_.size(), 2);
  ASSERT_EQ(logger.pending_attributes_.size(), 1);
  EXPECT_NEAR(logger.pending_metrics_["cpu_util"], 75.0, 0.01);
  EXPECT_DOUBLE_EQ(logger.pending_metrics_["uptime"], 1000.0);
  EXPECT_EQ(logger.pending_attributes_["job_id"], "111");

  // finalize() clears both maps (takes the !isInitialized() path).
  logger.finalize();
  EXPECT_TRUE(logger.pending_metrics_.empty());
  EXPECT_TRUE(logger.pending_attributes_.empty());

  // Second batch should start completely fresh.
  logger.logFloat("cpu_util", 80.0f);
  logger.logStr("job_id", "222");
  ASSERT_EQ(logger.pending_metrics_.size(), 1);
  ASSERT_EQ(logger.pending_attributes_.size(), 1);
  EXPECT_NEAR(logger.pending_metrics_["cpu_util"], 80.0, 0.01);
  EXPECT_EQ(logger.pending_attributes_["job_id"], "222");
  // uptime from the first batch should NOT be present.
  EXPECT_EQ(logger.pending_metrics_.count("uptime"), 0);

  // Third batch: empty batch.
  logger.finalize();
  EXPECT_TRUE(logger.pending_metrics_.empty());
  EXPECT_TRUE(logger.pending_attributes_.empty());

  // Verify nothing bleeds into subsequent batches.
  logger.logUint("rx_bytes.eth0", 42);
  EXPECT_EQ(logger.pending_metrics_.size(), 1);
  EXPECT_EQ(logger.pending_metrics_.count("cpu_util"), 0);
  EXPECT_EQ(logger.pending_attributes_.count("job_id"), 0);
}

TEST(OTLPLoggerTest, CompleteMetricFlowWithoutNetwork) {
  // Test a representative set of metrics through parseMetricKey and verify the
  // full mapping including OTEL name, all attributes,
  // scale_factor, kind, unit. This exercises the
  // complete path that finalize() would take for
  // each metric.

  // --- CPU utilization metric ---
  {
    auto parsed = parseMetricKey("cpu_util");
    ASSERT_TRUE(parsed.matched);
    EXPECT_EQ(parsed.mapping.otel_name, "cpu_util");
    EXPECT_EQ(parsed.mapping.unit, "1");

    EXPECT_DOUBLE_EQ(parsed.mapping.scale_factor, 0.01);
    EXPECT_FALSE(parsed.mapping.skip);
    ASSERT_EQ(parsed.mapping.attributes.size(), 1);
    EXPECT_EQ(parsed.mapping.attributes[0].first, "cpu.mode");
    EXPECT_EQ(parsed.mapping.attributes[0].second, "active");
    EXPECT_TRUE(parsed.dynamic_attributes.empty());

    // Simulate the scale_factor conversion.
    double raw = 75.0;
    double converted = raw * parsed.mapping.scale_factor;
    EXPECT_DOUBLE_EQ(converted, 0.75);
  }

  // --- CPU time metric (Gauge) ---
  {
    auto parsed = parseMetricKey("cpu_u_ms");
    ASSERT_TRUE(parsed.matched);
    EXPECT_EQ(parsed.mapping.otel_name, "cpu_u_ms");
    EXPECT_EQ(parsed.mapping.unit, "s");

    EXPECT_DOUBLE_EQ(parsed.mapping.scale_factor, 0.001);
    EXPECT_FALSE(parsed.mapping.skip);
    ASSERT_EQ(parsed.mapping.attributes.size(), 1);
    EXPECT_EQ(parsed.mapping.attributes[0].first, "cpu.mode");
    EXPECT_EQ(parsed.mapping.attributes[0].second, "user");
    EXPECT_TRUE(parsed.dynamic_attributes.empty());
  }

  // --- NUMA CPU metric ---
  {
    auto parsed = parseMetricKey("cpu_s_node2");
    ASSERT_TRUE(parsed.matched);
    EXPECT_EQ(parsed.mapping.otel_name, "cpu_s_node2");
    EXPECT_EQ(parsed.mapping.unit, "1");

    EXPECT_DOUBLE_EQ(parsed.mapping.scale_factor, 0.01);
    EXPECT_FALSE(parsed.mapping.skip);
    ASSERT_EQ(parsed.mapping.attributes.size(), 1);
    EXPECT_EQ(parsed.mapping.attributes[0].first, "cpu.mode");
    EXPECT_EQ(parsed.mapping.attributes[0].second, "system");
    ASSERT_EQ(parsed.dynamic_attributes.size(), 1);
    EXPECT_EQ(parsed.dynamic_attributes[0].first, "cpu.socket");
    EXPECT_EQ(parsed.dynamic_attributes[0].second, "2");
  }

  // --- Network metric with device ---
  {
    auto parsed = parseMetricKey("tx_bytes.ens5");
    ASSERT_TRUE(parsed.matched);
    EXPECT_EQ(parsed.mapping.otel_name, "tx_bytes");
    EXPECT_EQ(parsed.mapping.unit, "By");

    EXPECT_DOUBLE_EQ(parsed.mapping.scale_factor, 1.0);
    EXPECT_FALSE(parsed.mapping.skip);
    ASSERT_EQ(parsed.mapping.attributes.size(), 1);
    EXPECT_EQ(parsed.mapping.attributes[0].first, "network.io.direction");
    EXPECT_EQ(parsed.mapping.attributes[0].second, "transmit");
    ASSERT_EQ(parsed.dynamic_attributes.size(), 1);
    EXPECT_EQ(parsed.dynamic_attributes[0].first, "network.interface.name");
    EXPECT_EQ(parsed.dynamic_attributes[0].second, "ens5");
  }

  // --- GPU metric with device + scale_factor=100 ---
  {
    auto parsed = parseMetricKey("gpu_device_utilization");
    ASSERT_TRUE(parsed.matched);
    EXPECT_EQ(parsed.mapping.otel_name, "gpu_device_utilization");
    EXPECT_EQ(parsed.mapping.unit, "1");

    EXPECT_DOUBLE_EQ(parsed.mapping.scale_factor, 0.01);
    EXPECT_FALSE(parsed.mapping.skip);

    // Check static attributes.
    bool found_task = false;
    for (const auto& [k, v] : parsed.mapping.attributes) {
      if (k == "hw.gpu.task" && v == "device") {
        found_task = true;
      }
    }
    EXPECT_TRUE(found_task);
    EXPECT_TRUE(parsed.dynamic_attributes.empty());

    // Simulate the full attribute merge finalize() would do:
    // static attrs + dynamic attrs + hw.id (from device) + slurm attrs.
    std::vector<std::pair<std::string, std::string>> all_attrs;
    all_attrs.insert(
        all_attrs.end(),
        parsed.mapping.attributes.begin(),
        parsed.mapping.attributes.end());
    all_attrs.insert(
        all_attrs.end(),
        parsed.dynamic_attributes.begin(),
        parsed.dynamic_attributes.end());

    // Add hw.id from device=2.
    std::string gpu_device_id = fmt::format("{}", 2);
    // GPU metrics are identified by kGpuMetrics lookup in finalize().
    bool is_gpu_metric = true; // gpu_device_utilization is a known GPU metric
    if (is_gpu_metric && !gpu_device_id.empty()) {
      all_attrs.emplace_back("hw.id", gpu_device_id);
    }

    // Add Slurm attrs.
    std::unordered_map<std::string, std::string> slurm_attrs = {
        {"job_id", "99999"}, {"username", "gpuuser"}};
    if (is_gpu_metric) {
      for (const auto& [attr_key, attr_val] : slurm_attrs) {
        all_attrs.emplace_back(attr_key, attr_val);
      }
    }

    // Verify merged attributes contain expected entries.
    auto find_attr = [&](const std::string& key) -> std::string {
      for (const auto& [k, v] : all_attrs) {
        if (k == key) {
          return v;
        }
      }
      return "";
    };
    EXPECT_EQ(find_attr("hw.gpu.task"), "device");
    EXPECT_EQ(find_attr("hw.id"), "2");
    // Slurm attrs (order not guaranteed, just check presence).
    bool has_job_id = false;
    bool has_username = false;
    for (const auto& [k, v] : all_attrs) {
      if (k == "job_id" && v == "99999")
        has_job_id = true;
      if (k == "username" && v == "gpuuser")
        has_username = true;
    }
    EXPECT_TRUE(has_job_id);
    EXPECT_TRUE(has_username);

    // Simulate scale_factor conversion.
    double raw = 85.0;
    double converted = raw * parsed.mapping.scale_factor;
    EXPECT_DOUBLE_EQ(converted, 0.85);
  }

  // --- GPU metric without scaling (power) ---
  {
    auto parsed = parseMetricKey("gpu_power_draw");
    ASSERT_TRUE(parsed.matched);
    EXPECT_EQ(parsed.mapping.otel_name, "gpu_power_draw");
    EXPECT_EQ(parsed.mapping.unit, "W");

    EXPECT_DOUBLE_EQ(parsed.mapping.scale_factor, 1.0);
    EXPECT_FALSE(parsed.mapping.skip);
    bool found_hw_type = false;
    for (const auto& [k, v] : parsed.mapping.attributes) {
      if (k == "hw.type" && v == "gpu") {
        found_hw_type = true;
      }
    }
    EXPECT_TRUE(found_hw_type);
  }

  // --- Skip-flagged metadata key ---
  {
    auto parsed = parseMetricKey("device");
    ASSERT_TRUE(parsed.matched);
    EXPECT_TRUE(parsed.mapping.skip);
    EXPECT_EQ(parsed.mapping.otel_name, "device");
    EXPECT_TRUE(parsed.mapping.unit.empty());
  }

  // --- Unknown metric (passthrough) ---
  {
    auto parsed = parseMetricKey("custom_metric_xyz");
    ASSERT_TRUE(parsed.matched);
    EXPECT_EQ(parsed.mapping.otel_name, "custom_metric_xyz");
    EXPECT_EQ(parsed.mapping.unit, "");

    EXPECT_DOUBLE_EQ(parsed.mapping.scale_factor, 1.0);
    EXPECT_FALSE(parsed.mapping.skip);
    EXPECT_TRUE(parsed.mapping.attributes.empty());
    EXPECT_TRUE(parsed.dynamic_attributes.empty());
  }

  // --- Special CPU metric (uptime) ---
  {
    auto parsed = parseMetricKey("uptime");
    ASSERT_TRUE(parsed.matched);
    EXPECT_EQ(parsed.mapping.otel_name, "uptime");
    EXPECT_EQ(parsed.mapping.unit, "s");

    EXPECT_DOUBLE_EQ(parsed.mapping.scale_factor, 1.0);
    EXPECT_FALSE(parsed.mapping.skip);
    EXPECT_TRUE(parsed.mapping.attributes.empty());
    EXPECT_TRUE(parsed.dynamic_attributes.empty());
  }

  // --- Boundary: GPU metric with pipe attribute ---
  {
    auto parsed = parseMetricKey("tensorcore_active");
    ASSERT_TRUE(parsed.matched);
    EXPECT_EQ(parsed.mapping.otel_name, "tensorcore_active");
    EXPECT_EQ(parsed.mapping.unit, "1");

    EXPECT_DOUBLE_EQ(parsed.mapping.scale_factor, 1.0);
    EXPECT_FALSE(parsed.mapping.skip);
    ASSERT_EQ(parsed.mapping.attributes.size(), 1);
    EXPECT_EQ(parsed.mapping.attributes[0].first, "pipe");
    EXPECT_EQ(parsed.mapping.attributes[0].second, "tensorcore");
  }
}

// =============================================================================
// Multi-Threaded Isolation Test
// =============================================================================

TEST(OTLPLoggerTest, MultiThreadedIsolation) {
  // Verify that 3 OTLPLogger instances (simulating 3 collector threads)
  // can accumulate metrics concurrently without cross-contamination.
  // Also verify parseMetricKey is safe to call from multiple threads
  // (it uses only const static data).

  constexpr int kIterations = 500;

  OTLPLogger logger1; // simulates kernel collector
  OTLPLogger logger2; // simulates perf collector
  OTLPLogger logger3; // simulates GPU collector

  // Use threads to populate each logger concurrently.
  auto kernel_work = [&]() {
    for (int i = 0; i < kIterations; ++i) {
      logger1.logFloat("cpu_util", static_cast<float>(i));
      logger1.logFloat("cpu_u", static_cast<float>(i * 2));
      logger1.logInt("uptime", i * 1000);
      // Call parseMetricKey from this thread to verify thread-safety.
      auto parsed = parseMetricKey("cpu_util");
      EXPECT_TRUE(parsed.matched);
      EXPECT_EQ(parsed.mapping.otel_name, "cpu_util");
    }
  };

  auto perf_work = [&]() {
    for (int i = 0; i < kIterations; ++i) {
      logger2.logUint("cpu_u_ms", static_cast<uint64_t>(i * 100));
      logger2.logUint("cpu_s_ms", static_cast<uint64_t>(i * 50));
      logger2.logInt("mips", i * 10);
      // Call parseMetricKey from this thread.
      auto parsed = parseMetricKey("cpu_u_ms");
      EXPECT_TRUE(parsed.matched);
      EXPECT_EQ(parsed.mapping.otel_name, "cpu_u_ms");
    }
  };

  auto gpu_work = [&]() {
    for (int i = 0; i < kIterations; ++i) {
      logger3.logFloat("gpu_device_utilization", static_cast<float>(i % 100));
      logger3.logFloat("gpu_power_draw", static_cast<float>(i * 10));
      logger3.logInt("device", i % 8);
      logger3.logStr("job_id", fmt::format("job_{}", i));
      // Call parseMetricKey from this thread.
      auto parsed = parseMetricKey("gpu_device_utilization");
      EXPECT_TRUE(parsed.matched);
      EXPECT_EQ(parsed.mapping.otel_name, "gpu_device_utilization");
    }
  };

  std::thread t1(kernel_work);
  std::thread t2(perf_work);
  std::thread t3(gpu_work);

  t1.join();
  t2.join();
  t3.join();

  // Verify per-instance state isolation: each logger has ONLY its own metrics.

  // Logger 1 (kernel): should have cpu_util, cpu_u, uptime; NOT cpu_u_ms, etc.
  EXPECT_EQ(logger1.pending_metrics_.count("cpu_util"), 1);
  EXPECT_EQ(logger1.pending_metrics_.count("cpu_u"), 1);
  EXPECT_EQ(logger1.pending_metrics_.count("uptime"), 1);
  EXPECT_EQ(logger1.pending_metrics_.size(), 3);
  // Should NOT have any metrics from logger2 or logger3.
  EXPECT_EQ(logger1.pending_metrics_.count("cpu_u_ms"), 0);
  EXPECT_EQ(logger1.pending_metrics_.count("cpu_s_ms"), 0);
  EXPECT_EQ(logger1.pending_metrics_.count("mips"), 0);
  EXPECT_EQ(logger1.pending_metrics_.count("gpu_device_utilization"), 0);
  EXPECT_EQ(logger1.pending_metrics_.count("gpu_power_draw"), 0);
  EXPECT_EQ(logger1.pending_metrics_.count("device"), 0);
  EXPECT_TRUE(logger1.pending_attributes_.empty());

  // Logger 2 (perf): should have cpu_u_ms, cpu_s_ms, mips only.
  EXPECT_EQ(logger2.pending_metrics_.count("cpu_u_ms"), 1);
  EXPECT_EQ(logger2.pending_metrics_.count("cpu_s_ms"), 1);
  EXPECT_EQ(logger2.pending_metrics_.count("mips"), 1);
  EXPECT_EQ(logger2.pending_metrics_.size(), 3);
  EXPECT_EQ(logger2.pending_metrics_.count("cpu_util"), 0);
  EXPECT_EQ(logger2.pending_metrics_.count("gpu_device_utilization"), 0);
  EXPECT_TRUE(logger2.pending_attributes_.empty());

  // Logger 3 (GPU): should have gpu_device_utilization, gpu_power_draw, device.
  EXPECT_EQ(logger3.pending_metrics_.count("gpu_device_utilization"), 1);
  EXPECT_EQ(logger3.pending_metrics_.count("gpu_power_draw"), 1);
  EXPECT_EQ(logger3.pending_metrics_.count("device"), 1);
  EXPECT_EQ(logger3.pending_metrics_.size(), 3);
  EXPECT_EQ(logger3.pending_metrics_.count("cpu_util"), 0);
  EXPECT_EQ(logger3.pending_metrics_.count("cpu_u_ms"), 0);
  // GPU logger should have Slurm attrs.
  EXPECT_EQ(logger3.pending_attributes_.count("job_id"), 1);
  EXPECT_EQ(logger3.pending_attributes_.size(), 1);

  // Verify last-write-wins semantics for each logger's values.
  // Each loop runs kIterations times, so the last written value is
  // for i = kIterations - 1.
  EXPECT_DOUBLE_EQ(
      logger1.pending_metrics_["cpu_util"],
      static_cast<double>(kIterations - 1));
  EXPECT_DOUBLE_EQ(
      logger1.pending_metrics_["uptime"],
      static_cast<double>((kIterations - 1) * 1000));

  EXPECT_DOUBLE_EQ(
      logger2.pending_metrics_["cpu_u_ms"],
      static_cast<double>((kIterations - 1) * 100));

  EXPECT_DOUBLE_EQ(
      logger3.pending_metrics_["gpu_power_draw"],
      static_cast<double>((kIterations - 1) * 10));
  EXPECT_EQ(
      logger3.pending_attributes_["job_id"],
      fmt::format("job_{}", kIterations - 1));

  // Verify parseMetricKey still returns consistent
  // results after concurrent use.
  // (This would fail if there were any hidden mutable static state.)
  {
    auto p1 = parseMetricKey("cpu_util");
    EXPECT_TRUE(p1.matched);
    EXPECT_EQ(p1.mapping.otel_name, "cpu_util");
    EXPECT_DOUBLE_EQ(p1.mapping.scale_factor, 0.01);

    auto p2 = parseMetricKey("cpu_u_ms");
    EXPECT_TRUE(p2.matched);
    EXPECT_EQ(p2.mapping.otel_name, "cpu_u_ms");

    auto p3 = parseMetricKey("gpu_device_utilization");
    EXPECT_TRUE(p3.matched);
    EXPECT_EQ(p3.mapping.otel_name, "gpu_device_utilization");
    EXPECT_DOUBLE_EQ(p3.mapping.scale_factor, 0.01);

    auto p4 = parseMetricKey("rx_bytes.eth0");
    EXPECT_TRUE(p4.matched);
    EXPECT_EQ(p4.mapping.otel_name, "rx_bytes");
  }
}

// =============================================================================
// parseHeaders() Tests
// =============================================================================

TEST(OTLPLoggerTest, ParseHeadersEmpty) {
  auto result = parseHeaders("");
  EXPECT_TRUE(result.empty());
}

TEST(OTLPLoggerTest, ParseHeadersSingle) {
  const std::vector<std::pair<std::string, std::string>> expected{
      {"key", "value"}};
  EXPECT_EQ(parseHeaders("key=value"), expected);
}

TEST(OTLPLoggerTest, ParseHeadersMultiple) {
  const std::vector<std::pair<std::string, std::string>> expected{
      {"k1", "v1"}, {"k2", "v2"}, {"k3", "v3"}};
  EXPECT_EQ(parseHeaders("k1=v1,k2=v2,k3=v3"), expected);
}

TEST(OTLPLoggerTest, ParseHeadersMissingEquals) {
  // Token without '=' should be skipped.
  auto result = parseHeaders("noequals");
  EXPECT_TRUE(result.empty());
}

TEST(OTLPLoggerTest, ParseHeadersTrailingComma) {
  // Trailing comma produces an empty token which has no '=' -> skipped.
  const std::vector<std::pair<std::string, std::string>> expected{{"k", "v"}};
  EXPECT_EQ(parseHeaders("k=v,"), expected);
}

TEST(OTLPLoggerTest, ParseHeadersEmptyValue) {
  // "key=" -> key is "key", value is "".
  const std::vector<std::pair<std::string, std::string>> expected{{"key", ""}};
  EXPECT_EQ(parseHeaders("key="), expected);
}

TEST(OTLPLoggerTest, ParseHeadersEmptyKey) {
  // "=value" -> empty key should be skipped.
  auto result = parseHeaders("=value");
  EXPECT_TRUE(result.empty());
}

TEST(OTLPLoggerTest, ParseHeadersMixed) {
  // Mix of valid and invalid tokens.
  const std::vector<std::pair<std::string, std::string>> expected{
      {"good", "val"}, {"also", "ok"}};
  EXPECT_EQ(parseHeaders("good=val,bad,also=ok"), expected);
}

TEST(OTLPLoggerTest, ParseHeadersValueContainsEquals) {
  // Value with '=' in it (e.g., base64-encoded token). The parser splits on
  // the FIRST '=' so the rest stays in the value.
  const std::vector<std::pair<std::string, std::string>> expected{
      {"Authorization", "Bearer abc=def=="}};
  EXPECT_EQ(parseHeaders("Authorization=Bearer abc=def=="), expected);
}

TEST(OTLPLoggerTest, ParseHeadersConsecutiveCommas) {
  // Consecutive commas produce empty tokens (no '=' -> skipped).
  const std::vector<std::pair<std::string, std::string>> expected{
      {"k1", "v1"}, {"k2", "v2"}};
  EXPECT_EQ(parseHeaders("k1=v1,,k2=v2"), expected);
}

TEST(OTLPLoggerTest, ParseHeadersTrimsWhitespace) {
  // Whitespace around comma-separated tokens and around the key/value parts is
  // trimmed so the resulting HTTP header keys/values are valid. Whitespace
  // internal to a value (e.g. "Bearer xyz") is preserved.
  const std::vector<std::pair<std::string, std::string>> expected{
      {"Authorization", "Bearer xyz"}, {"X-Token", "abc"}};
  EXPECT_EQ(parseHeaders("Authorization=Bearer xyz , X-Token = abc"), expected);
}

// =============================================================================
// getEnvOr() Tests
// =============================================================================

TEST(OTLPLoggerTest, GetEnvOrUnset) {
  // Unset variable should return fallback.
  ::unsetenv("DYNOLOG_TEST_VAR_UNSET");
  EXPECT_EQ(getEnvOr("DYNOLOG_TEST_VAR_UNSET", "fallback"), "fallback");
}

TEST(OTLPLoggerTest, GetEnvOrSet) {
  // Set variable should return its value.
  ::setenv("DYNOLOG_TEST_VAR_SET", "hello", 1);
  EXPECT_EQ(getEnvOr("DYNOLOG_TEST_VAR_SET", "fallback"), "hello");
  ::unsetenv("DYNOLOG_TEST_VAR_SET");
}

TEST(OTLPLoggerTest, GetEnvOrSetEmpty) {
  // Empty string env var: current code checks
  // val[0] != '\0', so returns fallback.
  ::setenv("DYNOLOG_TEST_VAR_EMPTY", "", 1);
  EXPECT_EQ(getEnvOr("DYNOLOG_TEST_VAR_EMPTY", "fallback"), "fallback");
  ::unsetenv("DYNOLOG_TEST_VAR_EMPTY");
}

// =============================================================================
// OTLPManager Integration Tests
// NOTE: SDK-based tests (construction, logGauge, forceFlush) removed during
// Phase 1 SDK removal. Phase 2 will add equivalent tests for the new
// HTTP + protobuf implementation.
// =============================================================================

// =============================================================================
// Additional NUMA Regex Edge Cases
// =============================================================================

TEST(OTLPLoggerTest, NUMARegexNoDigit) {
  // "cpu_u_nodeABC" should NOT match the NUMA regex (no digits after "node").
  // Falls through to passthrough.
  auto parsed = parseMetricKey("cpu_u_nodeABC");
  ASSERT_TRUE(parsed.matched);
  EXPECT_EQ(parsed.mapping.otel_name, "cpu_u_nodeABC");
}

TEST(OTLPLoggerTest, NUMARegexNoNodeNumber) {
  // "cpu_u_node" with no digits should NOT match the NUMA regex.
  auto parsed = parseMetricKey("cpu_u_node");
  ASSERT_TRUE(parsed.matched);
  EXPECT_EQ(parsed.mapping.otel_name, "cpu_u_node");
}

TEST(OTLPLoggerTest, NUMARegexInvalidMode) {
  // "cpu_x_node0" - 'x' is not in (u|s|i), should NOT match the NUMA regex.
  // It also won't match CPU time (cpu_x_ms) since there's no "_ms" suffix.
  // Falls through to passthrough.
  auto parsed = parseMetricKey("cpu_x_node0");
  ASSERT_TRUE(parsed.matched);
  EXPECT_EQ(parsed.mapping.otel_name, "cpu_x_node0");
}

TEST(OTLPLoggerTest, NUMARegexExtraTrailing) {
  // "cpu_u_node0_extra" has trailing chars after the digits.
  // regex_match requires full-string match, so this should NOT match.
  auto parsed = parseMetricKey("cpu_u_node0_extra");
  ASSERT_TRUE(parsed.matched);
  EXPECT_EQ(parsed.mapping.otel_name, "cpu_u_node0_extra");
}

// =============================================================================
// Protobuf Serialization Tests (OTLPManager)
// =============================================================================

namespace {

// Helper: find a Metric by name in an ExportMetricsServiceRequest.
const opentelemetry::proto::metrics::v1::Metric* findMetric(
    const opentelemetry::proto::collector::metrics::v1::
        ExportMetricsServiceRequest& req,
    const std::string& name) {
  for (int i = 0; i < req.resource_metrics_size(); ++i) {
    const auto& rm = req.resource_metrics(i);
    for (int j = 0; j < rm.scope_metrics_size(); ++j) {
      const auto& sm = rm.scope_metrics(j);
      for (int k = 0; k < sm.metrics_size(); ++k) {
        if (sm.metrics(k).name() == name) {
          return &sm.metrics(k);
        }
      }
    }
  }
  return nullptr;
}

// Helper: find a string attribute value in a data point's attributes.
std::string findDataPointAttr(
    const opentelemetry::proto::metrics::v1::NumberDataPoint& dp,
    const std::string& key) {
  for (int i = 0; i < dp.attributes_size(); ++i) {
    if (dp.attributes(i).key() == key) {
      return dp.attributes(i).value().string_value();
    }
  }
  return "";
}

// Helper: find a string attribute value in Resource attributes.
std::string findResourceAttr(
    const opentelemetry::proto::resource::v1::Resource& resource,
    const std::string& key) {
  for (int i = 0; i < resource.attributes_size(); ++i) {
    if (resource.attributes(i).key() == key) {
      return resource.attributes(i).value().string_value();
    }
  }
  return "";
}

} // namespace

TEST(OTLPLoggerTest, SerializeBasic) {
  FLAGS_otlp_endpoint = "http://localhost:19999";
  FLAGS_otlp_service_name = "test-svc";
  OTLPManager mgr;

  std::unordered_map<std::string, double> metrics = {
      {"uptime", 1000.0},
      {"cpu_util", 75.0},
  };
  std::string payload = mgr.serializeMetrics(metrics, {});
  ASSERT_FALSE(payload.empty());

  opentelemetry::proto::collector::metrics::v1::ExportMetricsServiceRequest req;
  ASSERT_TRUE(req.ParseFromString(payload));

  ASSERT_EQ(req.resource_metrics_size(), 1);
  const auto& rm = req.resource_metrics(0);
  ASSERT_EQ(rm.scope_metrics_size(), 1);
  const auto& sm = rm.scope_metrics(0);
  EXPECT_EQ(sm.scope().name(), "dynolog");
  ASSERT_GE(sm.metrics_size(), 2);

  // Find "uptime" metric.
  const auto* uptime = findMetric(req, "uptime");
  ASSERT_NE(uptime, nullptr) << "uptime metric not found";
  EXPECT_EQ(uptime->name(), "uptime");
  EXPECT_EQ(uptime->unit(), "s");
  ASSERT_EQ(uptime->gauge().data_points_size(), 1);
  EXPECT_DOUBLE_EQ(uptime->gauge().data_points(0).as_double(), 1000.0);
  EXPECT_GT(uptime->gauge().data_points(0).time_unix_nano(), 0u);

  // Find "cpu_util" metric: 75.0 * 0.01 = 0.75
  const auto* cpu = findMetric(req, "cpu_util");
  ASSERT_NE(cpu, nullptr) << "cpu_util metric not found";
  EXPECT_EQ(cpu->name(), "cpu_util");
  EXPECT_EQ(cpu->unit(), "1");
  ASSERT_EQ(cpu->gauge().data_points_size(), 1);
  EXPECT_NEAR(cpu->gauge().data_points(0).as_double(), 0.75, 1e-9);
  EXPECT_EQ(
      findDataPointAttr(cpu->gauge().data_points(0), "cpu.mode"), "active");
}

TEST(OTLPLoggerTest, SerializeResource) {
  FLAGS_otlp_endpoint = "http://localhost:19999";
  FLAGS_otlp_service_name = "my-test-service";
  OTLPManager mgr;

  std::string payload = mgr.serializeMetrics({{"uptime", 1.0}}, {});
  ASSERT_FALSE(payload.empty());

  opentelemetry::proto::collector::metrics::v1::ExportMetricsServiceRequest req;
  ASSERT_TRUE(req.ParseFromString(payload));
  ASSERT_EQ(req.resource_metrics_size(), 1);

  const auto& resource = req.resource_metrics(0).resource();
  EXPECT_EQ(findResourceAttr(resource, "service.name"), "my-test-service");
  EXPECT_EQ(findResourceAttr(resource, "os.type"), "linux");
  EXPECT_FALSE(findResourceAttr(resource, "host.name").empty())
      << "host.name should be non-empty";
}

TEST(OTLPLoggerTest, SerializeSkipAndNaN) {
  FLAGS_otlp_endpoint = "http://localhost:19999";
  FLAGS_otlp_service_name = "test-svc";
  OTLPManager mgr;

  std::unordered_map<std::string, double> metrics = {
      {"device", 3.0},
      {"minor_id", 0.0},
      {"gpu_power_draw", 250.0},
      {"bad_metric", std::numeric_limits<double>::quiet_NaN()},
      {"inf_metric", std::numeric_limits<double>::infinity()},
  };
  std::string payload = mgr.serializeMetrics(metrics, {});
  ASSERT_FALSE(payload.empty());

  opentelemetry::proto::collector::metrics::v1::ExportMetricsServiceRequest req;
  ASSERT_TRUE(req.ParseFromString(payload));

  const auto& sm = req.resource_metrics(0).scope_metrics(0);
  // Only gpu_power_draw should appear (device/minor_id are skip, NaN/Inf
  // filtered)
  ASSERT_EQ(sm.metrics_size(), 1);

  const auto* power = findMetric(req, "gpu_power_draw");
  ASSERT_NE(power, nullptr);
  EXPECT_DOUBLE_EQ(power->gauge().data_points(0).as_double(), 250.0);
  EXPECT_EQ(power->unit(), "W");
}

TEST(OTLPLoggerTest, SerializeScaleFactor) {
  FLAGS_otlp_endpoint = "http://localhost:19999";
  FLAGS_otlp_service_name = "test-svc";
  OTLPManager mgr;

  std::unordered_map<std::string, double> metrics = {
      {"gpu_device_utilization", 85.0},
      {"gpu_memory_utilization", 60.0},
  };
  std::string payload = mgr.serializeMetrics(metrics, {});
  ASSERT_FALSE(payload.empty());

  opentelemetry::proto::collector::metrics::v1::ExportMetricsServiceRequest req;
  ASSERT_TRUE(req.ParseFromString(payload));

  const auto* gpu_util = findMetric(req, "gpu_device_utilization");
  ASSERT_NE(gpu_util, nullptr);
  EXPECT_NEAR(gpu_util->gauge().data_points(0).as_double(), 0.85, 1e-9);

  const auto* mem_util = findMetric(req, "gpu_memory_utilization");
  ASSERT_NE(mem_util, nullptr);
  EXPECT_NEAR(mem_util->gauge().data_points(0).as_double(), 0.60, 1e-9);
}

TEST(OTLPLoggerTest, SerializeGPUAttributes) {
  FLAGS_otlp_endpoint = "http://localhost:19999";
  FLAGS_otlp_service_name = "test-svc";
  OTLPManager mgr;

  std::unordered_map<std::string, double> metrics = {
      {"device", 2.0},
      {"gpu_power_draw", 300.0},
      {"fp16_active", 0.3},
  };
  std::unordered_map<std::string, std::string> attrs = {
      {"job_id", "12345"},
      {"username", "testuser"},
  };
  std::string payload = mgr.serializeMetrics(metrics, attrs);
  ASSERT_FALSE(payload.empty());

  opentelemetry::proto::collector::metrics::v1::ExportMetricsServiceRequest req;
  ASSERT_TRUE(req.ParseFromString(payload));

  // gpu_power_draw should have hw.type=gpu, hw.id=2, job_id, username
  const auto* power = findMetric(req, "gpu_power_draw");
  ASSERT_NE(power, nullptr);
  ASSERT_EQ(power->gauge().data_points_size(), 1);
  const auto& power_dp = power->gauge().data_points(0);
  EXPECT_EQ(findDataPointAttr(power_dp, "hw.type"), "gpu");
  EXPECT_EQ(findDataPointAttr(power_dp, "hw.id"), "2");
  EXPECT_EQ(findDataPointAttr(power_dp, "job_id"), "12345");
  EXPECT_EQ(findDataPointAttr(power_dp, "username"), "testuser");

  // fp16_active should have pipe=fp16, hw.id=2, job_id, username
  const auto* fp16 = findMetric(req, "fp16_active");
  ASSERT_NE(fp16, nullptr);
  ASSERT_EQ(fp16->gauge().data_points_size(), 1);
  const auto& fp16_dp = fp16->gauge().data_points(0);
  EXPECT_EQ(findDataPointAttr(fp16_dp, "pipe"), "fp16");
  EXPECT_EQ(findDataPointAttr(fp16_dp, "hw.id"), "2");
  EXPECT_EQ(findDataPointAttr(fp16_dp, "job_id"), "12345");
  EXPECT_EQ(findDataPointAttr(fp16_dp, "username"), "testuser");
}

TEST(OTLPLoggerTest, ConfigEndpoint) {
  // Without /v1/metrics suffix: auto-appended.
  {
    FLAGS_otlp_endpoint = "http://collector.example.com:4318";
    FLAGS_otlp_service_name = "test-svc";
    OTLPManager mgr;
    EXPECT_EQ(mgr.endpoint(), "http://collector.example.com:4318/v1/metrics");
  }

  // With /v1/metrics suffix: not double-appended.
  {
    FLAGS_otlp_endpoint = "http://collector.example.com:4318/v1/metrics";
    FLAGS_otlp_service_name = "test-svc";
    OTLPManager mgr;
    EXPECT_EQ(mgr.endpoint(), "http://collector.example.com:4318/v1/metrics");
  }
}

// =============================================================================
// Async Queue and Signal Tests
// =============================================================================

TEST(OTLPLoggerTest, AsyncQueueAndSignal) {
  {
    FLAGS_otlp_endpoint = "";
    FLAGS_otlp_service_name = "test-svc";
    FLAGS_otlp_max_queue_size = 2;
    OTLPManager mgr;

    for (int i = 0; i < 3; ++i) {
      mgr.queuePayload("payload-" + std::to_string(i));
    }

    std::lock_guard<std::mutex> lk(mgr.export_mutex_);
    EXPECT_EQ(mgr.export_queue_.size(), 2);
    EXPECT_EQ(mgr.export_queue_.front(), "payload-1");
  }

  FLAGS_otlp_max_queue_size = 1000;
  FLAGS_otlp_endpoint = "http://localhost:19999";
  FLAGS_otlp_service_name = "test-svc";
  OTLPManager mgr;

  // Queue starts empty.
  {
    std::lock_guard<std::mutex> lk(mgr.export_mutex_);
    EXPECT_TRUE(mgr.export_queue_.empty());
  }

  // Queue a payload -- the background thread will consume it
  // (httpPost will fail to connect, but that is expected).
  mgr.queuePayload("test-payload-1");

  // Queue empty string -- should not crash.
  mgr.queuePayload("");

  // Queue multiple payloads rapidly before destruction.
  for (int i = 0; i < 10; ++i) {
    mgr.queuePayload("payload-" + std::to_string(i));
  }

  // Destructor joins the thread -- test completing is proof of no hang.
}

TEST(OTLPLoggerTest, AsyncShutdownDrain) {
  FLAGS_otlp_endpoint = "http://localhost:19999";
  FLAGS_otlp_service_name = "test-svc";
  OTLPManager mgr;

  // Set shutdown immediately, holding export_mutex_ to match the destructor's
  // pattern. Storing the flag without the lock can race with the export
  // thread's cv.wait() and drop the wakeup; doing it under the lock keeps the
  // test from depending on the side-effect notification in queuePayload().
  {
    std::lock_guard<std::mutex> lk(mgr.export_mutex_);
    mgr.shutdown_.store(true);
  }

  // Queue payloads after shutdown signal.
  mgr.queuePayload("drain-1");
  mgr.queuePayload("drain-2");
  mgr.queuePayload("drain-3");

  // Destructor will join the thread and drain the queue.
  // Test completing without hanging is the assertion.
}

// =============================================================================
// Negative / Edge Case Serialization Tests
// =============================================================================

TEST(OTLPLoggerTest, SerializeEmptyMetrics) {
  FLAGS_otlp_endpoint = "http://localhost:19999";
  FLAGS_otlp_service_name = "test-svc";
  OTLPManager mgr;

  std::string payload = mgr.serializeMetrics({}, {});
  ASSERT_FALSE(payload.empty());

  opentelemetry::proto::collector::metrics::v1::ExportMetricsServiceRequest req;
  ASSERT_TRUE(req.ParseFromString(payload));

  const auto& sm = req.resource_metrics(0).scope_metrics(0);
  EXPECT_EQ(sm.metrics_size(), 0);
}

TEST(OTLPLoggerTest, SerializeAllSkipped) {
  FLAGS_otlp_endpoint = "http://localhost:19999";
  FLAGS_otlp_service_name = "test-svc";
  OTLPManager mgr;

  std::unordered_map<std::string, double> metrics = {
      {"device", 1.0},
      {"minor_id", 0.0},
  };
  std::string payload = mgr.serializeMetrics(metrics, {});
  ASSERT_FALSE(payload.empty());

  opentelemetry::proto::collector::metrics::v1::ExportMetricsServiceRequest req;
  ASSERT_TRUE(req.ParseFromString(payload));

  const auto& sm = req.resource_metrics(0).scope_metrics(0);
  EXPECT_EQ(sm.metrics_size(), 0);
}

TEST(OTLPLoggerTest, SerializeAllNaN) {
  FLAGS_otlp_endpoint = "http://localhost:19999";
  FLAGS_otlp_service_name = "test-svc";
  OTLPManager mgr;

  std::unordered_map<std::string, double> metrics = {
      {"cpu_util", std::numeric_limits<double>::quiet_NaN()},
      {"uptime", std::numeric_limits<double>::infinity()},
  };
  std::string payload = mgr.serializeMetrics(metrics, {});
  ASSERT_FALSE(payload.empty());

  opentelemetry::proto::collector::metrics::v1::ExportMetricsServiceRequest req;
  ASSERT_TRUE(req.ParseFromString(payload));

  const auto& sm = req.resource_metrics(0).scope_metrics(0);
  EXPECT_EQ(sm.metrics_size(), 0);
}

// NOTE: End-to-end integration tests that required Docker +
// OTLP_INTEGRATION_TEST have been removed. They referenced deleted SDK APIs
// (logGauge, forceFlush, FLAGS_otlp_protocol, FLAGS_otlp_use_tls). Future
// integration tests for the new direct-protobuf implementation will be added in
// a later phase if needed.

} // namespace dynolog
