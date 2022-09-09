//
//  myHeap.cpp
//  Heap
//
//  Created by Mary Tamry on 07.09.22.
//

#include "myHeap.hpp"
#include <sstream>
#include <iostream>
using namespace std;

myHeap::myHeap()
{
    cout << "Please enter the size of the tree " << endl;
    cin >> treeSize;
    data = new int(treeSize+1);
    nextFreeSlot = 1;
}

myHeap::~myHeap()
{
    delete data;
}

int myHeap::LeftSon(int i)
{
    if((2*i) < treeSize){
        return (2*i);
    }else{
        return -1;
    }
}

int myHeap::RightSon(int i)
{
    if(((2*i)+1) < treeSize){
        return ((2*i)+1);
    }else{
        return -1;
    }
}

int myHeap::Parent(int i)
{
    if((i/2) <= 0){
        return -1;
    }else{
        return (i/2);
    }
}

int myHeap::Swap(int i, int j)
{
    int tempVar = data[i];
    if(data[i] > data[j])
    {
        data[i] = data[j];
        data[j] = tempVar;
        return 0;
    }else{
        return -1;
    }
}

int myHeap::push(int x)
{
    if(nextFreeSlot != -1){
        data[nextFreeSlot] = x;
        int currentSlotOfElement;
        if(checkParent(x))
        {
            Swap(nextFreeSlot, Parent(nextFreeSlot));
            currentSlotOfElement = Parent(nextFreeSlot);
            while(checkParent(data[currentSlotOfElement]))
            {
                Swap(currentSlotOfElement, Parent(currentSlotOfElement));
                currentSlotOfElement = Parent(currentSlotOfElement);
            }
        }
        if(nextFreeSlot != treeSize+1){
            while(data[nextFreeSlot] != NULL)
            {
                nextFreeSlot += 1;
            }
        }else{
            nextFreeSlot = -1;
        }
        return 0;
    }else{
        cout << "The Tree is full please make a new one" << endl;
        return -1;
    }
}


bool myHeap::checkParent(int x)
{
    if(x > data[Parent(nextFreeSlot)])
    {
        if(Parent(nextFreeSlot) != -1){
            return 1;
        }else{
            return 0;
        }
    }else{
        return 0;
    }
}

string myHeap::toString()
{
    ostringstream os;
    for(int i = 1; i < treeSize+1; i++)
    {
        os << data[i] << "  ";
    };
    
    string heapOutput(os.str());
    
    return heapOutput;
}
