// productorder_test.cpp
// Glenn G. Chappell
// 2020-08-31
//
// For CS 311 Fall 2020
// Test program for class ProductOrder
// For Project 1, Exercise A
// Uses the "doctest" unit-testing framework, version 2
// Requires doctest.h, productorder.h, productorder.cpp

// Includes for code to be tested
#include "productorder.h"    // For class ProductOrder
#include "productorder.h"    // Double-inclusion check, for testing only

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
#include <string>
using std::string;
#include <ostream>
using std::ostream;
#include <sstream>
using std::ostringstream;
#include <cstddef>
using std::size_t;
#include <utility>
using std::move;


// *********************************************************************
// Helper Functions/Classes for This Test Program
// *********************************************************************


// class TypeCheck
// This class exists in order to have static member function "check",
// which takes a parameter of a given type, by reference. Objects of
// type TypeCheck<T> cannot be created.
// Usage:
//     TypeCheck<MyType>::check(x)
//      returns true if the type of x is (MyType) or (const MyType),
//      otherwise false.
// Invariants: None.
// Requirements on Types: None.
template<typename T>
class TypeCheck {

private:

    // No default ctor
    TypeCheck() = delete;

    // Uncopyable. Do not define copy/move ctor/assn.
    TypeCheck(const TypeCheck &) = delete;
    TypeCheck(TypeCheck &&) = delete;
    TypeCheck<T> & operator=(const TypeCheck &) = delete;
    TypeCheck<T> & operator=(TypeCheck &&) = delete;

    // Compiler-generated dctor is used (but irrelevant).
    ~TypeCheck() = default;

public:

    // check
    // The function and function template below simulate a single
    // function that takes a single parameter, and returns true iff the
    // parameter has type T or (const T).

    // check (reference-to-const T)
    // Pre: None.
    // Post:
    //     Return is true.
    // Does not throw (No-Throw Guarantee)
    static bool check([[maybe_unused]] const T & param)
    {
        return true;
    }

    // check (reference-to-const non-T)
    // Pre: None.
    // Post:
    //     Return is false.
    // Requirements on types: None.
    // Does not throw (No-Throw Guarantee)
    template <typename OtherType>
    static bool check([[maybe_unused]] const OtherType & param)
    {
        return false;
    }

};  // End class TypeCheck


// *********************************************************************
// Test Cases
// *********************************************************************


TEST_CASE( "Function return types are correct" )
{
    ProductOrder t1;
    ProductOrder t2;

    SUBCASE( "Copy assn returns ProductOrder by ref" )
    {
        [[maybe_unused]] ProductOrder & r(t1 = t2);  // By-reference check
        REQUIRE( TypeCheck<ProductOrder>::check(t1 = t2) );
    }

    SUBCASE( "Move assn returns ProductOrder by ref" )
    {
        ProductOrder t_movable;
        [[maybe_unused]] ProductOrder & r(t1 = move(t_movable));  // By-reference check
        REQUIRE( TypeCheck<ProductOrder>::check(t1 = move(t_movable)) );
    }

    SUBCASE( "ProductOrder::getName returns string by value" )
    {
        [[maybe_unused]] string && rr(t1.getName());  // by-value check
        REQUIRE( TypeCheck<string>::check(t1.getName()) );
    }

    SUBCASE( "ProductOrder::getNumber returns int by value" )
    {
        [[maybe_unused]] int && rr(t1.getNumber());  // by-value check
        REQUIRE( TypeCheck<int>::check(t1.getNumber()) );
    }

    SUBCASE( "ProductOrder::empty returns bool by value" )
    {
        [[maybe_unused]] bool && rr(t1.empty());  // by-value check
        REQUIRE( TypeCheck<bool>::check(t1.empty()) );
    }

    SUBCASE( "ProductOrder::toString returns string by value" )
    {
        [[maybe_unused]] string && rr(t1.toString());  // by-value check
        REQUIRE( TypeCheck<string>::check(t1.toString()) );
    }

    SUBCASE( "ProductOrder::operator++ [pre] returns ProductOrder by ref" )
    {
        [[maybe_unused]] ProductOrder & r(++t1);  // By-reference check
        REQUIRE( TypeCheck<ProductOrder>::check(++t1) );
    }

    SUBCASE( "ProductOrder::operator++ [post] returns ProductOrder by value" )
    {
        [[maybe_unused]] ProductOrder && rr(t1++);  // by-value check
        REQUIRE( TypeCheck<ProductOrder>::check(t1++) );
    }

    SUBCASE( "ProductOrder::operator-- [pre] returns ProductOrder by ref" )
    {
        [[maybe_unused]] ProductOrder & r(--t1);  // By-reference check
        REQUIRE( TypeCheck<ProductOrder>::check(--t1) );
    }

    SUBCASE( "ProductOrder::operator-- [post] returns ProductOrder by value" )
    {
        [[maybe_unused]] ProductOrder && rr(t1--);  // by-value check
        REQUIRE( TypeCheck<ProductOrder>::check(t1--) );
    }

    SUBCASE( "operator==(ProductOrder,ProductOrder) returns bool by value" )
    {
        [[maybe_unused]] bool && rr(t1 == t2);  // by-value check
        REQUIRE( TypeCheck<bool>::check(t1 == t2) );
    }

    SUBCASE( "operator!=(ProductOrder,ProductOrder) returns bool by value" )
    {
        [[maybe_unused]] bool && rr(t1 != t2);  // by-value check
        REQUIRE( TypeCheck<bool>::check(t1 != t2) );
    }

    SUBCASE( "operator<<(ostream,ProductOrder) returns ostream by ref" )
    {
        ostringstream ostr;
        [[maybe_unused]] ostream & r(ostr << t1);  // By-reference check
        REQUIRE( TypeCheck<ostream>::check(ostr << t1) );
    }
}


