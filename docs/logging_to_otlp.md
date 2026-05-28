# Logging to OTLP (OpenTelemetry Protocol)

Dynolog supports exporting metrics via the [OpenTelemetry Protocol (OTLP)](https://opentelemetry.io/docs/specs/otlp/), enabling integration with any OTLP-compatible observability backend such as Grafana (via OTEL Collector), Datadog, New Relic, Honeycomb, Splunk, and others.

## Building with OTLP Support

OTLP support uses the [opentelemetry-proto](https://github.com/open-telemetry/opentelemetry-proto) definitions to generate C++ protobuf stubs, and libcurl for HTTP transport. To build dynolog with OTLP enabled:

```bash
# Using the build script
BUILD_OTLP=1 ./scripts/build.sh

# Or manually with cmake
git submodule update --init -- third_party/opentelemetry-proto
mkdir -p build && cd build
cmake -DUSE_OTLP=ON -DCMAKE_BUILD_TYPE=Release -G Ninja ..
cmake --build .
```

## Configuration

### Command Line Flags

| Flag | Default | Description |
| --- | --- | --- |
| `--use_otlp` | `false` | Enable OTLP metrics export |
| `--otlp_endpoint` | `""` | OTLP HTTP endpoint (e.g., `http://localhost:4318/v1/metrics`). The `/v1/metrics` path is appended automatically if not present. TLS is inferred from `https://` URL scheme. |
| `--otlp_service_name` | `dynolog` | Service name reported in OTLP resource attributes |
| `--otlp_headers` | `""` | Custom headers as `key1=value1,key2=value2` (for authentication tokens, etc.) |
| `--otlp_timeout_ms` | `30000` | Export timeout in milliseconds |
| `--otlp_max_queue_size` | `1000` | Maximum number of serialized OTLP payloads to buffer; oldest payloads are dropped when the queue is full |
| `--otlp_export_interval_ms` | `60000` | Periodic export interval in milliseconds |
| `--otlp_ssl_ca_cert_path` | `""` | Path to CA certificate file for verifying the OTLP server |
| `--otlp_ssl_client_cert_path` | `""` | Path to client certificate file for mTLS authentication |
| `--otlp_ssl_client_key_path` | `""` | Path to client private key file for mTLS authentication |

### Environment Variable Overrides

The following standard OpenTelemetry environment variables take precedence over command line flags:

| Environment Variable | Overrides Flag |
| --- | --- |
| `OTEL_EXPORTER_OTLP_ENDPOINT` | `--otlp_endpoint` |
| `OTEL_SERVICE_NAME` | `--otlp_service_name` |

### Resource Attributes

The following resource attributes are automatically set on all exported metrics:

| Attribute | Value |
| --- | --- |
| `service.name` | From `--otlp_service_name` flag (default: `dynolog`) |
| `service.version` | Compile-time version from `version.txt` |
| `host.name` | System hostname |
| `os.type` | `linux` |

## Usage Examples

### Basic: Export to local OTEL Collector

```bash
dynolog --use_otlp --otlp_endpoint=http://localhost:4318
```

### Export with authentication header

```bash
dynolog --use_otlp --otlp_endpoint=https://otlp.example.com:4318 \
  --otlp_headers="Authorization=Bearer mytoken"
```

### Export with mTLS

```bash
dynolog --use_otlp --otlp_endpoint=https://otlp.example.com:4318 \
  --otlp_ssl_ca_cert_path=/etc/ssl/ca.pem \
  --otlp_ssl_client_cert_path=/etc/ssl/client.pem \
  --otlp_ssl_client_key_path=/etc/ssl/client-key.pem
```

### Using environment variables

```bash
export OTEL_EXPORTER_OTLP_ENDPOINT=http://collector:4318
export OTEL_SERVICE_NAME=dynolog-gpu-node-01
dynolog --use_otlp --enable_gpu_monitor
```

### Combined with other loggers

OTLP can be used alongside other loggers (Prometheus, JSON, etc.):

```bash
dynolog --use_otlp --otlp_endpoint=http://localhost:4318 \
  --use_prometheus --use_JSON
```

### With systemd

```bash
echo "--use_otlp" | sudo tee -a /etc/dynolog.gflags
echo "--otlp_endpoint=http://collector:4318" | sudo tee -a /etc/dynolog.gflags
sudo systemctl restart dynolog
```

## Metric Naming

Dynolog preserves its native metric names in the OTLP export while adding OTEL-style attributes and unit normalization. This keeps metric names familiar to dynolog users while enabling attribute-based filtering in OTLP-compatible backends.

For the complete metric mapping table, see [Metrics.md](Metrics.md#otlp-metric-naming).

### Key Conversions

- **CPU utilization percentages** (e.g., `cpu_util=75.0`) are converted to ratios (`cpu_util=0.75`) with `cpu.mode` attributes decomposed from the metric name.
- **Network metrics** (e.g., `rx_bytes.eth0`) are exported with the base name (`rx_bytes`) and `network.io.direction` and `network.interface.name` attributes.
- **GPU metrics** are tagged with `hw.id` for device identification and Slurm attribution labels (`job_id`, `username`, etc.) when available.
- **Unknown metrics** are passed through with their raw name (e.g., `custom_metric` is exported as `custom_metric`).

## Architecture

The OTLP logger consists of two components:

1. **OTLPLogger**: Implements the `Logger` interface. Accumulates metric values via `logInt()`/`logFloat()`/`logUint()` calls, then on `finalize()` serializes them to an OTLP protobuf and queues for async export.

2. **OTLPManager**: Thread-safe singleton that owns configuration, protobuf serialization, and a background export thread. Metrics are serialized to `ExportMetricsServiceRequest` protobuf and POSTed via libcurl to the configured endpoint. Shared across the three collector threads (kernel, perf, GPU) via `CompositeLogger`. The async queue is bounded by `--otlp_max_queue_size`; when full, dynolog drops the oldest serialized payload and keeps the newest payload.
