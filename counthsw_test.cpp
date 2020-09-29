// counthsw_test.cpp
// Glenn G. Chappell
// 2020-09-28
//
// For CS 311 Fall 2020
// Test program for function countHSW
// For Project 4, Exercise A
// Uses the "doctest" unit-testing framework, version 2
// Requires doctest.h, counthsw.h, counthsw.cpp

// Includes for code to be tested
#include "counthsw.h"        // For countHSW
#include "counthsw.h"        // Double-inclusion check, for testing only

// Includes for the "doctest" unit-testing framework
#define DOCTEST_CONFIG_IMPLEMENT
                             // We write our own main
#define DOCTEST_CONFIG_SUPER_FAST_ASSERTS
                             // Reduce compile time
#include "doctest.h"         // For doctest

// Includes for all test programs
#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <string>
using std::string;

// Additional includes for this test program
// (None)


// *********************************************************************
// Helper Functions/Classes for This Test Program
// *********************************************************************


// (None)


// *********************************************************************
// Test Cases
// *********************************************************************


TEST_CASE( "n x 1 and 1 x n boards" )
{
    SUBCASE( "All 3 x 1 boards" )
    {
        REQUIRE( countHSW(3,1, 0,0, 1,0, 2,0) == 1 );
        REQUIRE( countHSW(3,1, 0,0, 2,0, 1,0) == 1 );
        REQUIRE( countHSW(3,1, 1,0, 0,0, 2,0) == 0 );
        REQUIRE( countHSW(3,1, 1,0, 2,0, 0,0) == 0 );
        REQUIRE( countHSW(3,1, 2,0, 0,0, 1,0) == 1 );
        REQUIRE( countHSW(3,1, 2,0, 1,0, 0,0) == 1 );
    }

    SUBCASE( "All 1 x 3 boards" )
    {
        REQUIRE( countHSW(1,3, 0,0, 0,1, 0,2) == 1 );
        REQUIRE( countHSW(1,3, 0,0, 0,2, 0,1) == 1 );
        REQUIRE( countHSW(1,3, 0,1, 0,0, 0,2) == 0 );
        REQUIRE( countHSW(1,3, 0,1, 0,2, 0,0) == 0 );
        REQUIRE( countHSW(1,3, 0,2, 0,0, 0,1) == 1 );
        REQUIRE( countHSW(1,3, 0,2, 0,1, 0,0) == 1 );
    }

    SUBCASE( "All 4 x 1 boards" )
    {
        REQUIRE( countHSW(4,1, 0,0, 1,0, 2,0) == 0 );
        REQUIRE( countHSW(4,1, 0,0, 1,0, 3,0) == 1 );
        REQUIRE( countHSW(4,1, 0,0, 2,0, 1,0) == 0 );
        REQUIRE( countHSW(4,1, 0,0, 2,0, 3,0) == 0 );
        REQUIRE( countHSW(4,1, 0,0, 3,0, 1,0) == 1 );
        REQUIRE( countHSW(4,1, 0,0, 3,0, 2,0) == 0 );
        REQUIRE( countHSW(4,1, 1,0, 0,0, 2,0) == 0 );
        REQUIRE( countHSW(4,1, 1,0, 0,0, 3,0) == 0 );
        REQUIRE( countHSW(4,1, 1,0, 2,0, 0,0) == 0 );
        REQUIRE( countHSW(4,1, 1,0, 2,0, 3,0) == 0 );
        REQUIRE( countHSW(4,1, 1,0, 3,0, 0,0) == 0 );
        REQUIRE( countHSW(4,1, 1,0, 3,0, 2,0) == 0 );
        REQUIRE( countHSW(4,1, 2,0, 0,0, 1,0) == 0 );
        REQUIRE( countHSW(4,1, 2,0, 0,0, 3,0) == 0 );
        REQUIRE( countHSW(4,1, 2,0, 1,0, 0,0) == 0 );
        REQUIRE( countHSW(4,1, 2,0, 1,0, 3,0) == 0 );
        REQUIRE( countHSW(4,1, 2,0, 3,0, 0,0) == 0 );
        REQUIRE( countHSW(4,1, 2,0, 3,0, 1,0) == 0 );
        REQUIRE( countHSW(4,1, 3,0, 0,0, 1,0) == 0 );
        REQUIRE( countHSW(4,1, 3,0, 0,0, 2,0) == 1 );
        REQUIRE( countHSW(4,1, 3,0, 1,0, 0,0) == 0 );
        REQUIRE( countHSW(4,1, 3,0, 1,0, 2,0) == 0 );
        REQUIRE( countHSW(4,1, 3,0, 2,0, 0,0) == 1 );
        REQUIRE( countHSW(4,1, 3,0, 2,0, 1,0) == 0 );
    }

    SUBCASE( "All 1 x 4 boards" )
    {
        REQUIRE( countHSW(1,4, 0,0, 0,1, 0,2) == 0 );
        REQUIRE( countHSW(1,4, 0,0, 0,1, 0,3) == 1 );
        REQUIRE( countHSW(1,4, 0,0, 0,2, 0,1) == 0 );
        REQUIRE( countHSW(1,4, 0,0, 0,2, 0,3) == 0 );
        REQUIRE( countHSW(1,4, 0,0, 0,3, 0,1) == 1 );
        REQUIRE( countHSW(1,4, 0,0, 0,3, 0,2) == 0 );
        REQUIRE( countHSW(1,4, 0,1, 0,0, 0,2) == 0 );
        REQUIRE( countHSW(1,4, 0,1, 0,0, 0,3) == 0 );
        REQUIRE( countHSW(1,4, 0,1, 0,2, 0,0) == 0 );
        REQUIRE( countHSW(1,4, 0,1, 0,2, 0,3) == 0 );
        REQUIRE( countHSW(1,4, 0,1, 0,3, 0,0) == 0 );
        REQUIRE( countHSW(1,4, 0,1, 0,3, 0,2) == 0 );
        REQUIRE( countHSW(1,4, 0,2, 0,0, 0,1) == 0 );
        REQUIRE( countHSW(1,4, 0,2, 0,0, 0,3) == 0 );
        REQUIRE( countHSW(1,4, 0,2, 0,1, 0,0) == 0 );
        REQUIRE( countHSW(1,4, 0,2, 0,1, 0,3) == 0 );
        REQUIRE( countHSW(1,4, 0,2, 0,3, 0,0) == 0 );
        REQUIRE( countHSW(1,4, 0,2, 0,3, 0,1) == 0 );
        REQUIRE( countHSW(1,4, 0,3, 0,0, 0,1) == 0 );
        REQUIRE( countHSW(1,4, 0,3, 0,0, 0,2) == 1 );
        REQUIRE( countHSW(1,4, 0,3, 0,1, 0,0) == 0 );
        REQUIRE( countHSW(1,4, 0,3, 0,1, 0,2) == 0 );
        REQUIRE( countHSW(1,4, 0,3, 0,2, 0,0) == 1 );
        REQUIRE( countHSW(1,4, 0,3, 0,2, 0,1) == 0 );
    }

    SUBCASE( "Various n x 1 boards with n > 4" )
    {
        REQUIRE( countHSW(  5,1,   0,0,   1,0,   4,0) == 1 );
        REQUIRE( countHSW(  5,1,   2,0,   0,0,   4,0) == 0 );
        REQUIRE( countHSW(  7,1,   2,0,   0,0,   4,0) == 0 );
        REQUIRE( countHSW(  8,1,   7,0,   6,0,   0,0) == 1 );
        REQUIRE( countHSW( 20,1,   0,0,  19,0,   1,0) == 1 );
        REQUIRE( countHSW( 25,1,  24,0,   0,0,  22,0) == 0 );
        REQUIRE( countHSW(299,1, 298,0,   0,0, 297,0) == 1 );
        REQUIRE( countHSW(299,1, 297,0, 298,0,   0,0) == 0 );
    }

    SUBCASE( "Various 1 x n boards with n > 4" )
    {
        REQUIRE( countHSW(1,  5, 0,  4, 0,  3, 0,0) == 1 );
        REQUIRE( countHSW(1,  5, 0,  0, 0,  1, 0,4) == 1 );
        REQUIRE( countHSW(1,  6, 0,  1, 0,  5, 0,0) == 0 );
        REQUIRE( countHSW(1,  6, 0,  5, 0,  0, 0,4) == 1 );
        REQUIRE( countHSW(1, 33, 0, 15, 0,  0, 0,1) == 0 );
        REQUIRE( countHSW(1, 50, 0,  0, 0, 49, 0,1) == 1 );
        REQUIRE( countHSW(1,298, 0,296, 0,297, 0,0) == 0 );
        REQUIRE( countHSW(1,299, 0,  0, 0,298, 0,1) == 1 );
    }
}


