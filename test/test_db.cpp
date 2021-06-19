// Copyright 2021 Arunabh Sharma

#include "gtest/gtest.h"

#include "mcb/db.h"
#include "mcb/logger.h"

class DbTest : public ::testing::Test
{
 protected:
  DbTest();
  ~DbTest() override;

  void SetUp() override;
  void TearDown() override;

  mcb::DbWrapper db_inst_;
};

DbTest::DbTest() : db_inst_("/tmp/test_blocks")
{
}

DbTest::~DbTest() = default;

void DbTest::SetUp()
{
}
void DbTest::TearDown()
{
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

TEST_F(DbTest, WriteReadDatabaseGood)
{
  db_inst_.Write("key1", "value1");
  db_inst_.Write("key2", "value2");
  db_inst_.Write("key3", "value3");
  std::string value;
  bool read_status;
  read_status = db_inst_.Read("key1", value);
  ASSERT_TRUE(read_status);
  ASSERT_EQ(value, "value1");
  read_status = db_inst_.Read("key2", value);
  ASSERT_TRUE(read_status);
  ASSERT_EQ(value, "value2");
  read_status = db_inst_.Read("key3", value);
  ASSERT_TRUE(read_status);
  ASSERT_EQ(value, "value3");
  read_status = db_inst_.Read("key4", value);
  ASSERT_FALSE(read_status);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

TEST_F(DbTest, IterateGood)
{
  std::string value;
  bool valid;
  valid = db_inst_.Iterate(value);
  ASSERT_TRUE(valid);
  ASSERT_EQ(value, "value1");
  valid = db_inst_.Iterate(value);
  ASSERT_TRUE(valid);
  ASSERT_EQ(value, "value2");
  valid = db_inst_.Iterate(value);
  ASSERT_TRUE(valid);
  ASSERT_EQ(value, "value3");
  valid = db_inst_.Iterate(value);
  ASSERT_FALSE(valid);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

TEST_F(DbTest, RemoveGood)
{
  std::string value;
  bool read_valid, write_valid;
  write_valid = db_inst_.Write("key4", "value4");
  ASSERT_TRUE(write_valid);
  read_valid = db_inst_.Read("key4", value);
  ASSERT_TRUE(read_valid);
  ASSERT_EQ(value, "value4");
  bool del_valid = db_inst_.Remove("key4");
  ASSERT_TRUE(del_valid);
  read_valid = db_inst_.Read("key4", value);
  ASSERT_FALSE(read_valid);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(int argc, char** argv)
{
  spdlog::cfg::load_env_levels();
  spdlog::set_pattern("%^[%l][%s:%#][%!]%$ %v");
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
