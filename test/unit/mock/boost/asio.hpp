#ifndef ASIO_MOCK_H
#define ASIO_MOCK_H

#include <functional>

namespace boost::asio {

class io_service {

public:
    using dispatch_fn_t = std::function<void()>;

    void dispatch(dispatch_fn_t fn) {
        fn();
    }
    
};

}

#endif