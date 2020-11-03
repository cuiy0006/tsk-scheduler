#include <iostream>
#include <thread>

#include "scheduler.h"
#include "json_data_accessor.h"
#include <iostream>

namespace general::scheduler {

scheduler::scheduler(boost::asio::io_service& io_service, config& config)
    : m_io_service(io_service),
      m_config(config),
      m_refresh_timer(m_io_service),
      m_data_accessor(m_io_service, m_config) {
}

void scheduler::run() {
    m_io_service.dispatch([this]() {
        this->refresh();
    });

}

void scheduler::refresh() {
    // std::thread::id this_id = std::this_thread::get_id();
    // std::cout << this_id << std::endl;

    data_accessor::tasks_map_t tasks_map;

    auto cb = std::bind(&scheduler::get_tasks_map_callback, this, std::placeholders::_1);
    m_data_accessor.get_tasks_async(cb);

    std::cout << "scheduler next refresh..." << std::endl;

    schedule_next_refresh();
}

void scheduler::schedule_next_refresh() {
    m_refresh_timer.expires_from_now(boost::posix_time::seconds(m_config.get_refresh_interval()));
    m_refresh_timer.async_wait([this](const boost::system::error_code& e) {
        this->refresh();
    });
}

void scheduler::get_tasks_map_callback(const data_accessor::tasks_map_t& tasks_map) {
    for(auto it = tasks_map.begin(); it != tasks_map.end(); ++it){
        std::cout << it->second << std::endl;
        std::cout << "----------------------------------" << std::endl;
    }
    std::cout << "##########################################" << std::endl;
}



}