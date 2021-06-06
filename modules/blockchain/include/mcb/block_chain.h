// Copyright 2021 Arunabh Sharma

#ifndef MODULES_BLOCKCHAIN_INCLUDE_MCB_TYPES_H_
#define MODULES_BLOCKCHAIN_INCLUDE_MCB_TYPES_H_

#include <string>
#include <vector>

#include "mcb/block.h"
#include "mcb/pow.h"

namespace mcb
{
class BlockChain
{
 public:
  BlockChain() = delete;
  explicit BlockChain(const int lead_zeros);
  ~BlockChain() = default;

  void CreateBlock(const std::string &block_msg);
  void PrintBlockChain();

 private:
  std::vector<Block> blocks_;
  Pow pow_inst_;
};

}  // namespace mcb

#endif  // MODULES_BLOCKCHAIN_INCLUDE_MCB_TYPES_H_