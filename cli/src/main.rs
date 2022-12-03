// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

use std::net::TcpStream;
use std::net::ToSocketAddrs;

use anyhow::Result;
use clap::Parser;

// Make all the command modules accessible to this file.
mod commands;
use commands::*;

/// Instructions on adding a new Dyno CLI command:
///
/// 1. Add a new variant to the `Command` enum.
///    Please include a description of the command and, if applicable, its flags/subcommands.
///
/// 2. Create a new file for the command's implementation in the commands/ directory (ie
///    commands/status.rs). This new file is where the command should be implemented.
///    Make the new command's module accessible from this file by adding
///    a new line with `pub mod <newfile>;` to commands/mod.rs.
///
///
/// 3. Add a branch to the match statement in main() to handle the new enum variant (from step 1).
///    From here, invoke the handling logic defined in the new file (from step 2). In an effort to keep
///    the command dispatching logic clear and concise, please keep the code in the match branch to a minimum.

const DYNO_PORT: u16 = 1778;

#[derive(Debug, Parser)]
struct Opts {
    #[clap(long, default_value = "localhost")]
    hostname: String,
    #[clap(long, default_value_t = DYNO_PORT)]
    port: u16,
    #[clap(subcommand)]
    cmd: Command,
}

#[derive(Debug, Parser)]
enum Command {
    /// Check the status of dynolog process
    Status,
    /// Capture gputrace
    Gputrace {
        /// Job id of the application to trace
        #[clap(long, default_value_t = 0)]
        job_id: u64,
        /// List of pids to capture trace for (comma separated).
        #[clap(long, default_value = "0")]
        pids: String,
        /// Duration of trace to collect in ms.
        #[clap(long, default_value_t = 500)]
        duration_ms: u64,
        /// Training iterations to collect, this takes precedence over duration.
        #[clap(long, default_value_t = -1)]
        iterations: i64,
        /// Log file for trace.
        #[clap(long)]
        log_file: String,
        /// Unix timestamp used for synchronized collection (milliseconds since epoch)
        #[clap(long, default_value_t = 0)]
        profile_start_time: u64,
        /// Start iteration roundup, starts an iteration based trace at a multiple
        /// of this value.
        #[clap(long, default_value_t = 1)]
        profile_start_iteration_roundup: u64,
        /// Max number of processes to profile
        #[clap(long, default_value_t = 3)]
        process_limit: u32,
    },
}

/// Create a socket connection to dynolog
fn create_dyno_client(host: &str, port: u16) -> Result<TcpStream> {
    let addr = (host, port)
        .to_socket_addrs()?
        .next()
        .expect("Failed to connect to the server");

    TcpStream::connect(addr).map_err(|err| err.into())
}

fn main() -> Result<()> {
    let Opts {
        hostname,
        port,
        cmd,
    } = Opts::parse();

    let dyno_client =
        create_dyno_client(&hostname, port).expect("Couldn't connect to the server...");

    match cmd {
        Command::Status => status::run_status(dyno_client),
        Command::Gputrace {
            job_id,
            pids,
            log_file,
            duration_ms,
            iterations,
            profile_start_time,
            profile_start_iteration_roundup,
            process_limit,
        } => gputrace::run_gputrace(
            dyno_client,
            job_id,
            &pids,
            duration_ms,
            iterations,
            &log_file,
            profile_start_time,
            profile_start_iteration_roundup,
            process_limit,
        ),
        // ... add new commands here
    }
}
