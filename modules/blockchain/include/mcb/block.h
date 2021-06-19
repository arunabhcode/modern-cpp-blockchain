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
  Block(const std::string& block_msg,
        const std::string& prev_hash,
        const uint64_t nonce);
  ~Block() = default;

  void AppendStringToByteVector(const std::string& str,
                                std::vector<uint8_t>& vec);
  void CalcHash();

  void SetHash(const std::string& hash);
  void SetData(const std::string& block_msg);
  void SetPrevHash(const std::string& prev_hash);
  void SetNonce(const uint64_t nonce);

  std::string GetHash() const;
  std::string GetPrevHash() const;
  std::string GetData() const;
  uint64_t GetNonce() const;

  void PrintBlock() const;

 private:
  std::string hash_;
  std::vector<uint8_t> block_data_;
  std::string prev_hash_;
  uint64_t nonce_;
};

}  // namespace mcb

#endif  // MODULES_BLOCKCHAIN_INCLUDE_MCB_BLOCK_H_
