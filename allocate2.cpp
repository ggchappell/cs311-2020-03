// allocate2.cpp  UNFINISHED
// Glenn G. Chappell
// 2020-09-11
//
// For CS 311 Fall 2020
// Out-of-memory handling using exceptions

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <string>
using std::string;
#include <new>
using std::bad_alloc;


// userPause
// Wait for user to press ENTER: read all chars through first newline.
void userPause()
{
    std::cout.flush();
    while (std::cin.get() != '\n') ;
}


// class Named
// Given name on construction. Prints name, along with "created" on
// construction. Prints name, along with "DESTROYED" on destruction.
class Named {

// ***** Named: ctors, dctor, op= *****
public:

    // Ctor from string
    // Store given string as my name. Print my name, then
    // " allocated\n", to cout.
    Named(const string & name)
        :_name(name)
    {
        // UNCOMMENT ONE OR MORE LINES BELOW TO SEE WHAT HAPPENS IF
        // ALLOCATION FAILS.

        //if (_name == "Object A") throw std::bad_alloc();
        //if (_name == "Object B") throw std::bad_alloc();
        if (_name == "Object C") throw std::bad_alloc();

        // NOTE: In practice, we ***never*** do throws like those above;
        // "new" does them. These are fake throws, to see what would
        // happen if "new" did actually throw.

        cout << _name << " created" << endl;
    }

    // Dctor
    // Print my name, then " deallocated\n", to cout.
    ~Named()
    {
        cout << _name << " DESTROYED" << endl;
    }

    // No other Big Five functions
    Named(const Named & other) = delete;
    Named(Named && other) = delete;
    Named & operator=(const Named & rhs) = delete;
    Named & operator=(Named && rhs) = delete;

// ***** Named: data members *****
private:

    string _name;  // Object's name; print on destruction

};


// allocate1
// Attempt to allocate a Named object, with name "Object A". Returns a
// pointer to the object in nptra. Old value of nptra is discarded.
// Throws std::bad_alloc if allocation is unsuccessful.
// Pre: None.
// Post:
//     nptra points to object with name "Object A", allocated with new,
//      ownership transfered to caller.
// May throw std::bad_alloc.
void allocate1(Named * & nptra)
{
    // TODO: WRITE THIS!!!
}


// allocate2
// Attempt to allocate two Named objects, with named "Object B" and
// "Object C". Return pointers to these in nptrb, nptrc. Old values of
// nptrb, nptrc are discarded. Throws std::bad_alloc if either
// allocation is unsuccessful.
// Pre: None.
// Post:
//     nptrb points to object with name "Object B", allocated with new,
//      ownership transfered to caller.
//     nptrc points to object with name "Object C", allocated with new,
//      ownership transfered to caller.
// May throw std::bad_alloc.
void allocate2(Named * & nptrb,
               Named * & nptrc)
{
    // TODO: WRITE THIS!!!
}


// Main program
// Demonstrates calling allocate1, allocate2, with proper catching.
int main()
{
    // Call allocate1
    bool allocate1Successful;  // true if allocation is successful
    Named * npa;
    try
    {
        allocate1(npa);
        allocate1Successful = true;
        cout << "Call to \"allocate1\" successful" << endl;
    }
    catch (std::bad_alloc & e)
    {
        allocate1Successful = false;
        cout << "Call to \"allocate1\" NOT successful" << endl;
    }

    // Call allocate2
    bool allocate2Successful;  // true if allocations are successful
    Named * npb;
    Named * npc;
    try
    {
        allocate2(npb, npc);
        allocate2Successful = true;
        cout << "Call to \"allocate2\" successful" << endl;
    }
    catch (std::bad_alloc & e)
    {
        allocate2Successful = false;
        cout << "Call to \"allocate2\" NOT successful" << endl;
    }
    cout << endl;

    // Now we deallocate the arrays that were successfully allocated
    if (allocate1Successful)
    {
        cout << "Deallocating object from \"allocate1\":"
             << " Object A" << endl;
        delete npa;
    }
    if (allocate2Successful)
    {
        cout << "Deallocating objects from \"allocate2\":"
             << " Object B, Object C" << endl;
        delete npb;
        delete npc;
    }
    cout << endl;

    // Wait for user
    cout << "Press ENTER to quit ";
    userPause();
}

