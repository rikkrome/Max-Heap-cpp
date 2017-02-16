#include "maxheap.hpp"
#include <stdio.h>
#include <iostream>

MaxHeap::MaxHeap() {}
MaxHeap::~MaxHeap() {}

/*
ALL YOUR CODE GOES HERE
The methods below either
  - don't do anything at all, or
  - return 0 just so that the code compiles

You have to implement every method in this class
 */

int MaxHeap::size() {
  return currentSize;
}

int MaxHeap::left(int parent) {
    return ((2 * parent) + 1);
}

int MaxHeap::right(int parent) {
    return ((2 * parent) + 2);
}

int MaxHeap::parent(int child) {
  return (child/2);
}

void MaxHeap::insert(int element) {

    arr.push_back(element);
    currentSize = arr.size();
    percolateUp(arr.size() - 1);
    

}

int MaxHeap::deleteMax() {
    int max =  arr.front();
    arr.erase(arr.begin());
    currentSize--;
  return max;
}

void MaxHeap::display() {
  vector<int>::iterator it;
  cout << "MaxHeap:- ";
  for(it=arr.begin(); it!=arr.end(); ++it) {
    cout << *it << " ";
  }
  cout << endl;
}

void MaxHeap::percolateUp(int i) {
    
    
    
    int n = arr.size();

    int temp = i;
    int p = parent(i - 1);
//    cout << "i: " <<  i << " " << arr[temp] << " p: " << p << " " <<  arr[p] << endl;

    if( i != p){
        if( p < n && arr[temp] > arr[p]){
            temp = p;
        }
        // If switch parent and child is not root
        if (temp != i){
            swap(arr[i], arr[temp]);
            //check if
            percolateUp(temp);
        }
    }


}



void MaxHeap::percolateDown(int index) {
    
    int child;
    int temp = arr[index];
    int n = size();
    for( ; left(index) < n; index = child){
        child = left(index);
        if(child != n - 1 && arr[child] < arr[child + 1])
            ++child;
        if(temp < arr[child])
            arr[index] = arr[child];
        else
            break;
        
    }
    arr[index] = temp;
    

}

void MaxHeap::buildHeap(vector<int> A,int n) {
    
    for(int i = arr.size() / 2 - 1; i >= 0; --i){
        percolateDown(i);
    }
    
}

void MaxHeap::heapsort(vector<int>& A,int n) {
    
    arr.swap(A);
    
    currentSize = arr.size();
    buildHeap(arr,currentSize);
    
    
    for(int j = arr.size() - 1; j > 0; --j){
        swap(arr[0],arr[j]);
//        percolateDown(arr,0, j);
        currentSize--;
        percolateDown(0);

    }
    
    A.swap(arr);


}


