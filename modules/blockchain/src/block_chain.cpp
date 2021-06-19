// Copyright 2021 Arunabh Sharma

#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_TRACE

#include "mcb/block_chain.h"

#include "mcb/codec.h"
#include "mcb/logger.h"

namespace mcb
{
BlockChain::BlockChain(const int lead_zeros, const std::string& db_dir)
    : pow_inst_(lead_zeros), db_inst_(db_dir), db_count_key_(0)
{
  Block genesis_block("GenesisBlock", "", 0);
  pow_inst_.MineBlock(genesis_block);
  blocks_.emplace_back(genesis_block);
  if (!db_inst_.IsEmpty())
  {
    SPDLOG_INFO("Reading blockchain from database");
    InstantiateFromDatabase();
  }
  else
  {
    SPDLOG_INFO("Creating new blockchain");
  }
}

void BlockChain::CreateBlock(const std::string& block_msg)
{
  Block raw_block(block_msg, blocks_.back().GetHash(), 0);
  pow_inst_.MineBlock(raw_block);
  if (pow_inst_.ValidateBlock(raw_block) && AddToDatabase(raw_block))
  {
    blocks_.emplace_back(raw_block);
  }
  else
  {
    SPDLOG_ERROR("Invalid block or write to database failed");
    throw std::domain_error("Invalid block or write to database failed");
  }
}

void BlockChain::PrintBlockChain()
{
  for (const Block& b : blocks_)
  {
    b.PrintBlock();
  }
}

void BlockChain::InstantiateFromDatabase()
{
  while (!db_inst_.IsEmpty())
  {
    std::string decode_str;
    db_inst_.Iterate(decode_str);
    SPDLOG_DEBUG(decode_str);
    mcb::Block decode_block;
    Codec::Decode(decode_str, blocks_.back().GetHash(), decode_block);
    decode_block.PrintBlock();
    blocks_.emplace_back(decode_block);
    db_count_key_++;
  }
}

bool BlockChain::AddToDatabase(const Block& block)
{
  std::string encode_str;
  Codec::Encode(block, encode_str);
  SPDLOG_DEBUG(encode_str);
  bool write_status = db_inst_.Write(std::to_string(db_count_key_), encode_str);
  db_count_key_++;
  return write_status;
}

}  // namespace mcb
