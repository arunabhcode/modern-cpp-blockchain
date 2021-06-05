// Copyright 2021 Arunabh Sharma

#include "mcb/block_chain.h"

int main()
{
  mcb::BlockChain bc_inst;
  bc_inst.CreateBlock("Hello, ");
  bc_inst.CreateBlock("World!");
  bc_inst.PrintBlockChain();

  return 0;
}
