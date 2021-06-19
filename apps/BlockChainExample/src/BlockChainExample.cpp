// Copyright 2021 Arunabh Sharma

#include "mcb/block_chain.h"
#include "spdlog/spdlog.h"

int main()
{
  spdlog::set_pattern("%^[%l][%s:%#][%!]%$%v");

  mcb::BlockChain bc_inst(8, "/tmp/blocks");
  bc_inst.CreateBlock("Hello");
  bc_inst.CreateBlock("World!");

  return 0;
}
