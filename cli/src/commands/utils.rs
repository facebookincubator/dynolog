// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

use std::io::Read;
use std::io::Write;
use std::net::TcpStream;

use anyhow::Result;

pub fn send_msg(mut client: &TcpStream, msg: &str) -> Result<()> {
    let msg_len: [u8; 4] = i32::try_from(msg.len()).unwrap().to_ne_bytes();

    client.write_all(&msg_len)?;
    client.write_all(msg.as_bytes()).map_err(|err| err.into())
}

pub fn get_resp(mut client: &TcpStream) -> Result<String> {
    // Response is prefixed with length
    let mut resp_len: [u8; 4] = [0; 4];
    client.read_exact(&mut resp_len)?;

    let resp_len = i32::from_ne_bytes(resp_len);
    let resp_len = usize::try_from(resp_len).unwrap();

    println!("response length = {}", resp_len);

    let mut resp_str = Vec::<u8>::new();
    resp_str.resize(resp_len, 0);

    client.read_exact(resp_str.as_mut_slice())?;

    String::from_utf8(resp_str).map_err(|err| err.into())
}
