#ifndef TASK_H
#define TASK_H

#include <string>
#include "boost/date_time/posix_time/posix_time.hpp"
#include "boost/date_time/c_local_time_adjustor.hpp"

using namespace boost::posix_time;

namespace general::scheduler {

class task {

public:
    task(std::string& task_id);
    void set_interval(int interval);
    void set_start_date_time(std::string& start_date_time_str);
    void set_end_date_time(std::string& end_date_time_str);

    std::string get_task_id() const;
    int get_interval() const;
    ptime get_start_date_time() const;
    ptime get_end_date_time() const;
    ptime get_start_date_time_local() const;
    ptime get_end_date_time_local() const;

private:
    std::string& m_task_id;
    int m_interval;
    ptime m_start_date_time;
    ptime m_end_date_time;

};

std::ostream &operator<<(std::ostream &os, task const &tsk);

}

#endif