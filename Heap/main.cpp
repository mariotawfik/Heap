//
//  main.cpp
//  Heap
//
//  Created by Mary Tamry on 09.09.22.
//

#include <iostream>
#include "myHeap.hpp"
#include "assert.h"


int main() {
// I know that my heap has a capacity of 100 items
    myHeap *h = new myHeap();
// Init of the random number generator
    int seed = time(NULL);
    srand(seed);
// --------------------------------------------------------
// Test #1 : heap interface works properly
// --------------------------------------------------------
    int numberOfItems = 50;
    int t;
    for (int i = 0 ; i < numberOfItems ; i++)
    {
        h->push(rand() % 1000);
    }
    int whereAmI = -1;
    int lastPopped;
    cout << h->toString() << endl << endl;
    for (int i = 0 ; i < numberOfItems ; i++)
    {
        lastPopped = h->pop();
        cout << lastPopped << endl;
        cout << h->toString() << endl << endl;
        whereAmI = lastPopped;
    }
    cout << "Test #1 successful" << endl;
// --------------------------------------------------------
// Test #2 : Limit cases
// --------------------------------------------------------
// This should fail but not break
// Pop an empty heap
    h->pop();
// This should fail but not break
    for (int i = 0 ; i < 10001 ; i++)
    {
        h->push(rand() % 1000 );
    }
// ...
}
