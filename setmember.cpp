// setmember.cpp
// Glenn G. Chappell
// 2020-09-02
//
// For CS 311 Fall 2020
// See how class members are initialized

#include <iostream>
using std::cout;
using std::endl;


// class SetMember
// Initializes members in various ways.
// Invariants: None.
class SetMember {

// ***** SetMember: Ctors, dctor, op= *****
public:

    // Default ctor - defauted
    SetMember() = default;

    // Ctor from int - sets _x member
    SetMember(int x)
        :_x(x)
    {}

    // Ctor form 2 ints - does not set _x member
    SetMember(int a,
              int b)
    {
        (void)a;  // Avoid unused-parameter warnings
        (void)b;  //  (alternate method)
    }

    // Big-Five Auto-Generated
    ~SetMember() = default;
    SetMember(const SetMember &) = default;
    SetMember(SetMember &&) = default;
    SetMember & operator=(const SetMember &) = default;
    SetMember & operator=(SetMember &&) = default;

// ***** SetMember: General public member functions *****
public:

    // getx
    // Returns _x member.
    int getx() const
    {
        return _x;
    }

// ***** SetMember: Data members *****
private:

    int _x = 42;

};  // End class SetMember


// Main program
// Try setting class members in various ways. Print their values.
int main()
{
    cout << "Member _x is set in its declaration." << endl;
    cout << endl;

    // Default ctor (defaulted)
    SetMember sm1;
    cout << "Default ctor (defaulted); _x = " << sm1.getx() << endl;
    cout << endl;

    // Ctor from int (sets member)
    const int val = 99999;
    SetMember sm2(val);
    cout << "Member set in ctor to " << val << "; _x = " << sm2.getx()
         << endl;
    cout << endl;

    // Ctor from 2 ints (does not set member)
    SetMember sm3(1, 2);
    cout << "Member not set in ctor; _x = " << sm3.getx() << endl;
    cout << endl;
}

