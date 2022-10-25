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
| m | desc | desc | Ratio | - | 60s |
| m | desc | desc | Ratio | - | 60s |

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
