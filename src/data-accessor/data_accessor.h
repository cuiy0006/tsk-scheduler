#ifndef DATA_ACCESSOR_H
#define DATA_ACCESSOR_H

#include <unordered_map>
#include <functional>
#include <task.h>

namespace general::scheduler {

class data_accessor {

public:
    using task_ptr_t = std::shared_ptr<task>;

    using tasks_map_t = std::unordered_map<std::string, task_ptr_t>;

    using get_tasks_callback = std::function<void(const tasks_map_t&)>;

    virtual void get_tasks_async(get_tasks_callback cb) = 0;

    virtual void get_tasks(tasks_map_t& tasks_map) = 0;

};

}

#endif