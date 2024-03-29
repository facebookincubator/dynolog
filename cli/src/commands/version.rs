// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

use std::net::TcpStream;

use anyhow::Result;

#[path = "utils.rs"]
mod utils;

// This module contains the handling logic for querying dyno version

/// Get version info
pub fn run_version(client: TcpStream) -> Result<()> {
    utils::send_msg(&client, r#"{"fn":"getVersion"}"#).expect("Error sending message to service");

    let resp_str = utils::get_resp(&client).expect("Unable to decode output bytes");

    println!("response = {}", resp_str);

    Ok(())
}
