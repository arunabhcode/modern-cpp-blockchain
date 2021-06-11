// Copyright 2021 Arunabh Sharma

#include "mcb/codec.h"

#include <iostream>
#include <memory>
#include <vector>

#include "spdlog/spdlog.h"

namespace mcb
{
void Codec::Encode(const Block& block, std::string& encode_str)
{
  const char* raw_buffer =
      static_cast<const char*>(static_cast<const void*>(std::addressof(block)));
  std::string s(raw_buffer, raw_buffer + sizeof(Block));
  encode_str = s;
}

void Codec::Decode(const std::string& decode_str, Block& block)
{
  char* raw_buffer = const_cast<char*>(decode_str.c_str());
  std::memcpy(std::addressof(block), raw_buffer, sizeof(Block));
}

}  // namespace mcb
