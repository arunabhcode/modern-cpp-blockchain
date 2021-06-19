// Copyright 2018 Arunabh Sharma

#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_TRACE

#include "spdlog/cfg/env.h"
#include "spdlog/spdlog.h"

int main()
{
  spdlog::cfg::load_env_levels();
  SPDLOG_TRACE("This will print trace level message");
  // To use to tell the user something or general landmark output
  SPDLOG_INFO("This will print info level message");
  // To debug
  SPDLOG_DEBUG("This will print debug level message");
  // To warn the user in case of some non-expected/borderline value
  SPDLOG_WARN("This will print warn level message");
  // To log some critical assertion failure
  SPDLOG_CRITICAL("This will print critical level message");
  // In case of try catching
  SPDLOG_ERROR("This will print error level message");
  return 0;
}
