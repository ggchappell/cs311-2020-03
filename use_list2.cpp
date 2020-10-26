// use_list2.cpp  UNFINISHED
// Glenn G. Chappell
// 2019-10-26
//
// For CS 311 Fall 2020
// Singly Linked List example using smart pointers: create & find size
// Based on use_list.cpp

#include "llnode2.h"  // For struct LLNode2
#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <cstddef>
using std::size_t;


// userPause
// Wait for user to press ENTER: read all chars through first newline.
void userPause()
{
    std::cout.flush();
    while (std::cin.get() != '\n') ;
}


// Main program
// Creates a Linked List and finds its size.
int main()
{
    const size_t THESIZE = 507;  // Size of list to create

    // Create empty list
    cout << "Creating empty Linked List" << "\n";
    LLNode2<int> * head = nullptr;

    // Add nodes to list
    cout << "Adding " << THESIZE << " nodes to Linked List" << "\n";
    for (size_t i = 0; i < THESIZE ; ++i)
    {
        head = new LLNode2<int>(int(THESIZE-i), head);
    }
    cout << endl;

    // Find & print size of Linked List
    auto s = size(head);
    cout << "Computed size of Linked List: " << s << " - ";
    cout << (s == THESIZE
               ? "right!"
               : "WRONG **********************************************")
         << "\n";
    cout << endl;

    // Deallocate list
    cout << "Deallocating list" << "\n";
    delete head;
    cout << endl;

    // Wait for user
    cout << "Press ENTER to quit ";
    userPause();
}
