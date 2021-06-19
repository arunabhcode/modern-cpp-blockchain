// Copyright 2021 Arunabh Sharma

#include <vector>

#include "gtest/gtest.h"

#include "mcb/block.h"
#include "mcb/codec.h"
#include "mcb/db.h"
#include "mcb/logger.h"

class CodecTest : public ::testing::Test
{
 protected:
  CodecTest();
  ~CodecTest() override;

  void SetUp() override;
  void TearDown() override;
};

CodecTest::CodecTest()
{
}

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

  mcb::Block decode_block;
  std::string decode_string(encode_string);
  mcb::Codec::Decode(decode_string, decode_block);

  ASSERT_EQ(encode_block.GetHash(), decode_block.GetHash());
  ASSERT_EQ(encode_block.GetPrevHash(), decode_block.GetPrevHash());
  ASSERT_EQ(encode_block.GetData(), decode_block.GetData());
  ASSERT_EQ(encode_block.GetNonce(), decode_block.GetNonce());
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(int argc, char** argv)
{
  spdlog::cfg::load_env_levels();
  spdlog::set_pattern("%^[%l][%s:%#][%!]%$ %v");
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
