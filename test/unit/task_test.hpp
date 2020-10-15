#include "gtest/gtest.h"
#include <task.h>
#include <string.h>
#include <iostream>
#include <sstream> 

using namespace general::scheduler;


TEST(TaskTest, TestDefault){
    std::string task_id = "d79ff2f3-965d-4bee-890e-ec2295588642";
    std::string start_date_time = "2002-06-20 23:59:59.123";
    std::string end_date_time = "1989-12-31 00:00:00.321";
    
    task task(task_id);

    task.set_interval(20);
    task.set_start_date_time(start_date_time);
    task.set_end_date_time(end_date_time);

    EXPECT_EQ(task_id, task.get_task_id());
    EXPECT_EQ(20, task.get_interval());
    EXPECT_EQ("2002-Jun-20 23:59:59.123000", to_simple_string(task.get_start_date_time()));
    EXPECT_EQ("1989-Dec-31 00:00:00.321000", to_simple_string(task.get_end_date_time()));
    
    EXPECT_EQ("2002-Jun-20 19:59:59.123000", to_simple_string(task.get_start_date_time_local()));
    EXPECT_EQ("1989-Dec-30 19:00:00.321000", to_simple_string(task.get_end_date_time_local()));
}