// Copyright 2021 Arunabh Sharma

#include "mcb/block_chain.h"
#include "mcb/logger.h"

int main()
{
  spdlog::cfg::load_env_levels();
  spdlog::set_pattern("%^[%l][%s:%#][%!]%$ %v");

  mcb::BlockChain bc_inst(8, "/tmp/blocks");
  bc_inst.CreateBlock("Hello, ");
  bc_inst.CreateBlock("World!");

  return 0;
}
