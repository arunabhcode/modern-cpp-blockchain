// Copyright 2021 Arunabh Sharma

#include "mcb/block_chain.h"

#include "spdlog/spdlog.h"

namespace mcb
{
BlockChain::BlockChain(const int lead_zeros) : pow_inst_(lead_zeros)
{
  blocks_.emplace_back(Block("GenesisBlock", "", 0));
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
    spdlog::info("--------------");
    spdlog::info("Previous hash: {}", b.GetPrevHash());
    spdlog::info("Block data: {}", b.GetData());
    spdlog::info("Block hash: {}", b.GetHash());
    spdlog::info("Block nonce: {}", b.GetNonce());
    spdlog::info("--------------");
  }
}

}  // namespace mcb