TEST_CASE( "Small boards" )
{
    SUBCASE( "Various small boards" )
    {
        REQUIRE( countHSW(2,2, 0,0, 1,0, 1,1) ==   1 );
        REQUIRE( countHSW(2,2, 1,0, 1,1, 0,0) ==   1 );
        REQUIRE( countHSW(8,2, 1,0, 1,1, 0,0) ==   0 );
        REQUIRE( countHSW(8,2, 1,0, 0,0, 5,0) ==  96 );
        REQUIRE( countHSW(2,8, 0,1, 1,1, 0,0) ==   0 );
        REQUIRE( countHSW(2,8, 0,1, 0,0, 1,4) ==  64 );
        REQUIRE( countHSW(3,3, 0,0, 0,2, 1,1) ==   6 );
        REQUIRE( countHSW(4,4, 0,2, 2,1, 3,3) == 181 );
        REQUIRE( countHSW(3,5, 0,0, 1,1, 2,4) == 355 );
        REQUIRE( countHSW(2,3, 1,0, 0,1, 1,2) ==   1 );
        REQUIRE( countHSW(3,2, 0,0, 1,0, 1,1) ==   0 );
        REQUIRE( countHSW(4,2, 2,1, 3,0, 0,1) ==   4 );
        REQUIRE( countHSW(3,4, 1,1, 0,3, 2,3) ==  16 );
    }
}