TEST_CASE( "Functions are const-correct (passes if it compiles)" )
{
    SUBCASE( "Calling functions on a const ProductOrder object" )
    {
        const ProductOrder tc1;

        [[maybe_unused]] string s1 = tc1.getName();   // ProductOrder::getName
        [[maybe_unused]] int w = tc1.getNumber();  // ProductOrder::getNumber
        [[maybe_unused]] bool b = tc1.empty();        // ProductOrder::empty
        [[maybe_unused]] string s2 = tc1.toString();  // ProductOrder::toString

        REQUIRE( 0 == 0 );           // Section passes if it compiles
    }

    SUBCASE( "Taking const ProductOrder arguments" )
    {
        const ProductOrder tc1;
        const ProductOrder tc2;

        ProductOrder t3 = tc1;      // Copy ctor
        t3 = tc1;                    // Copy assn

        [[maybe_unused]] bool b1 = (tc1 == tc2);      // op==(ProductOrder,ProductOrder)
        [[maybe_unused]] bool b2 = (tc1 != tc2);      // op!=(ProductOrder,ProductOrder)
        ostringstream ostr;
        ostr << tc1;                 // op<<(ostring,ProductOrder)

        REQUIRE( 0 == 0 );           // Section passes if it compiles
    }

    SUBCASE( "Taking const string arguments" )
    {
        const string s;

        ProductOrder t(s, 0);       // Data ctor
        t.setName(s);                // ProductOrder::setName

        REQUIRE( 0 == 0 );           // Section passes if it compiles
    }
}


TEST_CASE( "Default-constructed ProductOrder object: blank name, 0 count" )
{
    ProductOrder t1;

    REQUIRE( t1.getName() == "UNSPECIFIED" );
    REQUIRE( t1.getNumber() == 0 );
    REQUIRE( t1.empty() );

    SUBCASE( "Set name" )
    {
        t1.setName("abc");

        REQUIRE( t1.getName() == "abc" );
        REQUIRE( t1.getNumber() == 0 );
        REQUIRE( t1.empty() );
    }

    SUBCASE( "Set number" )
    {
        t1.setNumber(20);

        REQUIRE( t1.getName() == "UNSPECIFIED" );
        REQUIRE( t1.getNumber() == 20 );
        REQUIRE_FALSE( t1.empty() );
    }

    SUBCASE( "Set name, number" )
    {
        t1.setName("def");
        t1.setNumber(30);

        REQUIRE( t1.getName() == "def" );
        REQUIRE( t1.getNumber() == 30 );
        REQUIRE_FALSE( t1.empty() );
    }

    SUBCASE( "Set number, name" )
    {
        t1.setNumber(40);
        t1.setName("ghi");

        REQUIRE( t1.getName() == "ghi" );
        REQUIRE( t1.getNumber() == 40 );
        REQUIRE_FALSE( t1.empty() );
    }
}


