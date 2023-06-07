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

void swap(int &x, int &y)
{
  int temp;
  temp = x;
  x = y;
  y = temp;
}

void insert_in_right_position(Array *arr, int value)
{
  // pre condition to insert new value
  if (arr->length < arr->size)
  {
    // shifting to the right
    int i = arr->length - 1;
    while (value < arr->A[i])
    {
      arr->A[i + 1] = arr->A[i];
      i--;
    }
    // assinging the value in it's positino
    arr->A[i + 1] = value;
    arr->length++;
  }
}

int isSorted(Array *arr)
{ // (iterator form 0 to length -2) -> (< length -1) ......
  for (int i = 0; i < arr->length - 1; i++)
  {
    if (arr->A[i] > arr->A[i + 1])
    {
      return 0; // the array isn't sorted
    }
  }
  return 1; // the array is sorted
}

void rearrange(Array *arr)
{
  int i = 0;
  int j = arr->length - 1;
  while /*if*/ (i < j)
  {
    while (arr->A[i] < 0)
    {
      i++;
    }
    while /*if*/ (arr->A[j] >= 0)
    {
      j--;
    }
    // if (arr->A[i] > 0 && arr->A[j] < 0) /// THAT condition is vere importanttttttttt
    //{
    if (i < j)
      swap(arr->A[i], arr->A[j]);
    //}
  }
}

// to display elements in ARRAY
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
  arrve.A[0] = 1;
  arrve.A[1] = -5;
  arrve.A[2] = 8;
  arrve.A[3] = -4;
  arrve.A[4] = 12;
  arrve.A[5] = 13;
  arrve.A[6] = -9;
  arrve.A[7] = 10;
  arrve.A[8] = -50;
  arrve.A[9] = 100;

  // display(arr);
  // insert_in_right_position(&arr, 6);
  // display(arr);
  // cout << isSorted(&arr);

  display(arrve);
  rearrange(&arrve);
  display(arrve);
  free(arrve.A);
  free(arr.A);

  return 0;
}
