// (c) Meta Platforms, Inc. and affiliates. Confidential and proprietary.

use std::net::TcpStream;

use anyhow::Result;
use serde_json::Value;

#[path = "utils.rs"]
mod utils;

// This module contains the handling logic for dyno gputrace

/// Gputrace command triggers GPU profiling on pytorch apps
pub fn run_gputrace(
    client: TcpStream,
    job_id: u64,
    pids: &str,
    duration_ms: u64,
    log_file: &str,
    profile_start_time: u64,
    process_limit: u32,
) -> Result<()> {
    let kineto_config = format!(
        r#"PROFILE_START_TIME={}\n ACTIVITIES_DURATION_MSECS={}\nACTIVITIES_LOG_FILE={}"#,
        profile_start_time, duration_ms, log_file
    );

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
                log_file.replace(".json", &format!("_{}.json", pid))
            );
        }
    }

    Ok(())
}
