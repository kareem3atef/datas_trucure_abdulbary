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

// to display elements in ARRAY
void display(Array arr)
{
  for (int i = 0; i < arr.length; i++)
  {
    cout << arr.A[i] << " ";
  }
}

// ADDING or APPENDING in ARRAY
void add(Array &arr, int x)
{
  if (arr.length < arr.size)
  {
    arr.A[arr.length] = x;
    arr.length++;
  }
}

// INSERTING ellement in specific INDEX
void insert(Array &arr, int index, int X)
{
  if (index >= 0 && index <= arr.length)
  {
    if (arr.length < arr.size)
    {
      for (int i = arr.length; i > index; i--)
      {
        arr.A[i] = arr.A[i - 1];
      }
      arr.A[index] = X;
      arr.length++;
    }
  }
}

// DELETING an element by it's index
void Delete(Array &arr, int index)
{
  if (index >= 0 && index <= arr.length)
  {
    for (int i = index; i < arr.length - 1; i++)
    {
      arr.A[i] = arr.A[i + 1];
    }
  }
  arr.length--; // its' vere important to reduce the length
}

// LINEAR SEARCH for an key
int linearSearch(Array arr, int key)
{
  for (int i = 0; i < arr.length; i++)
  {
    if (key == arr.A[i])
    {
      return i;
    }
  }
  return -1;
}

// ##################################
// ####### BINARY SEARCH ############
// ##################################

// iterative implementation
int binarySearchI(Array arr, int key)
{
  int l, m, h;
  l = 0;
  h = arr.length - 1;
  while (l <= h)
  {
    m = (l + h) / 2;
    if (arr.A[m] == key)
    {
      return m;
    }
    else if (key > arr.A[m])
    {
      l = m + 1;
    }
    else
    {
      h = m - 1;
    }
  }
  return -1;
}

// Recursive Implementation
int binarySearchR(int arr[], int key, int high, int low)
{
  int mid;
  if (low <= high)
  {
    mid = (low + high) / 2;
    if (key == arr[mid])
    {
      return mid;
    }
    else if (key < arr[mid])
    {
      return binarySearchR(arr, key, mid - 1, low); // chat gpt fix it for me
    }
    else
    {
      return binarySearchR(arr, key, high, mid + 1); // you must put the fucking RETURN before calling the recursive function
    }
  }

  return -1;
}

// ##################################
// ####### GET index  ###############
// ##################################

int get(Array arr, int index)
{
  if (index < arr.length && index >= 0)
  {
    return arr.A[index];
  }
  return int(NULL);
}

// ##################################
// ####### Max number  ##############
// ##################################

int max(Array arr)
{
  int max = arr.A[0];
  for (int i = 0; i < arr.length; i++)
  {
    if (arr.A[i] > max)
    {
      max = arr.A[i];
    }
  }
  return max;
}
// ################################################
//  minimum implementation is the same mechanism ##
// ################################################

// #######################
// ###### summation ######
// #######################

int sum(Array arr)
{
  int total = 0;
  for (int i = 0; i < arr.length; i++)
  {
    total += arr.A[i];
  }
  return total;
}

// ###############################33
// #########3 Reversing ############
// #################################

/*
void reverse(Array *arr)
{
  // while debugging
  //  ifound out the condition is while i >= j only don't push till the end you will revers it agin
  for (int i = arr->length - 1, j = 0; i >= j; i--, j++)
  {
    swap(arr->A[i], arr->A[j]);
  }
}
*/
// another techinque in reversing with while loop :::::::;;;;;;;;
void reverse(Array *arr)
{
  int i, j;
  i = 0;
  j = arr->length - 1;
  while (i < j)
  {
    swap(arr->A[i++], arr->A[j--]);
  }
}

int main(int argc, char const *argv[])
{
  // initializing an ARRAY
  Array arr;
  cout << "enter size\n";
  cin >> arr.size;
  cout << "enter number of numbers you want\n";
  cin >> arr.length;

  arr.A = (int *)malloc(arr.size * sizeof(int));

  // entering data on array
  for (int i = 0; i < arr.length; i++)
  {
    arr.A[i] = i;
  }

  insert(arr, 2, 25);
  add(arr, 13);
  // Delete(arr, 1);
  // cout << get(arr, 70);
  // cout << sum(arr);
  // cout << max(arr);
  //  cout << binarySearchR(arr.A, 35, arr.length - 1, 0) << " ";
  display(arr);
  reverse(&arr);
  display(arr);

  free(arr.A);

  return 0;
}
