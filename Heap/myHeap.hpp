//
//  myHeap.hpp
//  Heap
//
//  Created by Mary Tamry on 07.09.22.
//

#ifndef myHeap_hpp
#define myHeap_hpp
#include <stdio.h>
#include <string>
using namespace std;

template <class type> class myHeap {
private:
    type* data;  // An array of integers, allocated through the constructor
    int currentSlot; // Keeps track of the parent with a free child so it does not fill up one side of the tree rather than the other;
    bool headElement;
    int nextFreeSlot(); // keeps track of the next free slot to insert a new element, Returns -1 if array is full
    int LeftSon(int i); // Returns the index of the left son of node i (2*i) ; -1 if out of range
    int RightSon(int i); // Returns the index of the right son of node i (2*i + 1) ; -1 if out of range
    int Parent(int i); // Returns the index of the parent of node i (i/2)  ; -1 if out of range
    int Swap(int i, int j); // Swaps two nodes in the heap - checks if one is the parent of the other ; returns 0 if success, -1 if failure
    int treeSize; //Size of the Array (must add 1 to it to make up for the missed head of the array
    bool checkParent(type x); // Checks if the value is greater than the parent value ; Returns 1 if true, else returns 0
    bool checkSon(int i); // Checks if the value of the index i is lower than the parent value ; Returns 1 if true, else returns 0
    int biggerSon; // Keeps track of the bigger son of a parent; useful for the pop function
    void ReversedSwap(int Head); //
    bool isMaximumHeap;

public:
    myHeap();
    ~myHeap(); // Needs a destructor to free dynamic mem
    void heapInterface();
    int push(type x);    // adds a new element ; returns 0 if success, -1 if failure
    type pop();          // Gets the value of the root element and removes it from the heap
    string toString();  // textual representation of the contents of the heap - for display & debug purposes mainly
    bool VerifyHeap();
};
#endif /* myHeap_hpp */
