#include "gtest/gtest.h"
#include "json_data_accessor.h"
#include "asio_thread_pool.hpp"

using namespace general::scheduler;

TEST(DataAccessorJsonTest, TestDefault){

    general::scheduler::asio_thread_pool pool(1);

    auto& io_service = pool.get_io_service();

    general::scheduler::config config;

    json_data_accessor jda(io_service, config);

    data_accessor::tasks_map_t tasks_map;

    jda.get_tasks(tasks_map);

    pool.stop();
}
