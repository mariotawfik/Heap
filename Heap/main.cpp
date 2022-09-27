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
    A.push(20);
    A.push(15);
    A.push(30);
    A.push(100);
    A.push(10);
    A.push(5);
    A.push(20);
    A.push(15);
    A.push(30);
    A.pop();
    cout << A.toString();
}
