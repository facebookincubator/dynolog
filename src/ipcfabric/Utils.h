// Copyright 2004-present Facebook. All Rights Reserved.

#pragma once

namespace dynolog {
namespace ipcfabric {

// struct to register libkineto process
struct LibkinetoContext {
  // gpu id of the process running on
  int32_t gpu;
  // pid to register to dynolog
  pid_t pid;
  // job id of the process
  int64_t jobid;
};

// struct to request libkineto ondemand config
struct LibkinetoRequest {
  // type of libkineto config
  int type;
  // size of pids
  int n;
  // job id of the libkineto process
  int64_t jobid;
  // pids of the process and its ancestors
  int32_t pids[];
};

constexpr char dynolog_endpoint[] = "dynolog";
constexpr char type_model_state[] = "model_status";
constexpr char type_model_id[] = "model_entity_id";
constexpr char type_tw_task[] = "tw_task";
constexpr char kLibkinetoRequest[] = "req";
constexpr char kLibkinetoContext[] = "ctxt";

} // namespace ipcfabric
} // namespace dynolog
