// timeofday.h  UNFINISHED
// Glenn G. Chappell
// 2020-08-28
//
// For CS 311 Fall 2020
// Header for class TimeOfDay
// Time of day: hours, minutes, seconds

#ifndef FILE_TIMEOFDAY_H_INCLUDED
#define FILE_TIMEOFDAY_H_INCLUDED

#include <ostream>  // For std::ostream


// *********************************************************************
// class TimeOfDay - Class definition
// *********************************************************************


// class TimeOfDay
// Time of day: hours, minutes, seconds.
class TimeOfDay {

// ***** TimeOfDay: Ctors, dctor, op= *****
public:

    // Default ctor
    // Set time to midnight.
    TimeOfDay() = default;  // WE PROBABLY NEED TO WRITE THIS!!!

    // Ctor from hours, minutes, seconds
    // Set time to given # of hours, minutes, seconds past midnight.
    // Extreme values of hh, mm, ss are corrected by shifting some whole
    // number of days forward or backward.
    TimeOfDay(int hh,
              int mm,
              int ss)
    {}  // WRITE THIS!!!

    // Big 5: use automatically generated versions
    ~TimeOfDay() = default;
    TimeOfDay(const TimeOfDay & other) = default;
    TimeOfDay(TimeOfDay && other) = default;
    TimeOfDay & operator=(const TimeOfDay & other) = default;
    TimeOfDay & operator=(TimeOfDay && other) = default;

// ***** TimeOfDay: General public operators *****
public:

    // op++ [pre]
    // Move time one second forward.
    TimeOfDay & operator++()
    {}  // WRITE THIS!!!

    // op++ [post]
    // Move time one second forward.
    TimeOfDay operator++(int dummy)
    {}  // WRITE THIS!!!

    // op-- [pre]
    // Move time one second backward.
    TimeOfDay & operator--()
    {}  // WRITE THIS!!!

    // op-- [post]
    // Move time one second backward.
    TimeOfDay operator--(int dummy)
    {}  // WRITE THIS!!!

// ***** TimeOfDay: General public functions *****
public:

    // getTime
    // Return hours, minutes, seconds in reference parameters.
    void getTime(int & hh,
                 int & mm,
                 int & ss) const
    {}  // WRITE THIS!!!

    // setTime
    // Set time to given # of hours, minutes, seconds past midnight.
    // Extreme values of hh, mm, ss are corrected by shifting some whole
    // number of days forward or backward.
    void setTime(int hh,
                 int mm,
                 int ss)
    {}  // WRITE THIS!!!

};  // End class TimeOfDay


// *********************************************************************
// class TimeOfDay - Declarations of associated global operators
// *********************************************************************


// operator<< (ostream,TimeOfDay)
// Prints given TimeOfDay object as "hh:mm:ss", with hh padded on the
// left with blanks, and mm, ss padded on the left with zeroes.
std::ostream & operator<<(std::ostream & out,
                          const TimeOfDay & t);


#endif  //#ifndef FILE_TIMEOFDAY_H_INCLUDED

