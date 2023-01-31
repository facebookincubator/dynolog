// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

use std::net::TcpStream;

use anyhow::Result;

#[path = "utils.rs"]
mod utils;

// This module contains the handling logic for dcgm

/// Pause dcgm module profiling
pub fn run_dcgm_pause(client: TcpStream, duration_s: i32) -> Result<()> {
    let request_json = format!(
        r#"
{{
    "fn": "dcgmProfPause",
    "duration_s": {}
}}"#,
        duration_s
    );

    utils::send_msg(&client, &request_json).expect("Error sending message to service");

    let resp_str = utils::get_resp(&client).expect("Unable to decode output bytes");

    println!("response = {}", resp_str);

    Ok(())
}

/// Resume dcgm module profiling
pub fn run_dcgm_resume(client: TcpStream) -> Result<()> {
    utils::send_msg(&client, r#"{"fn":"dcgmProfResume"}"#)
        .expect("Error sending message to service");

    let resp_str = utils::get_resp(&client).expect("Unable to decode output bytes");

    println!("response = {}", resp_str);

    Ok(())
}