TEST_CASE( "Data-constructed ProductOrder object" )
{
    ProductOrder t1("xyz", 100);

    REQUIRE( t1.getName() == "xyz" );
    REQUIRE( t1.getNumber() == 100 );
    REQUIRE_FALSE( t1.empty() );

    SUBCASE( "Set name" )
    {
        t1.setName("abc");

        REQUIRE( t1.getName() == "abc" );
        REQUIRE( t1.getNumber() == 100 );
        REQUIRE_FALSE( t1.empty() );
    }

    SUBCASE( "Set number" )
    {
        t1.setNumber(20);

        REQUIRE( t1.getName() == "xyz" );
        REQUIRE( t1.getNumber() == 20 );
        REQUIRE_FALSE( t1.empty() );
    }

    SUBCASE( "Set name, number" )
    {
        t1.setName("def");
        t1.setNumber(30);

        REQUIRE( t1.getName() == "def" );
        REQUIRE( t1.getNumber() == 30 );
        REQUIRE_FALSE( t1.empty() );
    }

    SUBCASE( "Set number, name" )
    {
        t1.setNumber(40);
        t1.setName("ghi");

        REQUIRE( t1.getName() == "ghi" );
        REQUIRE( t1.getNumber() == 40 );
        REQUIRE_FALSE( t1.empty() );
    }
}


TEST_CASE( "Copied ProductOrder objects" )
{
    SUBCASE( "Copy-constructed ProductOrder object" )
    {
        ProductOrder t1("xyz", 100);
        ProductOrder t2 = t1;

        REQUIRE( t1.getName() == "xyz" );
        REQUIRE( t1.getNumber() == 100 );
        REQUIRE_FALSE( t1.empty() );
        REQUIRE( t2.getName() == "xyz" );
        REQUIRE( t2.getNumber() == 100 );
        REQUIRE_FALSE( t2.empty() );

        t2.setName("abc");
        t2.setNumber(10);

        REQUIRE( t1.getName() == "xyz" );
        REQUIRE( t1.getNumber() == 100 );
        REQUIRE_FALSE( t1.empty() );
        REQUIRE( t2.getName() == "abc" );
        REQUIRE( t2.getNumber() == 10 );
        REQUIRE_FALSE( t2.empty() );

        t1.setName("def");
        t1.setNumber(20);

        REQUIRE( t1.getName() == "def" );
        REQUIRE( t1.getNumber() == 20 );
        REQUIRE_FALSE( t1.empty() );
        REQUIRE( t2.getName() == "abc" );
        REQUIRE( t2.getNumber() == 10 );
        REQUIRE_FALSE( t2.empty() );
    }

    SUBCASE( "Copy-assigned ProductOrder object" )
    {
        ProductOrder t1("xyz", 100);
        ProductOrder t2;
        t2 = t1;

        REQUIRE( t1.getName() == "xyz" );
        REQUIRE( t1.getNumber() == 100 );
        REQUIRE_FALSE( t1.empty() );
        REQUIRE( t2.getName() == "xyz" );
        REQUIRE( t2.getNumber() == 100 );
        REQUIRE_FALSE( t2.empty() );

        t2.setName("abc");
        t2.setNumber(10);

        REQUIRE( t1.getName() == "xyz" );
        REQUIRE( t1.getNumber() == 100 );
        REQUIRE_FALSE( t1.empty() );
        REQUIRE( t2.getName() == "abc" );
        REQUIRE( t2.getNumber() == 10 );
        REQUIRE_FALSE( t2.empty() );

        t1.setName("def");
        t1.setNumber(20);

        REQUIRE( t1.getName() == "def" );
        REQUIRE( t1.getNumber() == 20 );
        REQUIRE_FALSE( t1.empty() );
        REQUIRE( t2.getName() == "abc" );
        REQUIRE( t2.getNumber() == 10 );
        REQUIRE_FALSE( t2.empty() );
    }
}


