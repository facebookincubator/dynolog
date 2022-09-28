// (c) Meta Platforms, Inc. and affiliates. Confidential and proprietary.

use std::net::TcpStream;

use anyhow::Result;

#[path = "utils.rs"]
mod utils;

// This module contains the handling logic for dyno status

/// Get system info
pub fn run_status(client: TcpStream) -> Result<()> {
    utils::send_msg(&client, r#"{"fn":"getStatus"}"#).expect("Error sending message to service");

    let resp_str = utils::get_resp(&client).expect("Unable to decode output bytes");

    println!("response = {}", resp_str);

    Ok(())
}
