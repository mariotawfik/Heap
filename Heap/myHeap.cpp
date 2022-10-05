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

template <class type>
myHeap<type>::myHeap()
{
    heapInterface();
    data = new type[treeSize+1];
    currentSlot = 1;
    headElement = true;
    for(int i = 0; i < treeSize+1; i++){
        data[i] = NULL;
    }
}

template <class type>
myHeap<type>::~myHeap()
{
    delete[] data;
}

template <class type>
int myHeap<type>::LeftSon(int i)
{
    if((2*i) < treeSize){
        return (2*i);
    }else{
        return -1;
    }
}

template <class type>
int myHeap<type>::RightSon(int i)
{
    if(((2*i)+1) < treeSize){
        return ((2*i)+1);
    }else{
        return -1;
    }
}

template <class type>
int myHeap<type>::Parent(int i)
{
    if(((int)(i/2)) <= 0){
        return -1;
    }else{
        return (i/2);
    }
}

template <class type>
int myHeap<type>::Swap(int i, int j)
{
    type tempVar = data[i];
    if(data[i] > data[j])
    {
        data[i] = data[j];
        data[j] = tempVar;
        return 0;
    }else{
        return -1;
    }
}

template <class type>
int myHeap<type>::push(type x)
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

template <class type>
bool myHeap<type>::checkParent(type x)
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

template <class type>
string myHeap<type>::toString()
{
    ostringstream os;
    for(int i = 1; i < treeSize+1; i++)
    {
        os << data[i] << "  ";
    };
    
    string heapOutput(os.str());
    
    return heapOutput;
}

template <class type>
int myHeap<type>::nextFreeSlot()
{
    if(currentSlot == 1 && headElement){
        headElement = false;
        return 1;
    }else{
        if(currentSlot >= treeSize+1){
            return -1;
        }else{
            int i = 1;
            while(data[i] != NULL){
                i++;
            }
            return i;
        }
    }
}

template <class type>
type myHeap<type>::pop()
{
    if(data[1] != NULL){
        type removedRoot = data[1];
        currentSlot = treeSize;
        data[1] = data[currentSlot];
        data[currentSlot] = NULL;
        currentSlot--;
        ReversedSwap(1);
        return removedRoot;
    }else{
        return -1;
    }
}

template <class type>
bool myHeap<type>::checkSon(int i)
{
    bool oneSon = false;
        if((data[LeftSon(i)] != NULL || data[RightSon(i)] != NULL) && (LeftSon(i) != -1 && RightSon(i) != -1))
        {
            if(data[LeftSon(i)] != NULL && data[RightSon(i)] == NULL)
            {
                oneSon = true;
                biggerSon = LeftSon(i);
                if((data[LeftSon(i)] > data[i])){
                    return 1;
                }else{
                    return 0;
                }
            }else{
                if(data[LeftSon(i)] == NULL && data[RightSon(i)] != NULL)
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

template <class type>
    void myHeap<type>::ReversedSwap(int Head)
    {
        while(checkSon(Head))
        {
            Swap(biggerSon, Head);
            Head = biggerSon;
        }
    }

template <class type>
    bool myHeap<type>::VerifyHeap()
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

        return true;
    }

template <class type>
    void myHeap<type>::heapInterface()
    {
        cout << "Please enter the size of the heap" << endl;
        cin >> treeSize;
        
        cout << "Do you want a minimum or maximum heap? Choose 1 for minimum heap or 2 for maximum heap" << endl;
        int option;
        cin >> option;
        switch (option) {
            case 1:
                isMaximumHeap = false;
                break;
            case 2:
                isMaximumHeap = true;
                break;
            default:
                while(option != 1 && option != 2)
                {
                    cout << "Please a valid option (1/2)" << endl;
                    cin >> option;
                }
                break;
        }
        
    }