TEST_CASE( "String conversions" )
{
    ProductOrder t1;
    ProductOrder t2("xyz", 100);
    ProductOrder t3("", 0);

    SUBCASE( "ProductOrder::toString" )
    {
        REQUIRE( t1.toString() == "UNSPECIFIED (0)" );
        REQUIRE( t2.toString() == "xyz (100)" );
        REQUIRE( t3.toString() == " (0)" );
    }

    SUBCASE( "operator<<(ostream,ProductOrder)" )
    {
        ostringstream ostr1;
        ostr1 << t1;
        REQUIRE( ostr1.str() == "UNSPECIFIED (0)" );
        ostringstream ostr2;
        ostr2 << t2;
        REQUIRE( ostr2.str() == "xyz (100)" );
        ostringstream ostr3;
        ostr3 << t3;
        REQUIRE( ostr3.str() == " (0)" );
    }
}


TEST_CASE( "Increment & decrement" )
{
    ProductOrder t1;
    ProductOrder t2("xyz", 10);

    SUBCASE( "Increment ordinary object" )
    {
        ProductOrder t3 = (++t2);
        REQUIRE( t2.getName() == "xyz" );
        REQUIRE( t2.getNumber() == 11 );
        REQUIRE_FALSE( t2.empty() );
        REQUIRE( t3.getName() == "xyz" );
        REQUIRE( t3.getNumber() == 11 );
        REQUIRE_FALSE( t3.empty() );

        ProductOrder t4 = (t2++);
        REQUIRE( t2.getName() == "xyz" );
        REQUIRE( t2.getNumber() == 12);
        REQUIRE_FALSE( t2.empty() );
        REQUIRE( t4.getName() == "xyz" );
        REQUIRE( t4.getNumber() == 11 );
        REQUIRE_FALSE( t4.empty() );

        ++(++t2);
        REQUIRE( t2.getName() == "xyz" );
        REQUIRE( t2.getNumber() == 14 );
        REQUIRE_FALSE( t2.empty() );
    }

    SUBCASE( "Increment object with zero count" )
    {
        ++t1;
        REQUIRE( t1.getName() == "UNSPECIFIED" );
        REQUIRE( t1.getNumber() == 1 );
        REQUIRE_FALSE( t1.empty() );

        t1++;
        REQUIRE( t1.getName() == "UNSPECIFIED" );
        REQUIRE( t1.getNumber() == 2 );
        REQUIRE_FALSE( t1.empty() );
    }

    SUBCASE( "Decrement ordinary object" )
    {
        ProductOrder t3 = (--t2);
        REQUIRE( t2.getName() == "xyz" );
        REQUIRE( t2.getNumber() == 9 );
        REQUIRE_FALSE( t2.empty() );
        REQUIRE( t3.getName() == "xyz" );
        REQUIRE( t3.getNumber() == 9 );
        REQUIRE_FALSE( t3.empty() );

        ProductOrder t4 = (t2--);
        REQUIRE( t2.getName() == "xyz" );
        REQUIRE( t2.getNumber() == 8 );
        REQUIRE_FALSE( t2.empty() );
        REQUIRE( t4.getName() == "xyz" );
        REQUIRE( t4.getNumber() == 9 );
        REQUIRE_FALSE( t4.empty() );

        --(--t2);
        REQUIRE( t2.getName() == "xyz" );
        REQUIRE( t2.getNumber() == 6 );
        REQUIRE_FALSE( t2.empty() );
    }

    SUBCASE( "Decrement object with zero count" )
    {
        --t1;
        REQUIRE( t1.getName() == "UNSPECIFIED" );
        REQUIRE( t1.getNumber() == 0 );
        REQUIRE( t1.empty() );

        t1--;
        REQUIRE( t1.getName() == "UNSPECIFIED" );
        REQUIRE( t1.getNumber() == 0 );
        REQUIRE( t1.empty() );
    }
}


TEST_CASE( "Equality & inequality" )
{
    ProductOrder t1("abc", 10);  // Base value
    ProductOrder t2("abc", 10);  // Same
    ProductOrder t3("def", 10);  // Different name
    ProductOrder t4("abc", 20);  // Different count
    ProductOrder t5("def", 20);  // Different name & count

    SUBCASE( "Equality" )
    {
        REQUIRE( t1 == t1 );
        REQUIRE( t1 == t2 );
        REQUIRE( t2 == t1 );
        REQUIRE_FALSE( t1 == t3 );
        REQUIRE_FALSE( t3 == t1 );
        REQUIRE_FALSE( t1 == t4 );
        REQUIRE_FALSE( t4 == t1 );
        REQUIRE_FALSE( t1 == t5 );
        REQUIRE_FALSE( t5 == t1 );
    }

    SUBCASE( "Inequality" )
    {
        REQUIRE_FALSE( t1 != t1 );
        REQUIRE_FALSE( t1 != t2 );
        REQUIRE_FALSE( t2 != t1 );
        REQUIRE( t1 != t3 );
        REQUIRE( t3 != t1 );
        REQUIRE( t1 != t4 );
        REQUIRE( t4 != t1 );
        REQUIRE( t1 != t5 );
        REQUIRE( t5 != t1 );
    }
}


