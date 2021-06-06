// Copyright 2021 Arunabh Sharma

#ifndef MODULES_BLOCKCHAIN_INCLUDE_MCB_POW_H_
#define MODULES_BLOCKCHAIN_INCLUDE_MCB_POW_H_

#include <string>

#include "mcb/block.h"

namespace mcb
{
class Pow
{
 public:
  Pow() = delete;
  explicit Pow(const int lead_zeros);
  ~Pow() = default;

  void MineBlock(Block& block);
  bool ValidateBlock(const Block& block);

 private:
  std::string target_hash_;
};
}  // namespace mcb

#endif  // MODULES_BLOCKCHAIN_INCLUDE_MCB_POW_H_
