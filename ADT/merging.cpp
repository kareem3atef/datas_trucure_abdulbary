#include <iostream>
#include <stdlib.h>

using namespace std;

// creating swap function for 2 integers
void swap(int &x, int &y)
{
  int temp;
  temp = x;
  x = y;
  y = temp;
}

// Creating ARRAY as data structure
struct Array
{
  int *A;
  int size;
  int length;
};

void merging(Array *arr1, Array *arr2, Array *arr3)
{
  int i, j, k;
  i = j = k = 0;
  while (i < arr1->length && j < arr2->length)
  {
    if (arr1->A[i] < arr2->A[j])
    {
      arr3->A[k++] = arr1->A[i++];
    }
    else
    {
      arr3->A[k++] = arr2->A[j++];
    }
  }
  while (i < arr1->length)
  {
    arr3->A[k++] = arr1->A[i++];
  }
  while (j < arr2->length)
  {
    arr3->A[k++] = arr2->A[j++];
  }
}

void display(Array arr)
{
  for (int i = 0; i < arr.length; i++)
  {
    cout << arr.A[i] << " ";
  }
}

int main(int argc, char const *argv[])
{
  // initializing an ARRAY
  Array arr;
  arr.size = 100;
  arr.length = 5;

  arr.A = (int *)malloc(arr.size * sizeof(int));

  // assigning values to the array
  arr.A[0] = 0;
  arr.A[1] = 5;
  arr.A[2] = 7;
  arr.A[3] = 10;
  arr.A[4] = 55;

  // initilaizing an -ve +ve array
  Array arrve;
  arrve.size = 15;
  arrve.length = 10;
  arrve.A = (int *)malloc(arrve.length * sizeof(int));
  // assign values
  arrve.A[0] = 0;
  arrve.A[1] = 2;
  arrve.A[2] = 6;
  arrve.A[3] = 8;
  arrve.A[4] = 10;
  arrve.A[5] = 13;
  arrve.A[6] = 15;
  arrve.A[7] = 17;
  arrve.A[8] = 20;
  arrve.A[9] = 33;

  Array arr3;
  arr3.length = 50;
  arr3.size = 100;
  arr3.A = (int *)malloc(arr3.length * sizeof(int));
  merging(&arr, &arrve, &arr3);
  display(arr);
  cout << endl;
  display(arrve);
  cout << endl;
  display(arr3);

  free(arrve.A);
  free(arr.A);
  free(arr3.A);

  return 0;
}
