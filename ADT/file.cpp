#include <iostream>
#include <stdlib.h>

using namespace std;

// Creating ARRAY as data structure
struct Array
{
  int *A;
  int size;
  int length;
};


// to display elements in ARRAY
void display(Array arr){
  for (int i = 0; i < arr.length; i++)
  {
    cout<<arr.A[i]<<" ";
  }
  
}


int main(int argc, char const *argv[])
{
  // initializing an ARRAY
  Array arr;
  cout<<"enter size\n";
  cin>>arr.size;
  cout<<"enter number of numbers you want\n";
  cin>>arr.length;

  arr.A = (int *)malloc(arr.size * sizeof(int));

  // entering data on array
  for (int i = 0; i < arr.length; i++)
  {
    arr.A[i] = i;
  }


  display(arr);


  
  return 0;
}
