#ifndef COMMON_H
#define COMMON_H

#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/date_time/c_local_time_adjustor.hpp>

using namespace boost::posix_time;

ptime utc_to_local(ptime& utc_date_time) {
    return boost::date_time::c_local_adjustor<ptime>::utc_to_local(utc_date_time);
}


#endif