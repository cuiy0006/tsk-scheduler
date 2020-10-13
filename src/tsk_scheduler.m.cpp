#include "threads/asio_thread_pool.hpp"
#include "config.h"
#include "scheduler/scheduler.h"


int main(int argc, char *argv[])
{
    general::scheduler::config config;

    general::scheduler::asio_thread_pool pool(config.get_thread_pool_size());

    auto& io_service = pool.get_io_service();

    general::scheduler::scheduler scheduler(io_service, config);

    scheduler.run();

    io_service.run();
    
    return 0;
}
