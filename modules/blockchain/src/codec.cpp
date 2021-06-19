// Copyright 2021 Arunabh Sharma

#include "mcb/codec.h"

#include <iostream>
#include <memory>
#include <regex>
#include <vector>

#include "spdlog/spdlog.h"

namespace mcb
{
void Codec::Encode(const Block& block, std::string& encode_str)
{
  encode_str = block.GetData() + "," + block.GetPrevHash() + "," +
               std::to_string(block.GetNonce());
}

// From https://www.geeksforgeeks.org/tokenizing-a-string-cpp/
std::vector<std::string> Codec::Tokenize(const std::string& str,
                                         const std::regex& re)
{
  std::sregex_token_iterator it{str.begin(), str.end(), re, -1};
  std::vector<std::string> tokenized{it, {}};

  // tokenized.erase(
  //     std::remove_if(tokenized.begin(),
  //                    tokenized.end(),
  //                    [](std::string const& s) { return s.size() == 0; }),
  //     tokenized.end());

  return tokenized;
}

void Codec::Decode(const std::string& decode_str, Block& block)
{
  std::regex re(R"([,]+)");
  std::vector<std::string> decode_vec = Tokenize(decode_str, re);
  block.SetData(decode_vec[0]);
  block.SetPrevHash(decode_vec[1]);
  block.SetNonce(std::stoull(decode_vec[2]));
  block.CalcHash();
}

}  // namespace mcb
