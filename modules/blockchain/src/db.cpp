// Copyright 2021 Arunabh Sharma

#include "mcb/db.h"

#include <exception>
#include <system_error>

#include "spdlog/spdlog.h"

namespace mcb
{
DbWrapper::DbWrapper(const std::string& db_dir) : db_dir_(db_dir)
{
  options_.create_if_missing = true;
  if (!OpenDatabase())
  {
    std::error_code ec = make_error_code(std::errc::io_error);
    SPDLOG_ERROR("Opening database failed");
    throw std::system_error(ec, std::string("Opening database failed").c_str());
  }
}

DbWrapper::~DbWrapper()
{
  CloseDatabase();
}

bool DbWrapper::OpenDatabase()
{
  leveldb::Status s = leveldb::DB::Open(options_, db_dir_, &db_);
  db_it_            = db_->NewIterator(leveldb::ReadOptions());
  db_it_->SeekToFirst();
  return s.ok();
}

void DbWrapper::CloseDatabase()
{
  delete db_it_;
  delete db_;
}

bool DbWrapper::Write(const std::string& key, const std::string& value)
{
  leveldb::Status s = db_->Put(leveldb::WriteOptions(), key, value);
  return s.ok();
}

bool DbWrapper::Read(const std::string& key, std::string& value)
{
  leveldb::Status s = db_->Get(leveldb::ReadOptions(), key, &value);
  return s.ok();
}

bool DbWrapper::Remove(const std::string& key)
{
  leveldb::Status s = db_->Delete(leveldb::WriteOptions(), key);
  return s.ok();
}

bool DbWrapper::Iterate(std::string& value)
{
  if (!IsEmpty())
  {
    value = db_it_->value().ToString();
    db_it_->Next();
    return true;
  }
  return false;
}

bool DbWrapper::IsEmpty()
{
  return !db_it_->Valid();
}

}  // namespace mcb
