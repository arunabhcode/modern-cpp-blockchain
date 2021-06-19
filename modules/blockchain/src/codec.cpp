// Copyright 2021 Arunabh Sharma

#include "mcb/codec.h"

#include <iostream>
#include <memory>
#include <regex>
#include <vector>

#include "mcb/logger.h"

namespace mcb
{
void Codec::Encode(const Block& block, std::string& encode_str)
{
  encode_str = block.GetData() + "~^" + std::to_string(block.GetNonce());
}

// From https://www.geeksforgeeks.org/tokenizing-a-string-cpp/
std::vector<std::string> Codec::Tokenize(const std::string& str,
                                         const std::regex& re)
{
  std::sregex_token_iterator it{str.begin(), str.end(), re, -1};
  std::vector<std::string> tokenized{it, {}};

  return tokenized;
}

void Codec::Decode(const std::string& decode_str,
                   const std::string& prev_hash,
                   Block& block)
{
  std::regex re(R"([~^]+)");
  std::vector<std::string> decode_vec = Tokenize(decode_str, re);
  block.SetData(decode_vec[0]);
  block.SetPrevHash(prev_hash);
  block.SetNonce(std::stoull(decode_vec[1]));
  block.CalcHash();
}

}  // namespace mcb
