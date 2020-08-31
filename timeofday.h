// timeofday.h
// Glenn G. Chappell
// Started: 2020-08-28
// Updated: 2020-08-31
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
// Invariants:
//   0 <= _secs < 24*60*60.
class TimeOfDay {

// ***** TimeOfDay: Ctors, dctor, op= *****
public:

    // Default ctor
    // Set time to midnight.
    TimeOfDay()
    {
        setTime(0, 0, 0);
    }

    // Ctor from hours, minutes, seconds
    // Set time to given # of hours, minutes, seconds past midnight.
    // Extreme values of hh, mm, ss are corrected by shifting some whole
    // number of days forward or backward.
    // Pre:
    //   0 <= hh < 24
    //   0 <= mm < 60
    //   0 <= ss < 60
    TimeOfDay(int hh,
              int mm,
              int ss)
    {
        setTime(hh, mm, ss);
    }

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
    {
        ++_secs;
        if (_secs == 24*60*60)
            _secs = 0;
        return *this;
    }

    // op++ [post]
    // Move time one second forward.
    TimeOfDay operator++([[maybe_unused]] int dummy)
    {
        auto save = *this;
        ++(*this);
        return save;
    }

    // op-- [pre]
    // Move time one second backward.
    TimeOfDay & operator--()
    {
        --_secs;
        if (_secs == -1)
            _secs = 24*60*60-1;
        return *this;
    }

    // op-- [post]
    // Move time one second backward.
    TimeOfDay operator--([[maybe_unused]] int dummy)
    {
        auto save = *this;
        --(*this);
        return save;
    }

// ***** TimeOfDay: General public functions *****
public:

    // getTime
    // Return hours, minutes, seconds in reference parameters.
    void getTime(int & hh,
                 int & mm,
                 int & ss) const;

    // setTime
    // Set time to given # of hours, minutes, seconds past midnight.
    // Extreme values of hh, mm, ss are corrected by shifting some whole
    // number of days forward or backward.
    // Pre:
    //   0 <= hh < 24
    //   0 <= mm < 60
    //   0 <= ss < 60
    void setTime(int hh,
                 int mm,
                 int ss);

// ***** TimeOfDay: Data members *****
private:

    int _secs;  // Seconds past midnight (range 0 .. 24*60*60-1)

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

