#include "scheduler.h"
#include <iostream>
#include <thread>

namespace general::scheduler {

scheduler::scheduler(boost::asio::io_service& io_service, config& config)
    : m_io_service(io_service),
      m_config(config),
      m_refresh_timer(m_io_service) {
}

void scheduler::run() {
    m_io_service.dispatch([this]() {
        this->refresh();
    });

}

void scheduler::refresh() {
    std::thread::id this_id = std::this_thread::get_id();
    std::cout << this_id << std::endl;

    schedule_next_refresh();
}

void scheduler::schedule_next_refresh() {
    m_refresh_timer.expires_from_now(boost::posix_time::seconds(m_config.get_refresh_interval()));
    m_refresh_timer.async_wait([this](const boost::system::error_code& e) {
        this->refresh();
    });
}

}