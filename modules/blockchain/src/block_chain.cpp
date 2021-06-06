// Copyright 2021 Arunabh Sharma

#include "mcb/block_chain.h"

#include "spdlog/spdlog.h"

namespace mcb
{
BlockChain::BlockChain()
{
  blocks_.emplace_back(Block("GenesisBlock", "", 0));
}

void BlockChain::CreateBlock(const std::string& block_msg)
{
  blocks_.emplace_back(Block(block_msg, blocks_.back().GetHash(), 0));
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