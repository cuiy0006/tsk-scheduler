
#include "json_data_accessor.h"
#include "data_accessor.h"
#include <fstream>
#include <iostream>

namespace general::scheduler {

json_data_accessor::json_data_accessor(boost::asio::io_service& io_service, config& config)
    : data_accessor(io_service, config) {
}

void json_data_accessor::get_tasks(tasks_map_t& tasks_map) {
    std::ifstream tasks_file(m_config.get_task_json_path());
    json tasks_object;
    tasks_file >> tasks_object;

    auto& tasks = tasks_object["tasks"];

    for(auto it = tasks.begin(); it != tasks.end(); ++it){
        json o = *it;
        
        std::string&& task_id = o["taskId"];
        int interval = o["interval"];
        std::string&& start_datetime = o["startDateTime"];
        std::string&& end_datetime = o["endDateTime"];

        task t(task_id);
        t.set_interval(interval);
        t.set_start_date_time(start_datetime);
        t.set_end_date_time(end_datetime);

        tasks_map.emplace(task_id, std::move(t));
    }
}

void json_data_accessor::get_tasks_async(get_tasks_callback cb) {
    this->m_io_service.dispatch([this, cb](){
        tasks_map_t tasks_map;
        this->get_tasks(tasks_map);
        cb(tasks_map);
    });
}

}



