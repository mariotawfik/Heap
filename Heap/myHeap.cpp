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
    data = new int[treeSize+1];
    currentSlot = 1;
    headElement = true;
    for(int i = 0; i < treeSize+1; i++){
        data[i] = -1;
    }
}

myHeap::~myHeap()
{
    delete[] data;
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
    if(((int)(i/2)) <= 0){
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
    currentSlot = nextFreeSlot();
    if(currentSlot != -1 && currentSlot < treeSize+1){
        data[currentSlot] = x;
        while(checkParent(data[currentSlot]))
        {
            Swap(currentSlot, Parent(currentSlot));
            currentSlot = Parent(currentSlot);
        }
        if(currentSlot == treeSize){
            currentSlot++;
        }
        return 0;
    }else{
        cout << "The Tree is full please make a new one" << endl;
        return -1;
    }
}


bool myHeap::checkParent(int x)
{
    if(Parent(currentSlot) != -1)
    {
        if(x > data[Parent(currentSlot)])
        {
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

int myHeap::nextFreeSlot()
{
    if(currentSlot == 1 && headElement){
        headElement = false;
        return 1;
    }else{
        if(currentSlot >= treeSize+1){
            return -1;
        }else{
            int i = 1;
            while(data[i] != -1){
                i++;
            }
            return i;
        }
    }
}

int myHeap::pop()
{
    if(data[1] != -1){
        int removedRoot = data[1];
        currentSlot = treeSize;
        data[1] = data[currentSlot];
        data[currentSlot] = -1;
        currentSlot--;
        ReversedSwap(1);
        return removedRoot;
    }else{
        return -1;
    }
}

bool myHeap::checkSon(int i)
{
    bool oneSon = false;
        if((data[LeftSon(i)] != -1 || data[RightSon(i)] != -1) && (LeftSon(i) != -1 && RightSon(i) != -1))
        {
            if(data[LeftSon(i)] != -1 && data[RightSon(i)] == -1)
            {
                oneSon = true;
                biggerSon = LeftSon(i);
                if((data[LeftSon(i)] > data[i])){
                    return 1;
                }else{
                    return 0;
                }
            }else{
                if(data[LeftSon(i)] == -1 && data[RightSon(i)] != -1)
                {
                    oneSon = true;
                    biggerSon = RightSon(i);
                    if((data[RightSon(i)] > data[i])){
                        return 1;
                    }else{
                        return 0;
                    }
                }else{
                    oneSon = false;
                }
            }
            if(oneSon == false){
                if((data[LeftSon(i)] > data[RightSon(i)]))
                {
                    biggerSon = LeftSon(i);
                }else{
                    biggerSon = RightSon(i);
                }
            }
            if((data[LeftSon(i)] > data[i]) || (data[RightSon(i)] > data[i]))
            {
                return 1;
            }else{
                return 0;
            }
        }else{
            return 0;
        }
}

    void myHeap::ReversedSwap(int Head)
    {
        while(checkSon(Head))
        {
            Swap(biggerSon, Head);
            Head = biggerSon;
        }
    }
    bool myHeap::VerifyHeap()
    {
        int currentIndex = 1;
        while(LeftSon(currentIndex) != -1)
        {
            if (data[currentIndex] < data[LeftSon(currentIndex)])
                return false;
            currentIndex = LeftSon(currentIndex);
        }
        currentIndex = 1;
        while(RightSon(currentIndex) != -1)
        {
            if (data[currentIndex] < data[RightSon(currentIndex)])
                return false;
            currentIndex = RightSon(currentIndex);
        }
        // same for right
        return true;
    }
