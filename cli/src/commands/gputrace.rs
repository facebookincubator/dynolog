// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

use std::net::TcpStream;

use anyhow::Result;
use serde_json::Value;

#[path = "utils.rs"]
mod utils;

// This module contains the handling logic for dyno gputrace

#[derive(Debug)]
pub enum GpuTraceTriggerConfig {
    DurationBased {
        profile_start_time: u64,
        duration_ms: u64,
    },
    IterationBased {
        profile_start_iteration_roundup: u64,
        iterations: i64,
    },
}

impl GpuTraceTriggerConfig {
    fn config(&self) -> String {
        match *self {
            GpuTraceTriggerConfig::DurationBased {
                profile_start_time,
                duration_ms,
            } => format!(
                "PROFILE_START_TIME={}\nACTIVITIES_DURATION_MSECS={}",
                profile_start_time, duration_ms
            ),
            GpuTraceTriggerConfig::IterationBased {
                profile_start_iteration_roundup,
                iterations,
            } => format!(
                r#"PROFILE_START_ITERATION=0
PROFILE_START_ITERATION_ROUNDUP={}
ACTIVITIES_ITERATIONS={}"#,
                profile_start_iteration_roundup, iterations
            ),
        }
    }
}

#[derive(Debug)]
pub struct GpuTraceOptions {
    pub record_shapes: bool,
    pub profile_memory: bool,
    pub with_stacks: bool,
    pub with_flops: bool,
    pub with_modules: bool,
}

impl GpuTraceOptions {
    fn config(&self) -> String {
        format!(
            r#"
PROFILE_REPORT_INPUT_SHAPES={}
PROFILE_PROFILE_MEMORY={}
PROFILE_WITH_STACK={}
PROFILE_WITH_FLOPS={}
PROFILE_WITH_MODULES={}"#,
            self.record_shapes,
            self.profile_memory,
            self.with_stacks,
            self.with_flops,
            self.with_modules
        )
    }
}

#[derive(Debug)]
pub struct GpuTraceConfig {
    pub log_file: String,
    pub trigger_config: GpuTraceTriggerConfig,
    pub trace_options: GpuTraceOptions,
}

impl GpuTraceConfig {
    fn config(&self) -> String {
        format!(
            "ACTIVITIES_LOG_FILE={}\n{}{}",
            self.log_file,
            self.trigger_config.config(),
            self.trace_options.config()
        )
    }
}

/// Gputrace command triggers GPU profiling on pytorch apps
pub fn run_gputrace(
    client: TcpStream,
    job_id: u64,
    pids: &str,
    process_limit: u32,
    config: GpuTraceConfig,
) -> Result<()> {
    let kineto_config = config.config();
    println!("Kineto config = \n{}", kineto_config);
    let kineto_config = kineto_config.replace('\n', "\\n");

    let request_json = format!(
        r#"
{{
    "fn": "setKinetOnDemandRequest",
    "config": "{}",
    "job_id": {},
    "pids": [{}],
    "process_limit": {}
}}"#,
        kineto_config, job_id, pids, process_limit
    );

    utils::send_msg(&client, &request_json).expect("Error sending message to service");

    let resp_str = utils::get_resp(&client).expect("Unable to decode output bytes");

    println!("response = {}", resp_str);

    let resp_v: Value = serde_json::from_str(&resp_str)?;
    let processes = resp_v["processesMatched"].as_array().unwrap();

    if processes.is_empty() {
        println!("No processes were matched, please check --job-id or --pids flags");
    } else {
        println!("Matched {} processes", processes.len());
        println!("Trace output files will be written to:");

        for pid in processes {
            let pid = pid.as_i64().unwrap();
            println!(
                "    {}",
                config.log_file.replace(".json", &format!("_{}.json", pid))
            );
        }
    }

    Ok(())
}

#[cfg(test)]
mod tests {
    use crate::*;

    #[test]
    fn test_gputrace_trigger_config() {
        let trigger_config = GpuTraceTriggerConfig::DurationBased {
            profile_start_time: 1000,
            duration_ms: 42,
        };
        assert_eq!(
            trigger_config.config(),
            r#"PROFILE_START_TIME=1000
ACTIVITIES_DURATION_MSECS=42"#
        );

        let trigger_config = GpuTraceTriggerConfig::IterationBased {
            profile_start_iteration_roundup: 1000,
            iterations: 42,
        };
        assert_eq!(
            trigger_config.config(),
            r#"PROFILE_START_ITERATION=0
PROFILE_START_ITERATION_ROUNDUP=1000
ACTIVITIES_ITERATIONS=42"#
        );
    }

    #[test]
    fn test_gputrace_config() {
        let mut test_trace_options = GpuTraceOptions {
            record_shapes: true,
            profile_memory: false,
            with_stacks: true,
            with_flops: false,
            with_modules: true,
        };
        assert_eq!(
            test_trace_options.config(),
            r#"
PROFILE_REPORT_INPUT_SHAPES=true
PROFILE_PROFILE_MEMORY=false
PROFILE_WITH_STACK=true
PROFILE_WITH_FLOPS=false
PROFILE_WITH_MODULES=true"#
        );

        test_trace_options.profile_memory = true;

        let test_trace_config = GpuTraceConfig {
            log_file: String::from("/tmp/test_trace.json"),
            trigger_config: GpuTraceTriggerConfig::DurationBased {
                profile_start_time: 1000,
                duration_ms: 42,
            },
            trace_options: test_trace_options,
        };
        assert_eq!(
            test_trace_config.config(),
            r#"ACTIVITIES_LOG_FILE=/tmp/test_trace.json
PROFILE_START_TIME=1000
ACTIVITIES_DURATION_MSECS=42
PROFILE_REPORT_INPUT_SHAPES=true
PROFILE_PROFILE_MEMORY=true
PROFILE_WITH_STACK=true
PROFILE_WITH_FLOPS=false
PROFILE_WITH_MODULES=true"#
        );
    }
}
