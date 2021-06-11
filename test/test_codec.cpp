// Copyright 2021 Arunabh Sharma

#include <vector>

#include "gtest/gtest.h"
#include "spdlog/spdlog.h"

#include "mcb/block.h"
#include "mcb/codec.h"

class CodecTest : public ::testing::Test
{
 protected:
  CodecTest();
  ~CodecTest() override;

  void SetUp() override;
  void TearDown() override;
};

CodecTest::CodecTest()  = default;
CodecTest::~CodecTest() = default;

void CodecTest::SetUp()
{
}
void CodecTest::TearDown()
{
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

TEST_F(CodecTest, EncodeDecodeGood)
{
  mcb::Block encode_block("hello", "world", 0);
  std::string encode_string;
  mcb::Codec::Encode(encode_block, encode_string);
  spdlog::info("Encode string : {}", encode_string);

  std::string decode_string(encode_string);
  mcb::Block decode_block;
  mcb::Codec::Decode(decode_string, decode_block);
  spdlog::info("Decode block data : {}", decode_block.GetData());
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
