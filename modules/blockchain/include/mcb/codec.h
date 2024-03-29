// Copyright 2021 Arunabh Sharma

#ifndef MODULES_BLOCKCHAIN_INCLUDE_MCB_CODEC_H_
#define MODULES_BLOCKCHAIN_INCLUDE_MCB_CODEC_H_

#include <regex>
#include <vector>

#include "mcb/block.h"

namespace mcb
{
class Codec
{
 public:
  Codec()  = default;
  ~Codec() = default;

  static void Encode(const Block& block, std::string& byte_buffer);
  static std::vector<std::string> Tokenize(const std::string& str,
                                           const std::regex& re);
  static void Decode(const std::string& byte_buffer,
                     const std::string& prev_hash,
                     Block& block);
};

}  // namespace mcb

#endif  // MODULES_BLOCKCHAIN_INCLUDE_MCB_CODEC_H_
