// fsarray.h  INCOMPLETE
// VERSION 5
// Glenn G. Chappell
// Started: 2020-10-14
// Updated: 2020-10-21
//
// For CS 311 Fall 2020
// Header for class FSArray
// Frightfully smart array of int
// Preliminary to Project 5

// History:
// - v1:
//   - Skeleton only: header & source files, #ifndef, #include, empty
//     class definition.
// - v2:
//   - Add member types value_type, size_type, iterator, const_iterator.
//   - Add dummy versions (at least) of all member functions, including
//     dummy return statements for non-void functions. Package compiles.
//   - Add data members.
//   - Add class invariants.
//   - Write (untested versions of) the following member functions:
//     default ctor, ctor from size (these two are single func), dctor,
//     op[], size, empty, begin, end, push_back, pop_back.
// - v3:
//   - Document exception-safety guarantees for most functions.
//   - Write copy ctor.
// - v4:
//   - Revise class invariants to allow for _data being nullptr if _size
//     is zero.
//   - Write move ctor.
//   - Mark various functions as noexcept.
//   - Put definitions of copy & move functions, resize, insert, erase,
//     swap in source file.
// - v5:
//   - Add _capacity data member.
//   - Add constant DEFAULT_CAP and use it in setting the capacity in
//     default ctor/ctor from size.

#ifndef FILE_FSARRAY_H_INCLUDED
#define FILE_FSARRAY_H_INCLUDED

#include <cstddef>
// For std::size_t
#include <algorithm>
// For std::max


// *********************************************************************
// class FSArray - Class definition
// *********************************************************************


// class FSArray
// Frightfully Smart Array of int.
// Resizable, copyable/movable, exception-safe.
// Invariants:
//     0 <= _size <= _capacity.
//     _data points to an array of value_type, allocated with new [],
//      owned by *this, holding _capacity value_type values -- UNLESS
//      _capacity == 0, in which case _data may be nullptr.
class FSArray {

// ***** FSArray: types *****
public:

    // value_type: type of data items
    using value_type = int;

    // size_type: type of sizes & indices
    using size_type = std::size_t;

    // iterator, const_iterator: random-access iterator types
    using iterator = value_type *;
    using const_iterator = const value_type *;

// ***** FSArray: internal-use constants *****
private:

    // Capacity of default-constructed object
    enum { DEFAULT_CAP = 16 };

// ***** FSArray: ctors, op=, dctor *****
public:

    // Default ctor & ctor from size
    // Strong Guarantee
    explicit FSArray(size_type size=0)
        :_capacity(std::max(size, size_type(DEFAULT_CAP))),
            // _capacity must be declared before _data
         _size(size),
         _data(_capacity == 0 ? nullptr : new value_type[_capacity])
    {}

    // Copy ctor
    // Strong Guarantee
    FSArray(const FSArray & other);

    // Move ctor
    // No-Throw Guarantee
    FSArray(FSArray && other) noexcept;

    // Copy assignment
    // ??? Guarantee
    FSArray & operator=(const FSArray & other);

    // Move assignment
    // No-Throw Guarantee
    FSArray & operator=(FSArray && other) noexcept;

    // Dctor
    // No-Throw Guarantee
    ~FSArray()
    {
        delete [] _data;
    }

// ***** FSArray: general public operators *****
public:

    // operator[] - non-const & const
    // Pre:
    //     ???
    // No-Throw Guarantee
    value_type & operator[](size_type index) noexcept
    {
        return _data[index];
    }
    const value_type & operator[](size_type index) const noexcept
    {
        return _data[index];
    }

// ***** FSArray: general public functions *****
public:

    // size
    // No-Throw Guarantee
    size_type size() const noexcept
    {
        return _size;
    }

    // empty
    // No-Throw Guarantee
    bool empty() const noexcept
    {
        return size() == 0;
    }

    // begin - non-const & const
    // No-Throw Guarantee
    iterator begin() noexcept
    {
        return _data;
    }
    const_iterator begin() const noexcept
    {
        return _data;
    }

    // end - non-const & const
    // No-Throw Guarantee
    iterator end() noexcept
    {
        return begin() + size();
    }
    const_iterator end() const noexcept
    {
        return begin() + size();
    }

    // resize
    // ??? Guarantee
    void resize(size_type newsize);

    // insert
    // ??? Guarantee
    iterator insert(iterator pos,
                    const value_type & item);

    // erase
    // ??? Guarantee
    iterator erase(iterator pos);

    // push_back
    // ??? Guarantee
    void push_back(const value_type & item)
    {
        insert(end(), item);
    }

    // pop_back
    // ??? Guarantee
    void pop_back()
    {
        erase(end()-1);
    }

    // swap
    // No-Throw Guarantee
    void swap(FSArray & other) noexcept;

// ***** FSArray: data members *****
private:

    size_type    _capacity;  // Size of our allocated array
    size_type    _size;      // Size of client's data
    value_type * _data;      // Pointer to our array

};  // End class FSArray


#endif  //#ifndef FILE_FSARRAY_H_INCLUDED

