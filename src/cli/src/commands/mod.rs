// (c) Meta Platforms, Inc. and affiliates. Confidential and proprietary.

// Export all command submodules to be used in main.rs
// Note: This "intermediate" commands module is purely for organizational purposes.
// This allows for a clear distinction between the command dispatching code and the command
// handling code. Additionally, explicitly "exporting" all the command modules here allows
// us to avoid having to explicitly list all the command modules in main.rs.

pub mod gputrace;
pub mod status;
// ... add new command modules here
