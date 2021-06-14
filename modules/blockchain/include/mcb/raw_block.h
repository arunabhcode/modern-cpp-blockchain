// Copyright 2021 Arunabh Sharma

#ifndef MODULES_BLOCKCHAIN_INCLUDE_MCB_BLOCK_H_
#define MODULES_BLOCKCHAIN_INCLUDE_MCB_BLOCK_H_

#include <string>
#include <vector>

namespace mcb
{
struct RawBlock
{
  std::string hash_;
  std::vector<uint8_t> block_data_;
  std::string prev_hash_;
  uint64_t nonce_;
};

}  // namespace mcb

#endif  // MODULES_BLOCKCHAIN_INCLUDE_MCB_BLOCK_H_
