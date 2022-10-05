//
//  main.cpp
//  Heap
//
//  Created by Mary Tamry on 09.09.22.
//

#include <iostream>
#include "myHeap.hpp"
#include "myHeap.cpp"
#include "assert.h"


int main() {
    myHeap<float> A;
    
    A.push(20.5);
    cout << A.toString() << endl;
    A.push(20.3);
    A.push(22.4);
    A.push(23.2);
    A.push(19.2);
    A.push(9.2);
    A.push(10.4);
    cout << A.toString() << endl;
    A.pop();
    cout << A.toString() << endl;
}
