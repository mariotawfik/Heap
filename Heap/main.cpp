//
//  main.cpp
//  Heap
//
//  Created by Mary Tamry on 09.09.22.
//

#include <iostream>
#include "myHeap.hpp"


int main() {
    myHeap A;
    A.push(10);
    A.push(5);
    A.push(6);
    A.push(11);
    cout << A.toString();
}
