#include "gtest/gtest.h"
#include <json_data_accessor.h>
#include <boost/asio.hpp>

using namespace general::scheduler;
using namespace boost::asio;

class DataAccessorJsonTest : public ::testing::Test {
protected:

  DataAccessorJsonTest()
    : m_jda(m_io_service, m_config) {
  }

  ~DataAccessorJsonTest() override {
  }


  void SetUp() override {
  }

  void TearDown() override {
  }

  general::scheduler::config m_config;
  io_service m_io_service;
  json_data_accessor m_jda;
};


TEST_F(DataAccessorJsonTest, TestGetTasks){
    data_accessor::tasks_map_t tasks_map;

    m_jda.get_tasks(tasks_map, true);

    EXPECT_NE(0, tasks_map.size());

    for(auto it = tasks_map.begin(); it != tasks_map.end(); ++it){
        const std::string& task_id = it->first;

        EXPECT_EQ(task_id, it->second.get_task_id());
    }
}

TEST_F(DataAccessorJsonTest, TestGetTasksAsync) {
    data_accessor::get_tasks_callback cb = [](data_accessor::tasks_map_t tasks_map) {
        EXPECT_NE(0, tasks_map.size());

        for(auto it = tasks_map.begin(); it != tasks_map.end(); ++it){
            const std::string& task_id = it->first;

            EXPECT_EQ(task_id, it->second.get_task_id());
        }
    };

    m_jda.get_tasks_async(cb, true);
}