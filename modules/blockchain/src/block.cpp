// Copyright 2021 Arunabh Sharma

#include "mcb/block.h"

#include <string>
#include <vector>

#include "mcb/logger.h"

#include "hash/picosha2.h"

namespace mcb
{
Block::Block(const std::string& block_msg,
             const std::string& prev_hash,
             const uint64_t nonce)
    : block_data_(block_msg.begin(), block_msg.end())
    , prev_hash_(prev_hash)
    , nonce_(nonce)
{
  CalcHash();
}

void Block::AppendStringToByteVector(const std::string& str,
                                     std::vector<uint8_t>& vec)
{
  std::copy(str.begin(), str.end(), std::back_inserter(vec));
}

void Block::CalcHash()
{
  std::vector<uint8_t> hash_vec(block_data_.begin(), block_data_.end());

  AppendStringToByteVector(prev_hash_, hash_vec);

  std::stringstream stream;
  stream << std::hex << nonce_;
  std::string nonce_hex_str(stream.str());
  AppendStringToByteVector(nonce_hex_str, hash_vec);

  picosha2::hash256_hex_string(hash_vec, hash_);
}

void Block::SetHash(const std::string& hash)
{
  hash_ = hash;
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

void Block::SetNonce(const uint64_t nonce)
{
  nonce_ = nonce;
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

uint64_t Block::GetNonce() const
{
  return nonce_;
}

void Block::PrintBlock() const
{
  SPDLOG_INFO("--------------");
  SPDLOG_INFO("Previous hash: {}", prev_hash_);
  SPDLOG_INFO("Block data: {}",
              std::string(block_data_.begin(), block_data_.end()));
  SPDLOG_INFO("Block hash: {}", hash_);
  SPDLOG_INFO("Block nonce: {}", nonce_);
  SPDLOG_INFO("--------------");
}

}  // namespace mcb
