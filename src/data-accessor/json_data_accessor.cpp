
#include "json_data_accessor.h"
#include "data_accessor.h"

namespace general::scheduler {

json_data_accessor::json_data_accessor(boost::asio::io_service& io_service)
    : data_accessor(io_service) {
}

void json_data_accessor::get_tasks(tasks_map_t& tasks_map) {
    
}

void json_data_accessor::get_tasks_async(get_tasks_callback cb) {

}

}