TEST_CASE( "Large boards" )
{
    SUBCASE( "Various large boards" )
    {
        REQUIRE( countHSW(3, 6, 0,0, 1,0, 1,1) ==  945 );
        REQUIRE( countHSW(4, 5, 3,1, 2,0, 0,0) == 5076 );
        REQUIRE( countHSW(5, 4, 2,2, 0,0, 1,3) == 5488 );
        REQUIRE( countHSW(2,10, 0,1, 0,0, 1,0) ==    0 );
        REQUIRE( countHSW(6, 3, 5,2, 4,1, 1,2) == 1047 );
        REQUIRE( countHSW(9, 2, 0,1, 4,0, 1,0) ==  128 );
        REQUIRE( countHSW(7, 2, 3,0, 0,1, 5,0) ==   48 );
    }
}


TEST_CASE( "Slide Examples" )
{
    SUBCASE( "Examples from \"Thoughts on Project 4\" slides" )
    {
        REQUIRE( countHSW(4,2, 1,0, 0,0, 3,1) ==     4 );
        REQUIRE( countHSW(3,2, 2,0, 1,0, 2,1) ==     2 );
        REQUIRE( countHSW(4,1, 1,0, 0,0, 3,0) ==     0 );
        REQUIRE( countHSW(5,4, 4,3, 4,2, 0,0) == 40887 );
    }
}


// *********************************************************************
// Main Program
// *********************************************************************


// userPause
// Wait for user to press ENTER: read all chars through first newline.
void userPause()
{
    std::cout.flush();
    while (std::cin.get() != '\n') ;
}


// Main program
// Run all tests. Prompt for ENTER before exiting.
int main(int argc,
         char *argv[])
{
    const std::string tname = "function countHSW"
                              " - CS 311 Proj 4, Ex A";
                             // Printable name for this test suite
    doctest::Context dtcontext;
                             // Primary doctest object
    int dtresult;            // doctest return code; for return by main

    // Handle command line
    dtcontext.applyCommandLine(argc, argv);
    dtresult = 0;            // doctest flags no command-line errors
                             //  (strange but true)

    if (!dtresult)           // Continue only if no command-line error
    {
        // Run test suites
        std::cout << "BEGIN tests for "
                  << tname << std::endl << std::endl;
        dtresult = dtcontext.run();
        std::cout << "END tests for "
                  << tname << std::endl << std::endl;
    }

    // If we want to do something else here, then we need to check
    // context.shouldExit() first.

    // Wait for user
    std::cout << "Press ENTER to quit ";
    userPause();

    // Program return value is return code from doctest
    return dtresult;
}

