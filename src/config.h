#ifndef CONFIG_H
#define CONFIG_H

#include <string>

namespace general::scheduler {

class config {
public:
    config();
    const std::string& get_log_path() const;
    const std::string& get_log_level() const;
    const std::string& get_delivery_ip() const;
    const int get_delivery_port() const;
    const int get_thread_pool_size() const;
    const int get_refresh_interval() const;
    const std::string& get_task_json_path() const;
    

private:
    constexpr static const char* DEFAULT_SCHEDULER_LOG_PATH = "./scheduler_%N.log";
    constexpr static const char* DEFAULT_SCHEDULER_LOG_LEVEL = "DEBUG";
    constexpr static const char* DEFAULT_SCHEDULER_DELIVERY_IP = "127.0.0.1";
    constexpr static int DEFAULT_SCHEDULER_DELIVERY_PORT = 43200;
    constexpr static int DEFAULT_SCHEDULER_THREAD_POOL_SIZE = 16;
    constexpr static int DEFAULT_SCHEDULER_REFRESH_INTERVAL = 30;
    constexpr static const char* DEFAULT_SCHEDULER_TASK_JSON_PATH = "./tasks.json";

    std::string m_log_path;
    std::string m_log_level;
    std::string m_delivery_ip;
    int m_delivery_port;
    int m_thread_pool_size;
    int m_refresh_interval;
    std::string m_task_json_path;
};    

}

#endif