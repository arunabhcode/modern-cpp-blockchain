// Copyright 2021 Arunabh Sharma

#include "mcb/block.h"

#include <string>
#include <vector>

#include "hash/picosha2.h"

namespace mcb
{
Block::Block(const std::string& block_msg, const std::string& prev_hash)
    : block_data_(block_msg.begin(), block_msg.end()), prev_hash_(prev_hash)
{
  CalcHash();
}

void Block::CalcHash()
{
  std::vector<uint8_t> hash_vec(block_data_.begin(), block_data_.end());
  std::copy(prev_hash_.begin(), prev_hash_.end(), std::back_inserter(hash_vec));
  picosha2::hash256_hex_string(hash_vec, hash_);
}

void Block::SetData(const std::string& block_msg)
{
  std::copy(
      block_msg.begin(), block_msg.end(), std::back_inserter(block_data_));
}

void Block::SetPrevHash(const std::string& prev_hash)
{
  prev_hash_ = prev_hash;
}

std::string Block::GetHash() const
{
  return hash_;
}

std::string Block::GetPrevHash() const
{
  return prev_hash_;
}

std::string Block::GetData() const
{
  return std::string(block_data_.begin(), block_data_.end());
}

}  // namespace mcb