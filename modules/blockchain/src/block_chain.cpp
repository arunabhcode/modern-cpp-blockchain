// Copyright 2021 Arunabh Sharma

#include "mcb/block_chain.h"

#include "spdlog/spdlog.h"

namespace mcb
{
BlockChain::BlockChain(const int lead_zeros) : pow_inst_(lead_zeros)
{
  Block genesis_block("GenesisBlock", "", 0);
  pow_inst_.MineBlock(genesis_block);
  blocks_.emplace_back(genesis_block);
}

void BlockChain::CreateBlock(const std::string& block_msg)
{
  Block raw_block(block_msg, blocks_.back().GetHash(), 0);
  pow_inst_.MineBlock(raw_block);
  if (pow_inst_.ValidateBlock(raw_block))
  {
    blocks_.emplace_back(raw_block);
  }
  else
  {
    throw std::domain_error("Invalid block");
  }
}

void BlockChain::PrintBlockChain()
{
  for (const Block& b : blocks_)
  {
    b.PrintBlock();
  }
}

}  // namespace mcb
