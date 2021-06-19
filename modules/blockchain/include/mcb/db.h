// Copyright 2021 Arunabh Sharma

#ifndef MODULES_BLOCKCHAIN_INCLUDE_MCB_DB_H_
#define MODULES_BLOCKCHAIN_INCLUDE_MCB_DB_H_

#include <memory>
#include <string>

#include "leveldb/db.h"

namespace mcb
{
class DbWrapper
{
 public:
  DbWrapper() = delete;
  explicit DbWrapper(const std::string& db_dir);
  ~DbWrapper();

  bool OpenDatabase();
  void CloseDatabase();

  bool Write(const std::string& key, const std::string& value);
  bool Read(const std::string& key, std::string& value);
  bool Remove(const std::string& key);
  bool Iterate(std::string& value);
  bool IsEmpty();

 private:
  leveldb::DB* db_;
  leveldb::Options options_;
  std::string db_dir_;
  leveldb::Iterator* db_it_;
};

}  // namespace mcb

#endif  // MODULES_BLOCKCHAIN_INCLUDE_MCB_DB_H_
