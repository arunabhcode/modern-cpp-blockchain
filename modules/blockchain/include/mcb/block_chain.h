// Copyright 2021 Arunabh Sharma

#ifndef MODULES_BLOCKCHAIN_INCLUDE_MCB_TYPES_H_
#define MODULES_BLOCKCHAIN_INCLUDE_MCB_TYPES_H_

#include <string>
#include <vector>

#include "mcb/block.h"
#include "mcb/db.h"
#include "mcb/pow.h"

namespace mcb
{
class BlockChain
{
 public:
  BlockChain() = delete;
  BlockChain(const int lead_zeros, const std::string &db_dir);
  ~BlockChain() = default;

  void CreateBlock(const std::string &block_msg);
  void PrintBlockChain();
  void InstantiateFromDatabase();
  bool AddToDatabase(const Block &block);

 private:
  std::vector<Block> blocks_;
  Pow pow_inst_;
  DbWrapper db_inst_;
  uint64_t db_count_key_;
};

}  // namespace mcb

#endif  // MODULES_BLOCKCHAIN_INCLUDE_MCB_TYPES_H_