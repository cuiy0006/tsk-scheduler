#include "window.h"

namespace general::scheduler {

window::window(const window_info& wi, const std::string& task_id)
    : m_task_id(task_id),
      m_window_info(std::move(wi)) {
}



}