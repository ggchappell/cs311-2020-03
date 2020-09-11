// except.cpp
// Glenn G. Chappell
// 2020-09-11
//
// For CS 311 Fall 2020
// Demo of throwing & catching exceptions

// ********************************************************************
// * THIS CODE IS FOR DEMONSTRATION PURPOSES ONLY. DO NOT IMITATE IT! *
// * NORMALLY, YOU MAY WRITE A THROW OR A CATCH, BUT NOT BOTH.        *
// ********************************************************************

// Preprocessor constants that affect program behavior
// Each should be 0 (false) or 1 (true)
#define FUNC_THROW  0  // Does function foo throw?
#define DCTOR_THROW 0  // Does class Bar dctor throw?
#define CATCH_OOR   1  // Does function main catch out_of_range?

// TODO:
// For each of the following sets of values:
// - Set the above constants to the given values.
// - Try to predict what the program will do.
// - Execute the program, and see if you were correct.
// 0, 0, 1
// 1, 0, 0
// 1, 0, 1
// 0, 1, 1
// 1, 1, 1

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <stdexcept>
using std::out_of_range;
using std::runtime_error;


// userPause
// Wait for user to press ENTER: read all chars through first newline.
void userPause()
{
    std::cout.flush();
    while (std::cin.get() != '\n') ;
}


// class Bar
// Empty class that prints messages and might throw.
// Invariants: None.
class Bar {
public:
    // default ctor
    // Does not throw.
    Bar()
    {
        cout << "Bar default ctor" << endl;
    }

    // Dctor
    // Throws out_of_range if DCTOR_THROW set; does not throw otherwise.
    ~Bar() noexcept(false)  // EVIL CODE!
    {
        cout << "Bar dctor" << endl;
#if DCTOR_THROW
        cout << "Bar dctor throwing out_of_range" << endl;
        throw out_of_range("Thrown by Bar dctor");
#endif
    }

    // No other Big Five member functions
    Bar(const Bar & other) = delete;
    Bar(Bar && other) = delete;
    Bar & operator=(const Bar & rhs) = delete;
    Bar & operator=(Bar && rhs) = delete;

};  // End class Bar


// foo
// A function that might throw.
// Throws out_of_range if FUNC_THROW set; does not throw otherwise.
void foo()
{
    Bar x;
    cout << "foo 1" << endl;
#if FUNC_THROW
    cout << "foo throwing out_of_range" << endl;
    throw out_of_range("Thrown by foo");
#endif
    cout << "foo 2" << endl;
}


// main
// Prints message and calls function foo.
// Catches out_of_range if CATCH_OOR set; catches runtime_error (which
// is never thrown in this program) otherwise.
int main()
{
    cout << "Exception Throwing & Catching"
         << " - see source code for changes to make" << endl;
    cout << endl;
    cout << "main 1" << endl;

    try
    {
        cout << "main 2" << endl;
        foo();
        cout << "main 3" << endl;
    }
#if CATCH_OOR
    catch (out_of_range & e)
#else
    catch (runtime_error & e)
#endif
    {
        cout << "Caught exception. Message = " << e.what() << endl;
    }

    cout << "main 4" << endl;
    cout << endl;

    // Wait for user
    cout << "Press ENTER to quit ";
    userPause();
}

