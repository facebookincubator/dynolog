# Logging to ODS

Meta's Operational Data Store (ODS) system supports logging from the public internet through Graph API. The open source Dynolog supports a Graph API based ODS Logger with user specified access token and certificate.

## Entity and Keys

ODS timeseries are uniquely identified by (entity, key) pair. Each entity represents a device on the host, each key represents a metric reported from the host. Every sampling interval, Dynolog will log the metrics as ((entity, keys), value) pairs and ODS will present them as timeseries.

The entity name is constructed as <ods_entity_prefix>hostname.gpu.<device_id>. The keys are constructed as dynolog.<metric_name>. A detailed list of supported metric names can be found at docs/Metrics.md.

# How to enable ODS logging

To enable ODS logging, users will need to obtain an access token and category id, and passes these through the required gflags, and set the --use_ODS flag to true.

## Supported/Required Gflags

* `--use_ODS` (default=false): enable ODS logging.
* `--access_token` (required): the access token string to validate the Graph API access.
* `--category_id` (required): the category id the ODS logger belongs to, used for admission control and identifying data owners.
* `--certificate_path` (default=/etc/ssl/certs/ca-certificates.crt): path to the SSL certificate on the host that the ODS logger runs on.
* `--ods_entity_prefix` (optional): the ODS entity prefix before the hostname.
