#include <string>

namespace General::Scheduler {

class Config {
public:
    Config();
    const std::string& get_log_path() const;
    const std::string& get_log_level() const;
    const std::string& get_delivery_ip() const;
    const int get_delivery_port() const;
    

private:
    constexpr static const char* DEFAULT_SCHEDULER_LOG_PATH = "./scheduler.log";
    constexpr static const char* DEFAULT_SCHEDULER_LOG_LEVEL = "INFO";
    constexpr static const char* DEFAULT_SCHEDULER_DELIVERY_IP = "127.0.0.1";
    constexpr static int DEFAULT_SCHEDULER_DELIVERY_PORT = 43200;

    std::string log_path;
    std::string log_level;
    std::string delivery_ip;
    int delivery_port;
};    

}