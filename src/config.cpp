#include <stdlib.h>

#include "config.h"

namespace general::scheduler {

config::config(){
    char* env = getenv("SCHEDULER_LOG_PATH");
    env != nullptr? m_log_path.assign(env): m_log_path = DEFAULT_SCHEDULER_LOG_PATH;

    env = getenv("SCHEDULER_LOG_LEVEL");
    env != nullptr? m_log_level.assign(env): m_log_level = DEFAULT_SCHEDULER_LOG_LEVEL;

    env = getenv("SCHEDULER_DELIVERY_IP");
    env != nullptr? m_delivery_ip.assign(env): m_delivery_ip = DEFAULT_SCHEDULER_DELIVERY_IP;

    env = getenv("SCHEDULER_DELIVERY_PORT");
    env != nullptr? m_delivery_port = std::stoi(env): m_delivery_port = DEFAULT_SCHEDULER_DELIVERY_PORT;

    env = getenv("SCHEDULER_THREAD_POOL_SIZE");
    env != nullptr? m_thread_pool_size = std::stoi(env): m_thread_pool_size = DEFAULT_SCHEDULER_THREAD_POOL_SIZE;

    env = getenv("SCHEDULER_REFRESH_INTERVAL");
    env != nullptr? m_refresh_interval = std::stoi(env): m_refresh_interval = DEFAULT_SCHEDULER_REFRESH_INTERVAL;
}

const std::string& config::get_log_path() const {
    return m_log_path;
}

const std::string& config::get_log_level() const {
    return m_log_level;
}

const std::string& config::get_delivery_ip() const {
    return m_delivery_ip;
}

const int config::get_delivery_port() const {
    return m_delivery_port;
}

const int config::get_thread_pool_size() const {
    return m_thread_pool_size;
}

const int config::get_refresh_interval() const {
    return m_refresh_interval;
}

}