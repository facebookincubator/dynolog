# Logging to Scuba

[Scuba](https://research.facebook.com/publications/scuba-diving-into-data-at-facebook/) is the data management system Meta uses for most real-time analysis. Scuba is a fast, scalable, distributed, in-memory database built at Meta, and supports logging from the public internet through Graph API. The open source Dynolog supports a Graph API based Scuba Logger with user specified access token and certificate.

## Scuba Table and Scribe Category

Scuba listens to [Scribe](https://engineering.fb.com/2019/10/07/data-infrastructure/scribe/), a distributed, buffered queueing system for data ingestion. To create a Scuba table, we first need to register a Scribe category that Scuba will listen to, the scribe category name will be following perfpipe_<scuba_table_name>.

Scuba will listen to the scribe category and dynamically generates the Scuba table schema based on the data schema it receives.

# How to enable Scuba logging

To enable Scuba logging, users will need to obtain an access token and category id, create a scribe category, and passes these through the required gflags, set the --use_scuba flag to true, and pass in the scribe category name with --scribe_category flag.

## Supported/Required Gflags

* `--use_scuba` (default=false): enable Scuba logging.
* `--access_token` (required): the access token string to validate the Graph API access.
* `--category_id` (required): the category id the Scuba logger belongs to, used for admission control and identifying data owners.
* `--certificate_path` (default=/etc/ssl/certs/ca-certificates.crt): path to the SSL certificate on the host that the Scuba logger runs on.
* `--scribe_category` (required): the scribe category name that sends data and generates the Scuba table.
