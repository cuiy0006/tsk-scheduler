#ifndef COMMON_H
#define COMMON_H

#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/date_time/c_local_time_adjustor.hpp>

using namespace boost::posix_time;

ptime utc_to_local(ptime& utc_date_time);
ptime utc_to_local(ptime&& utc_date_time);

bool is_expired(ptime& end_date_time, ptime& time);
bool is_expired(ptime&& end_date_time, ptime& time);
bool is_expired(ptime& end_date_time, ptime&& time);

bool is_in_window(ptime& start_date_time, ptime& end_date_time, ptime& time);
bool is_in_window(ptime&& start_date_time, ptime&& end_date_time, ptime&& time);
bool is_in_window(ptime&& start_date_time, ptime&& end_date_time, ptime& time);
bool is_in_window(ptime&& start_date_time, ptime& end_date_time, ptime&& time);
bool is_in_window(ptime& start_date_time, ptime&& end_date_time, ptime&& time);

#endif