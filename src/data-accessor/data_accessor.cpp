#include "data_accessor.h"

namespace general::scheduler {

data_accessor::data_accessor(boost::asio::io_service& io_service)
    : m_io_service(io_service) {
}

data_accessor::~data_accessor() {
    
}

}