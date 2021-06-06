// Copyright 2021 Arunabh Sharma

#include "mcb/pow.h"

#include <cmath>
#include <iomanip>
#include <limits>
#include <sstream>

#include "spdlog/spdlog.h"

namespace mcb
{
Pow::Pow(const int lead_zeros)
{
  if (lead_zeros > 256)
  {
    throw std::domain_error("Number of leading zeros can't be bigger than 256");
  }

  std::stringstream ss;
  ss << std::setfill('0') << std::setw(64) << std::hex << 0;
  target_hash_ = ss.str();
  int hash_idx = (lead_zeros / 4) > 0 ? lead_zeros / 4 - 1 : lead_zeros / 4;
  target_hash_[hash_idx] =
      std::to_string(std::pow(2, (4 - (lead_zeros % 4))))[0];
  spdlog::info("Target hash: {}", target_hash_);
}

bool Pow::HexGreater(const std::string &s1, const std::string &s2)
{
  if (s1.size() > s2.size())
    return true;
  else if (s1.size() < s2.size())
    return false;

  if (s1 > s2)
  {
    return true;
  }
  return false;
}

void Pow::MineBlock(Block &block)
{
  for (uint64_t i = 0; i < std::numeric_limits<uint64_t>::max(); i++)
  {
    block.SetNonce(i);
    block.CalcHash();
    if (HexGreater(target_hash_, block.GetHash()))
    {
      spdlog::info("Block hash found");
      block.PrintBlock();
      return;
    }
  }
}

bool Pow::ValidateBlock(const Block &block)
{
  Block val_block(block.GetData(), block.GetPrevHash(), block.GetNonce());
  val_block.CalcHash();
  if (HexGreater(target_hash_, val_block.GetHash()))
  {
    return true;
  }
  return false;
}

}  // namespace mcb
