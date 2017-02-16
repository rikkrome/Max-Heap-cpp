#include "maxheap.hpp"
#include <stdio.h>
#include <iostream>

int main(int argc, char*argv[]) {

  //demo functions of the maxheap class
  MaxHeap* myheap = new MaxHeap();
  cout << "========================================" << endl;
  cout << "Trying some methods from the MaxHeap class ...." << endl;
  cout << "You must check that the output is correct manually (or write code that does it automatically)" << endl ;
  cout << "========================================" << endl;
   //just max heap
  myheap->insert(13);
  cout << "insert 13" << endl;
  myheap->display();
    cout << endl;
    
  myheap->insert(21);
  cout << "insert 21" << endl;
  myheap->display();
    cout << endl;

  myheap->insert(16);
  cout << "insert 16" << endl;
  myheap->display();
    cout << endl;

  myheap->insert(24);
  cout << "insert 24" << endl;
  myheap->display();
    cout << endl;

  myheap->insert(31);
  cout << "insert 31" << endl;
  myheap->display();
    cout << endl;

  myheap->insert(19);
  cout << "insert 19" << endl;
  myheap->display();
    cout << endl;

  myheap->insert(68);
  cout << "insert 68" << endl;
  myheap->display();
    cout << endl;

    
  int heapSize = myheap->size();
    cout << "======================================== \n" << endl;

  for ( int i = 0; i < heapSize/2; i++ ) {
    cout << "Get and delete max element: " << myheap->deleteMax() << endl;
    myheap->display();
      cout << endl;
  }
  cout << "========================================" << endl;

  delete myheap;
  
 
    
//    cout << "argc: " <<argc << " : " << argv[1] << endl;
    
  //heapsorting numbers in a file
  vector<int> A;
  if(argc!=2) {
    cout<<"Provide an input file as argument";
  } else {
    //testing on my computer
    FILE *file = fopen("/Users/rickyromero/school/maxHeap/maxHeap/input.10.1", "r");
//    FILE *file = fopen(argv[1], "r");
    if(file == 0){
      cout << "ERROR: file does not exist" << endl;
      return -1;
    }
    else {
      int x;
      fscanf(file, "%d", &x);
      while(!feof(file)) {
          A.push_back(x);
          fscanf(file, "%d", &x);
      }
      fclose(file);
    }
  }
  
  int n = A.size();

  cout << endl << endl;
  cout << "========================================" << endl;
  cout << "Checking if HeapSort works ..." << endl;
  cout << "Input size: " << n << endl;
  cout << "========================================" << endl << endl;
// out put arr
  if (n <= 10) {
    cout << "This it the input:" << endl;
    for(int i=0; i<n; ++i) {
      cout << A[i] << " ";
    }
    cout << endl << endl;
  }
  else{
    cout << "Input is too large to display" << endl;
  }
// making a new heap
  MaxHeap *myheap2 = new MaxHeap();
//sort
  myheap2->heapsort(A,n);
    cout << "Input size: " << n << endl;

  if (n <= 10) {
    cout << "And this is the sorted output:" << endl;
    for(int i=0; i<n; ++i) {
      cout << A[i] << " ";
    }
    cout << endl;
  }
  else {
    cout << "Sorted output is too large to display" << endl;
  }
cout << endl;


  cout << "Checking if the output is actually sorted ..." << endl << endl;
  bool sorted = true;
  for (int i=1; i<n; ++i) {
    if (A[i-1] > A[i]){
          cout << "Output is NOT SORTED: " << A[i-1] << " is greater than " <<
          A[i] << "(index " << i << ")" << endl;
          sorted = false;
     }
  }
  if (sorted) {
    cout << "\tThe output is sorted" << endl;  
  }
  cout << "========================================" << endl << endl << endl << endl;

  
  delete myheap2;
  return 0;
}
