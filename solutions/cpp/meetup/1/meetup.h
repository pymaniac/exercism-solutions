#pragma once

#include <boost/date_time/gregorian/gregorian.hpp>

using namespace boost::gregorian;
typedef nth_day_of_the_week_in_month ndow;

namespace meetup {

// TODO: add your solution here
class scheduler {
    private:
    greg_month _month;
    int _year;

    date get_nth_teeth(greg_weekday gw) const {
        date d(_year, _month, 13);
        return next_weekday(d, gw);
    }

    date get_date(ndow::week_num w, int dayid) const {
        ndow nth(w, greg_weekday(dayid), _month);
        return nth.get_date(_year);
    }

    date get_last_date(int dayid) const {
        last_day_of_the_week_in_month lwdm(greg_weekday(dayid), _month);
        return lwdm.get_date(_year);
    }
    
    public:
    scheduler(greg_month m, int year) : _month(m), _year(year) {}
    #define DEFINE_TEENTH(DAY, ID) \
        date DAY##teenth() const { return get_nth_teeth(ID);}

    DEFINE_TEENTH(mon, 1);
    DEFINE_TEENTH(tues, 2);
    DEFINE_TEENTH(wednes, 3);
    DEFINE_TEENTH(thurs, 4);
    DEFINE_TEENTH(fri, 5);
    DEFINE_TEENTH(satur, 6);
    DEFINE_TEENTH(sun, 0);
    #undef DEFINE_TEENTH
    #define DEFINE_WEEKDAYS(WEEKNAME) \
        date WEEKNAME##_monday() const { return get_date(ndow::WEEKNAME, 1); } \
        date WEEKNAME##_tuesday() const { return get_date(ndow::WEEKNAME, 2); } \
        date WEEKNAME##_wednesday() const { return get_date(ndow::WEEKNAME, 3); } \
        date WEEKNAME##_thursday() const { return get_date(ndow::WEEKNAME, 4); } \
        date WEEKNAME##_friday() const { return get_date(ndow::WEEKNAME, 5); } \
        date WEEKNAME##_saturday() const { return get_date(ndow::WEEKNAME, 6); } \
        date WEEKNAME##_sunday() const { return get_date(ndow::WEEKNAME, 0); } 

    DEFINE_WEEKDAYS(first);
    DEFINE_WEEKDAYS(second);
    DEFINE_WEEKDAYS(third);
    DEFINE_WEEKDAYS(fourth);
    #undef DEFINE_WEEKDAYS

    date last_monday() const { return get_last_date(1); }
    date last_tuesday() const { return get_last_date(2); }
    date last_wednesday() const { return get_last_date(3); }
    date last_thursday() const { return get_last_date(4); }
    date last_friday() const { return get_last_date(5); }
    date last_saturday() const { return get_last_date(6); }
    date last_sunday() const { return get_last_date(0); }
};
    
}  // namespace meetup
