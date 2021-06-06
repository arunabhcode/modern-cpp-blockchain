// Copyright 2021 Arunabh Sharma

#include "mcb/block_chain.h"

int main()
{
  mcb::BlockChain bc_inst(8);
  bc_inst.CreateBlock("Hello, ");
  bc_inst.CreateBlock("World!");

  return 0;
}