TEST_CASE( "Large values" )
{
    const size_t bigname_len = 1000001;
    string bigname(bigname_len, 'x');  // We make this into a long string

    int bigcount = 2147483641;         // Almost greatest 32-bit signed value

    ostringstream ostr;
    ostr << bigname << " (" << bigcount << ")";
    string bigstringform = ostr.str();
                        // String form of ProductOrder(bigname, bigcount)

    SUBCASE( "Construction from large values" )
    {
        ProductOrder t1(bigname, bigcount);

        REQUIRE( t1.getName() == bigname );
        REQUIRE( t1.getNumber() == bigcount );
        REQUIRE_FALSE( t1.empty() );

        // Check size & prefix first, to avoid enormous error messages
        REQUIRE( t1.toString().size() == bigstringform.size() );
        REQUIRE( t1.toString().substr(0,20) == bigstringform.substr(0,20) );
        REQUIRE( t1.toString() == bigstringform );
    }

    SUBCASE( "Set functions, passing large values" )
    {
        ProductOrder t1;
        t1.setName(bigname);
        t1.setNumber(bigcount);

        REQUIRE( t1.getName() == bigname );
        REQUIRE( t1.getNumber() == bigcount );
        REQUIRE_FALSE( t1.empty() );

        // Check size & prefix first, to avoid enormous error messages
        REQUIRE( t1.toString().size() == bigstringform.size() );
        REQUIRE( t1.toString().substr(0,20) == bigstringform.substr(0,20) );
        REQUIRE( t1.toString() == bigstringform );
    }
}


TEST_CASE( "Same-object tests" )
{
    SUBCASE("Copy assignment returns *this")
    {
        ProductOrder t1;
        ProductOrder t2;
        ProductOrder & r(t1 = t2);
        REQUIRE( &r == &t1 );
    }

    SUBCASE("Move assignment returns *this")
    {
        ProductOrder t1;
        ProductOrder t_movable;
        ProductOrder & r(t1 = move(t_movable));
        REQUIRE( &r == &t1 );
    }

    SUBCASE("pre-increment returns *this")
    {
        ProductOrder t1;
        ProductOrder & r(++t1);
        REQUIRE( &r == &t1 );
    }

    SUBCASE("pre-decrement returns *this")
    {
        ProductOrder t1;
        ProductOrder & r(--t1);
        REQUIRE( &r == &t1 );
    }

    SUBCASE("post-increment returns copy")
    {
        ProductOrder t1;
        ProductOrder && rr1(t1++);
        ProductOrder && rr2(t1++);
        REQUIRE( &rr1 != &t1 );
        REQUIRE( &rr1 != &rr2 );
    }

    SUBCASE("post-decrement returns copy")
    {
        ProductOrder t1;
        ProductOrder && rr1(t1--);
        ProductOrder && rr2(t1--);
        REQUIRE( &rr1 != &t1 );
        REQUIRE( &rr1 != &rr2 );
    }

    SUBCASE("getName returns copy")
    {
        ProductOrder t1;
        string && rr1(t1.getName());
        string && rr2(t1.getName());
        REQUIRE( &rr1 != &rr2 );
    }

    SUBCASE("getNumber returns copy")
    {
        ProductOrder t1;
        int && rr1(t1.getNumber());
        int && rr2(t1.getNumber());
        REQUIRE( &rr1 != &rr2 );
    }

    SUBCASE("empty returns copy")
    {
        ProductOrder t1;
        bool && rr1(t1.empty());
        bool && rr2(t1.empty());
        REQUIRE( &rr1 != &rr2 );
    }

    SUBCASE("operator<< returns original stream")
    {
        ostringstream ostr;
        ProductOrder t1;
        ostream & r(ostr << t1);
        REQUIRE( &r == &ostr );
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
    const std::string tname = "class ProductOrder"
                              " - CS 311 Proj 1, Ex A";
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

