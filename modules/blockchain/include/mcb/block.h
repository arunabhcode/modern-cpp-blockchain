// Copyright 2021 Arunabh Sharma

#ifndef MODULES_BLOCKCHAIN_INCLUDE_MCB_BLOCK_H_
#define MODULES_BLOCKCHAIN_INCLUDE_MCB_BLOCK_H_

#include <string>
#include <vector>

namespace mcb
{
class Block
{
 public:
  Block() = default;
  Block(const std::string& block_msg, const std::string& prev_hash);
  ~Block() = default;

  void CalcHash();
  void SetData(const std::string& block_msg);
  void SetPrevHash(const std::string& prev_hash);
  std::string GetHash() const;
  std::string GetPrevHash() const;
  std::string GetData() const;

 private:
  std::string hash_;
  std::vector<uint8_t> block_data_;
  std::string prev_hash_;
};

}  // namespace mcb

#endif  // MODULES_BLOCKCHAIN_INCLUDE_MCB_BLOCK_H_
