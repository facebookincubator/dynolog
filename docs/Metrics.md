# Metric Definitions

## Concepts
We define a metric as a quantity measured over a given period of time. The time aspect may be crucial because each value measured has an associated time range `[time_start, duration]`. In some cases however, metrics can have instantaneous values as described below.

### Types of metrics
* **Delta metrics:** are changes in a quantity over a given time interval. Examples include the number of bytes transferred over a port. Each delta must have an associated time period to make it meaningful. (100MB was transferred over the network; in how much time?) We can also report these metrics as cumulative values, like 1000GB of total bytes were transferred by XYZ time. Deltas can be calculated by subtracting successive values.
* **Instantaneous metrics:** some metrics can have instantaneous values; this is typical for capacity metrics like the amount of memory used.
* **Ratio metrics:** are useful for measuring the utilization of a unit or component. For example, a cpu core was utilized 50% on average over the last minute.
* **Rate metrics:** are divided by the time interval of measurement. We still need to be aware about the interval over which the rate is averaged. For example, the bytes/sec measured every second vs every minute may have totally different values. The average over a second can have more variation than average over a minute.

### Scopes
A metric is generally associated with a scope that describes the space/dimension it covers. Examples of scope include: server, GPU devices, NIC card etc.

## CPU/System Metrics
| Metric | Description | What does it tell? | Type | Unit | Collection Interval |
| ----------- | ----------- |----------- |----------- |----------- |----------- |
| uptime | System uptime | How long the system has been running. | Instant | s | 60s |
| cpu_util | Fraction of total CPU time spend on user or system mode.| Overall amount of time the CPU was busy. | Ratio | - | 60s |
| cpu_u, cpu_s | Fraction of total CPU time spent in user and system mode respectively| Activity of the system CPU in user/system mode. | Ratio | - | 60s |
| cpu_i| Fraction of total CPU time that the CPU was in idle mode.| Overall inactivity of the system CPU. | Ratio | - | 60s |
| cpu_guest, cpu_guest_nice | Fraction of total CPU time spent running a virtual CPU for guest OS. | Guest/virtualization CPU overhead. | Ratio | - | 60s |
| cpu_u/s/n/w/x/y_ms| Total CPU time in milliseconds spent in various modes: user, system, nice, iowait etc. For more details please see man page for [/proc/stat](https://man7.org/linux/man-pages/man5/proc.5.html) | Activity of the system CPU in various modes. | Delta | ms | 60s |
| rx/tx_bytes.`<devname>` | Total bytes transmitted/received over the specific network device.| Network transfer statistics. | Delta | Bytes | 60s |
| rx/tx_packets.`<devname>` | Total packets transmitted/received over the specific network device.| Network transfer statistics. | Delta | Packets | 60s |
| rx/tx_errors.`<devname>` | Total transmit/receive errors on the specific network device.| Network transfer statistics. | Delta | Errors | 60s |
| rx/tx_drops.`<devname>` | Total transmit/receive packet drops on the specific network device.| Network transfer statistics. | Delta | Packets | 60s |
| mips | Number of million instructions executed per second. | Overall rate of instructions per second the CPU executed. | Rate | Million / sec | 60s |
| mega_cycles_per_second | Number of active CPU clock cycles per second. | Overall rate of the CPU clock cycle. | Rate | MHz | 60s |

## GPU Metrics
| Metric | Description | What does it tell? | Type | Unit | Collection Interval |
| ----------- | ----------- |----------- |----------- |----------- |----------- |
| graphics_engine_active_ratio | Ratio of time the graphics/compute engine is active | A coarse metric showing whether the gpu doing active work | Ratio | - | 10s |
| sm_active_ratio | Ratio of active SMs (streaming multiprocessor) | GPU usage at SM level | Ratio | - | 10s |
| sm_occupancy | Ratio of active warps | GPU usage at warps level | Ratio | - | 10s |
| gpu_frequency_mhz | SM clock of the GPU device | The frequency of the SM | Frequency | Mega Hertz | 10s |
| fp16_active | Ratio of cycles the fp16 pipe is active | fp16 compute pipe active ratio | Ratio | - | 10s |
| fp32_active | Ratio of cycles the fp32 pipe is active | fp32 compute pipe active ratio | Ratio | - | 10s |
| fp64_active | Ratio of cycles the fp64 pipe is active | fp64 compute pipe active ratio | Ratio | - | 10s |
| tensorcore_active | Ratio of cycles the tensor pipe is active | tensor compute pipe active ratio | Ratio | - | 10s |
| hbm_mem_bw_util | Ratio of cycles the high performance memory interface is active | Percentage of GPU memory bandwidth | Ratio | - | 10s |
| pcie_tx_bytes | Rate of transmitted bytes (bandwidth) over Pcie during the sampling interval | Pcie tx bandwidth | Bandwidth | Bytes/sec | 10s |
| pcie_rx_bytes | Rate of received bytes (bandwidth) over Pcie during the sampling interval | Pcie rx bandwidth | Bandwidth | Bytes/sec | 10s |
| nvlink_tx_bytes | Rate of transmitted bytes (bandwidth) on Nvlink during the sampling interval | NVLink tx bandwidth | Bandwidth | Bytes/sec | 10s |
| nvlink_rx_bytes | Rate of received bytes (bandwidth) on Nvlink during the sampling interval | NVLink rx bandwidth | Bandwidth | Bytes/sec | 10s |
| minor_id | Minor id of the device | Linux minor id of the device | ID | - | 10s |
| gpu_device_utilization | GPU Device utilization | The most coarse signal showing the GPU is active | Ratio | - | 10s |
| gpu_memory_utilization | Memory utilization of the GPU device | Ratio of GPU memory being allocated | Ratio | - | 10s |
| gpu_power_draw | Power of the device | How much power the GPU is consuming, also reflects how heavy the GPU is used | Power | Watt | 10s |
| dcgm_error | DCGM hardware error count | Number of DCGM-reported hardware errors for the device | Delta | Count | 10s |

## AMD GPU Metrics
Collected when `--enable_gpu_monitor` is set on a host with AMD GPUs and dynolog was built with `USE_AMD_GPU`. Keys shared with the NVIDIA table above have the same meaning and unit.

Metrics come from three sources, set up in order at startup; a source that fails to initialize is skipped:
1. **KFD and PCI sysfs** (`/sys/class/kfd`, `/sys/bus/pci/drivers/amdgpu`): the list of logical devices and their `kfd_id`, `minor_id` and `oam_id`. Always used.
2. **AMD SMI**: utilization, power, clock, memory, temperature and PCIe.
3. **ROCm RDC** (`--enable_amd_rdc`): profiling metrics, listed below. RDC initializes AMD SMI itself and aborts dynolog at startup if that fails.

When AMD SMI and RDC both report `gpu_device_utilization`, `gpu_power_draw` or `pcie_total_bytes`, the AMD SMI value is used and RDC's is the fallback.

One record is emitted per logical device, with `device` set to its KFD node id; devices with no metrics in a cycle are left out. A partitioned GPU (for example DPX or CPX compute partitioning) emits one record per partition: the records share `oam_id`, have distinct `partition_id`, and report the same GPU-wide values for memory, power, clock, temperature, PCIe, HBM and XGMI. `gpu_device_utilization` and the RDC compute metrics are per partition.

| Metric | Description | What does it tell? | Type | Unit | Collection Interval |
| ----------- | ----------- |----------- |----------- |----------- |----------- |
| gpu_device_utilization | Average gfx activity of the partition's compute dies | The most coarse signal showing the GPU is active | Ratio | Percent | 10s |
| gpu_power_draw | Current socket power | How much power the GPU is consuming | Power | Watt | 10s |
| gpu_power_limit | Power cap of the GPU | The power budget the GPU is throttled against | Power | Watt | 10s |
| gpu_frequency_mhz | Current system (gfx) clock | The frequency of the compute units | Frequency | Mega Hertz | 10s |
| gpu_memory_total_bytes | Total VRAM of the GPU | Memory capacity | Size | Bytes | 10s |
| gpu_memory_used_bytes | Used VRAM of the GPU | Memory allocated on the device | Size | Bytes | 10s |
| gpu_temperature_hotspot_c | Hotspot (junction) temperature | Whether the GPU is near its thermal limit | Temperature | Celsius | 10s |
| pcie_total_bytes | Instantaneous PCIe bandwidth, rx + tx | Pcie bandwidth. Known issue: on MI300X/MI350X this currently reads close to the idle floor (~2 MB/s) under load | Bandwidth | Bytes/sec | 10s |
| oam_id | OAM id of the physical GPU | Groups partitions of one GPU | ID | - | 10s |
| partition_id | Compute partition id within the GPU, from AMD SMI | 0 for unpartitioned GPUs | ID | - | 10s |
| kfd_id | KFD GPU id of the logical device (`/sys/class/kfd/kfd/topology/nodes/*/gpu_id`) | Correlates with KFD and ROCm tools | ID | - | 10s |
| minor_id | DRM render minor of the logical device | Linux minor id of the device | ID | - | 10s |
| gpu_name | GPU model name | e.g. `AMD Instinct MI300X OAM` | String | - | 10s |

### AMD RDC profiling metrics
Added to the same AMD records when RDC is enabled. Compute metrics are per partition on partitioned GPUs. HBM and XGMI bandwidth are GPU-wide and repeated on every partition.

| Metric | Description | What does it tell? | Type | Unit | Collection Interval |
| ----------- | ----------- |----------- |----------- |----------- |----------- |
| sm_occupancy | Average wave occupancy of the compute units (RDC_FI_PROF_OCCUPANCY_PERCENT / 100) | GPU usage at wave level | Ratio | - | 10s |
| graphics_engine_active_ratio | Active cycles over elapsed cycles | A coarse metric showing whether the GPU is doing active work | Ratio | - | 10s |
| simd_utilization | SIMD utilization | GPU usage at SIMD level | Ratio | - | 10s |
| fp16_flops_per_sec | FP16 operations per second | fp16 compute throughput | Rate | FLOP/sec | 10s |
| fp32_flops_per_sec | FP32 operations per second | fp32 compute throughput | Rate | FLOP/sec | 10s |
| fp64_flops_per_sec | FP64 operations per second | fp64 compute throughput | Rate | FLOP/sec | 10s |
| hbm_read_bytes | HBM read bandwidth | Memory read bandwidth | Bandwidth | Bytes/sec | 10s |
| hbm_write_bytes | HBM write bandwidth | Memory write bandwidth | Bandwidth | Bytes/sec | 10s |
| hbm_mem_bw_util | (hbm_read_bytes + hbm_write_bytes) over the datasheet peak (5.3 TB/s MI300X, 8 TB/s MI350X/MI355X); unset for other models | Percentage of GPU memory bandwidth | Ratio | - | 10s |
| xgmi_rx_bytes | XGMI receive bandwidth, all links, averaged since the previous cycle | GPU-to-GPU rx bandwidth | Bandwidth | Bytes/sec | 10s |
| xgmi_tx_bytes | XGMI transmit bandwidth, all links, averaged since the previous cycle | GPU-to-GPU tx bandwidth | Bandwidth | Bytes/sec | 10s |

## OTLP Metric Naming

When using the OTLP logger (`--use_otlp`), dynolog preserves its native metric names in the OTLP export while adding OTEL-style attributes and unit normalization. This keeps metric names familiar to dynolog users while enabling attribute-based filtering in OTLP-compatible backends.

### CPU/System Metric Mapping
| Dynolog Metric | Exported Name | OTEL Unit | OTEL Type | Attributes | Notes |
| --- | --- | --- | --- | --- | --- |
| cpu_util | cpu_util | 1 | Gauge | cpu.mode=active | Divided by 100 (% to ratio) |
| cpu_u | cpu_u | 1 | Gauge | cpu.mode=user | Divided by 100 |
| cpu_s | cpu_s | 1 | Gauge | cpu.mode=system | Divided by 100 |
| cpu_i | cpu_i | 1 | Gauge | cpu.mode=idle | Divided by 100 |
| cpu_guest | cpu_guest | 1 | Gauge | cpu.mode=guest | Divided by 100 |
| cpu_guest_nice | cpu_guest_nice | 1 | Gauge | cpu.mode=guest_nice | Divided by 100 |
| cpu_u_node{N} | cpu_u_node{N} | 1 | Gauge | cpu.mode=user, cpu.socket={N} | Divided by 100; per-NUMA-socket |
| cpu_s_node{N} | cpu_s_node{N} | 1 | Gauge | cpu.mode=system, cpu.socket={N} | Divided by 100; per-NUMA-socket |
| cpu_i_node{N} | cpu_i_node{N} | 1 | Gauge | cpu.mode=idle, cpu.socket={N} | Divided by 100; per-NUMA-socket |
| cpu_u_ms | cpu_u_ms | s | Gauge | cpu.mode=user | |
| cpu_s_ms | cpu_s_ms | s | Gauge | cpu.mode=system | |
| cpu_n_ms | cpu_n_ms | s | Gauge | cpu.mode=nice | |
| cpu_w_ms | cpu_w_ms | s | Gauge | cpu.mode=iowait | |
| cpu_x_ms | cpu_x_ms | s | Gauge | cpu.mode=irq | |
| cpu_y_ms | cpu_y_ms | s | Gauge | cpu.mode=softirq | |
| cpu_z_ms | cpu_z_ms | s | Gauge | cpu.mode=steal | |
| cpu_guest_ms | cpu_guest_ms | s | Gauge | cpu.mode=guest | |
| cpu_guest_nice_ms | cpu_guest_nice_ms | s | Gauge | cpu.mode=guest_nice | |
| uptime | uptime | s | Gauge | | |
| mips | mips | | Gauge | | Passthrough (value is millions of instructions/s) |
| mega_cycles_per_second | mega_cycles_per_second | | Gauge | | Passthrough (value is millions of cycles/s) |

### Network Metric Mapping
| Dynolog Metric | Exported Name | OTEL Unit | OTEL Type | Attributes |
| --- | --- | --- | --- | --- |
| rx_bytes.{dev} | rx_bytes | By | Gauge | network.io.direction=receive, network.interface.name={dev} |
| tx_bytes.{dev} | tx_bytes | By | Gauge | network.io.direction=transmit, network.interface.name={dev} |
| rx_packets.{dev} | rx_packets | {packet} | Gauge | network.io.direction=receive, network.interface.name={dev} |
| tx_packets.{dev} | tx_packets | {packet} | Gauge | network.io.direction=transmit, network.interface.name={dev} |
| rx_errors.{dev} | rx_errors | {error} | Gauge | network.io.direction=receive, network.interface.name={dev} |
| tx_errors.{dev} | tx_errors | {error} | Gauge | network.io.direction=transmit, network.interface.name={dev} |
| rx_drops.{dev} | rx_drops | {packet} | Gauge | network.io.direction=receive, network.interface.name={dev} |
| tx_drops.{dev} | tx_drops | {packet} | Gauge | network.io.direction=transmit, network.interface.name={dev} |

### GPU Metric Mapping
GPU metrics preserve their dynolog names in the OTLP export. The `hw.id` attribute identifies the GPU device.

| Dynolog Metric | Exported Name | OTEL Unit | Additional Attributes | Notes |
| --- | --- | --- | --- | --- |
| graphics_engine_active_ratio | graphics_engine_active_ratio | 1 | hw.gpu.task=general | |
| sm_active_ratio | sm_active_ratio | 1 | | |
| sm_occupancy | sm_occupancy | 1 | | |
| gpu_frequency_mhz | gpu_frequency_mhz | MHz | | |
| fp16_active | fp16_active | 1 | pipe=fp16 | |
| fp32_active | fp32_active | 1 | pipe=fp32 | |
| fp64_active | fp64_active | 1 | pipe=fp64 | |
| tensorcore_active | tensorcore_active | 1 | pipe=tensorcore | |
| hbm_mem_bw_util | hbm_mem_bw_util | 1 | | |
| pcie_tx_bytes | pcie_tx_bytes | By/s | direction=transmit | |
| pcie_rx_bytes | pcie_rx_bytes | By/s | direction=receive | |
| nvlink_tx_bytes | nvlink_tx_bytes | By/s | direction=transmit | |
| nvlink_rx_bytes | nvlink_rx_bytes | By/s | direction=receive | |
| gpu_device_utilization | gpu_device_utilization | 1 | hw.gpu.task=device | Divided by 100 (% to ratio) |
| gpu_memory_utilization | gpu_memory_utilization | 1 | | Divided by 100 (% to ratio) |
| gpu_power_draw | gpu_power_draw | W | hw.type=gpu | |
| dcgm_error | dcgm_error | {error} | hw.type=gpu | |
| gpu_power_limit | gpu_power_limit | W | hw.type=gpu | AMD only |
| gpu_memory_total_bytes | gpu_memory_total_bytes | By | | AMD only |
| gpu_memory_used_bytes | gpu_memory_used_bytes | By | | AMD only |
| gpu_temperature_hotspot_c | gpu_temperature_hotspot_c | Cel | | AMD only |
| pcie_total_bytes | pcie_total_bytes | By/s | direction=total | AMD only |
| simd_utilization | simd_utilization | 1 | | AMD RDC only |
| fp16_flops_per_sec | fp16_flops_per_sec | {flop}/s | pipe=fp16 | AMD RDC only |
| fp32_flops_per_sec | fp32_flops_per_sec | {flop}/s | pipe=fp32 | AMD RDC only |
| fp64_flops_per_sec | fp64_flops_per_sec | {flop}/s | pipe=fp64 | AMD RDC only |
| hbm_read_bytes | hbm_read_bytes | By/s | direction=read | AMD RDC only |
| hbm_write_bytes | hbm_write_bytes | By/s | direction=write | AMD RDC only |
| xgmi_rx_bytes | xgmi_rx_bytes | By/s | direction=receive | AMD RDC only |
| xgmi_tx_bytes | xgmi_tx_bytes | By/s | direction=transmit | AMD RDC only |

`oam_id`, `partition_id` and `kfd_id` are not exported as metrics.

### ARM Hardware Counter Metric Mapping
ARM hardware counter metrics preserve their dynolog names in the OTLP export. These metrics use attributes to distinguish TLB levels, operation types, and other hardware event characteristics.

> **Note:** These metrics are only available on ARM Neoverse V2 hosts with hardware performance counter monitoring enabled.

| Dynolog Metric | Exported Name | OTEL Unit | Attributes | Description |
| --- | --- | --- | --- | --- |
| l1d_tlb | l1d_tlb | {event} | level=l1d, type=access | L1 data TLB accesses |
| l1d_tlb_refill | l1d_tlb_refill | {event} | level=l1d, type=miss | L1 data TLB misses |
| l1i_tlb | l1i_tlb | {event} | level=l1i, type=access | L1 instruction TLB accesses |
| l1i_tlb_refill | l1i_tlb_refill | {event} | level=l1i, type=miss | L1 instruction TLB misses |
| l2d_tlb | l2d_tlb | {event} | level=l2, type=access | L2 unified TLB accesses |
| l2d_tlb_refill | l2d_tlb_refill | {event} | level=l2, type=miss | L2 unified TLB misses |
| stall_backend_mem | stall_backend_mem | {cycle} | reason=backend_mem | Backend memory stall cycles |
| ll_cache_miss_rd | ll_cache_miss_rd | {event} | level=ll | Last-level cache read misses |
| br_mis_pred | br_mis_pred | {event} | — | Branch mispredictions |
| br_retired | br_retired | {instruction} | — | Branch instructions retired |
| l1i_cache_refill | l1i_cache_refill | {event} | level=l1i, type=miss | L1 instruction cache refills (misses) |
| l1d_cache_refill | l1d_cache_refill | {event} | level=l1d, type=miss | L1 data cache refills (misses) |
| l2d_cache_refill | l2d_cache_refill | {event} | level=l2, type=miss | L2 data cache refills (misses) |
| l3d_cache_refill | l3d_cache_refill | {event} | level=l3, type=miss | L3 data cache refills (misses) |
| FP_HP_SPEC | FP_HP_SPEC | {operation} | precision=half | Half-precision floating-point operations (speculative) |
| FP_SP_SPEC | FP_SP_SPEC | {operation} | precision=single | Single-precision floating-point operations (speculative) |
| FP_DP_SPEC | FP_DP_SPEC | {operation} | precision=double | Double-precision floating-point operations (speculative) |
| dtlb_walk | dtlb_walk | {event} | type=data | Data TLB page table walks |
| itlb_walk | itlb_walk | {event} | type=instruction | Instruction TLB page table walks |

For detailed setup instructions, see [docs/logging_to_otlp.md](logging_to_otlp.md).
