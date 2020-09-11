// allocate2_raii.cpp
// Glenn G. Chappell
// 2020-09-11
//
// For CS 311 Fall 2020
// Out-of-memory handling using exceptions, with RAII classes

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <string>
using std::string;
#include <new>
using std::bad_alloc;
#include <memory>
using std::unique_ptr;
using std::make_unique;


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
        //if (_name == "Object C") throw std::bad_alloc();

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
// Attempt to allocate a Named object, with name "Object A". Returns
// unique_ptr to the object in nptra. Throws std::bad_alloc if
// allocation is unsuccessful.
// Pre: None.
// Post:
//     nptra points to object with name "Object A".
// May throw std::bad_alloc.
void allocate1(unique_ptr<Named> & nptra)
{
    nptra = make_unique<Named>("Object A");
    // If the allocation fails, the "new" throws, and we
    // leave. No clean-up necessary.
}


// allocate2
// Attempt to allocate two Named objects, with named "Object B" and
// "Object C". Return unique_ptrs to these in nptrb, nptrc. Throws
// std::bad_alloc if either allocation is unsuccessful.
// Pre: None.
// Post:
//     nptrb points to object with name "Object B".
//     nptrc points to object with name "Object C".
// May throw std::bad_alloc.
void allocate2(unique_ptr<Named> & nptrb,
               unique_ptr<Named> & nptrc)
{
    nptrb = make_unique<Named>("Object B");
    nptrc = make_unique<Named>("Object C");
}


// Main program
// Demonstrates calling allocate1, allocate2, with proper catching.
int main()
{
    // Call allocate1
    unique_ptr<Named> npa;
    try
    {
        allocate1(npa);
        cout << "Call to \"allocate1\" successful" << endl;
    }
    catch (std::bad_alloc & e)
    {
        cout << "Call to \"allocate1\" NOT successful" << endl;
    }

    // Call allocate2
    unique_ptr<Named> npb;
    unique_ptr<Named> npc;
    try
    {
        allocate2(npb, npc);
        cout << "Call to \"allocate2\" successful" << endl;
    }
    catch (std::bad_alloc & e)
    {
        cout << "Call to \"allocate2\" NOT successful" << endl;
    }
    cout << endl;

    // Deallocation is automatic; nothing more to do
    // (Isn't RAII great?)

    // Wait for user
    cout << "Press ENTER to quit ";
    userPause();
}

