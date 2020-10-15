#include "task.h"

namespace general::scheduler {

task::task(std::string& task_id)
    : m_task_id(task_id) {
}

void task::set_interval(int interval) {
    m_interval = interval;
}

void task::set_start_date_time(std::string& start_date_time_str) {
    m_start_date_time = time_from_string(start_date_time_str);
}

void task::set_end_date_time(std::string& end_date_time_str) {
    m_end_date_time = time_from_string(end_date_time_str);
}

const std::string task::get_task_id() const {
    return m_task_id;
}

int task::get_interval() const {
    return m_interval;
}

ptime task::get_start_date_time() const {
    return m_start_date_time;
}

ptime task::get_end_date_time() const {
    return m_end_date_time;
}

ptime task::get_start_date_time_local() const {
    return boost::date_time::c_local_adjustor<ptime>::utc_to_local(m_start_date_time);
}

ptime task::get_end_date_time_local() const {
    return boost::date_time::c_local_adjustor<ptime>::utc_to_local(m_end_date_time);
}


std::ostream &operator<<(std::ostream &os, task const &tsk) { 
    return os << "task id: " << tsk.get_task_id() << "\n"
                << "task interval: " << tsk.get_interval() << "\n"
                << "task start date time: " << tsk.get_start_date_time() << "\n"
                << "task end date time: " << tsk.get_end_date_time();
}

}