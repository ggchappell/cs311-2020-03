// timeofday.cpp
// Glenn G. Chappell
// Started: 2020-08-28
// Updated: 2020-08-31
//
// For CS 311 Fall 2020
// Source for class TimeOfDay
// Time of day: hours, minutes, seconds

#include "timeofday.h"  // For class TimeOfDay
#include <ostream>
using std::ostream;


// *********************************************************************
// class TimeOfDay - Definitions of member functions
// *********************************************************************


// TimeOfDay::getTime
// (See header for docs.)
void TimeOfDay::getTime(int & hh,
                        int & mm,
                        int & ss) const
{
    ss = _secs % 60;
    mm = (_secs / 60) % 60;
    hh = _secs / 60 / 60;
}

// TimeOfDay::setTime
// (See header for docs.)
void TimeOfDay::setTime(int hh,
                        int mm,
                        int ss)
{
    _secs = hh*60*60 + mm*60 + ss;
}


// *********************************************************************
// class TimeOfDay - Definitions of associated global operators
// *********************************************************************


// operator<< (ostream,TimeOfDay)
// (See header for docs.)
ostream & operator<<(ostream & out,
                     const TimeOfDay & t)
{
    int hh, mm, ss;
    t.getTime(hh, mm, ss);

    if (hh < 10)  // Left-pad with blank
        out << " ";
    out << hh << ":";

    if (mm < 10)  // Left-pad with zero
        out << "0";
    out << mm << ":";

    if (ss < 10)  // Left-pad with zero
        out << "0";
    out << ss;

    return out;
}

