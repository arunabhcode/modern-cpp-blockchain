// Copyright 2021 Arunabh Sharma

#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_TRACE

#include "spdlog/cfg/env.h"
#include "spdlog/spdlog.h"

#include "mcb/block_chain.h"

int main()
{
  spdlog::cfg::load_env_levels();
  spdlog::set_pattern("%^[%l][%s:%#][%!]%$%v");

  mcb::BlockChain bc_inst(8, "/tmp/blocks");
  bc_inst.CreateBlock("Hello, ");
  bc_inst.CreateBlock("World!");

  return 0;
}
