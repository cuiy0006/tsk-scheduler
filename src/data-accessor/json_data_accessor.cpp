// system
#include <fstream>

#include "json_data_accessor.h"
#include "data_accessor.h"
#include <common/common.hpp>
#include <boost/log/trivial.hpp>


namespace general::scheduler {

using namespace boost::posix_time;

json_data_accessor::json_data_accessor(boost::asio::io_service& io_service, config& config)
    : data_accessor(io_service, config) {
}

void json_data_accessor::get_tasks(tasks_map_t& tasks_map, bool all) {
    std::ifstream tasks_file(m_config.get_task_json_path());
    json tasks_object;
    tasks_file >> tasks_object;

    auto& tasks = tasks_object["tasks"];

    for(auto it = tasks.begin(); it != tasks.end(); ++it){
        json o = *it;
        
        std::string&& modified_on_str = o["modifiedOn"];
        std::string&& start_datetime_str = o["startDateTime"];
        std::string&& end_datetime_str = o["endDateTime"];
        std::string&& task_id = o["taskId"];
        int interval = o["interval"];
        bool active = o["active"] == 1? true : false;

        if(all && !active) {
            continue;
        }

        task t(task_id);
        t.set_interval(interval);
        t.set_start_date_time(start_datetime_str);
        t.set_end_date_time(end_datetime_str);
        t.set_modified_on(modified_on_str);
        t.set_active(active);

        time_duration td = seconds(m_config.get_refresh_interval());
        ptime now = microsec_clock::universal_time();

        // only get modified tasks
        bool modified = is_in_window(now - td, now, t.get_modified_on());

        // now is in window
        bool is_now_in_window = is_in_window(t.get_start_date_time(), t.get_end_date_time(), now);
        // next refresh is in window 
        bool is_future_in_window = is_in_window(t.get_start_date_time(), t.get_end_date_time(), now + td);
        
        if(!all && !modified) {
            if(!is_now_in_window && !is_future_in_window){
                continue;
            } else {
                if(!active) {
                    continue;
                }
            }
        }
        
        tasks_map.emplace(task_id, std::move(t));
    }
}

void json_data_accessor::get_tasks_async(get_tasks_callback cb, bool all) {
    this->m_io_service.dispatch([this, cb, all](){
        tasks_map_t tasks_map;
        this->get_tasks(tasks_map, all);
        cb(tasks_map);
    });
}

}



