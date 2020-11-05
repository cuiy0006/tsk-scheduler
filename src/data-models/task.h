#ifndef TASK_H
#define TASK_H

// system
#include <string>

// boost
#include "boost/date_time/posix_time/posix_time.hpp"
#include "boost/date_time/c_local_time_adjustor.hpp"

using namespace boost::posix_time;

namespace general::scheduler {

class task {

public:
    task();
    task(std::string& task_id);
    void set_task_id(std::string& task_id);
    void set_interval(int interval);
    void set_start_date_time(std::string& start_date_time_str);
    void set_end_date_time(std::string& end_date_time_str);
    void set_modified_on(std::string& modified_on);

    const std::string& get_task_id() const;
    int get_interval() const;
    ptime get_start_date_time() const;
    ptime get_end_date_time() const;
    ptime get_modified_on() const; 

private:
    std::string m_task_id;
    int m_interval;
    ptime m_start_date_time;
    ptime m_end_date_time;
    ptime m_modified_on;
};

std::ostream &operator<<(std::ostream &os, task const &tsk);

}

#endif