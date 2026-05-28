#pragma once

#include <boost/date_time/posix_time/posix_time.hpp>

using namespace boost::posix_time;
namespace gigasecond {

    static constexpr int64_t ONE_GIGA_SECOND = 1000000000;
    
// TODO: add your solution here
inline ptime advance(ptime from) {
    return from + seconds(ONE_GIGA_SECOND);
}
    
}  // namespace gigasecond
