#include "gtest/gtest.h"
#include <config.h>
#include <stdlib.h>
#include <string>

using namespace general::scheduler;

TEST(ConfigTest, TestDefault){
    config config;
    ASSERT_EQ("./scheduler_%N.log", config.get_log_path());
    ASSERT_EQ("DEBUG", config.get_log_level());
    ASSERT_EQ("127.0.0.1", config.get_delivery_ip());
    ASSERT_EQ(43200, config.get_delivery_port());
}

TEST(ConfigTest, TestAssignment){
    std::string log_path = "../../scheduler.log";
    std::string log_level = "DEBUG";
    std::string delivery_ip = "192.168.0.1";
    int delivery_port = 1024;
    char delivery_port_str[10];
    sprintf(delivery_port_str, "%d", delivery_port);

    setenv("SCHEDULER_LOG_PATH", log_path.c_str(), 1);
    setenv("SCHEDULER_LOG_LEVEL", log_level.c_str(), 1);
    setenv("SCHEDULER_DELIVERY_IP", delivery_ip.c_str(), 1);
    setenv("SCHEDULER_DELIVERY_PORT", delivery_port_str, 1);

    config config;
    ASSERT_EQ(log_path, config.get_log_path());
    ASSERT_EQ(log_level, config.get_log_level());
    ASSERT_EQ(delivery_ip, config.get_delivery_ip());
    ASSERT_EQ(delivery_port, config.get_delivery_port());
}