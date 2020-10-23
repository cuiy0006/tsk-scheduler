
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
        std::cout << *it << std::endl;
    }
}

void json_data_accessor::get_tasks_async(get_tasks_callback cb) {

}

}



