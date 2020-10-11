#include <stdlib.h>

#include <config.h>

namespace General::Scheduler {

Config::Config(){
    char* env = getenv("SCHEDULER_LOG_PATH");
    env != nullptr? log_path.assign(env): log_path = DEFAULT_SCHEDULER_LOG_PATH;

    env = getenv("SCHEDULER_LOG_LEVEL");
    env != nullptr? log_level.assign(env): log_level = DEFAULT_SCHEDULER_LOG_LEVEL;

    env = getenv("SCHEDULER_DELIVERY_IP");
    env != nullptr? delivery_ip.assign(env): delivery_ip = DEFAULT_SCHEDULER_DELIVERY_IP;

    env = getenv("SCHEDULER_DELIVERY_PORT");
    env != nullptr? delivery_port = std::stoi(env): delivery_port = DEFAULT_SCHEDULER_DELIVERY_PORT;
}

const std::string& Config::get_log_path() const {
    return log_path;
}

const std::string& Config::get_log_level() const {
    return log_level;
}

const std::string& Config::get_delivery_ip() const {
    return delivery_ip;
}

const int Config::get_delivery_port() const {
    return delivery_port;
}

}