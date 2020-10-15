#include "gtest/gtest.h"
#include "config_test.hpp"
#include "task_test.hpp"
#include "data_accessor_json_test.hpp"


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}