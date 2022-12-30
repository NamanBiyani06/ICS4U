#include <iostream>
#include <string.h>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

int * selectionSort(int[], int);
void selectionSort(int[], int, int);
void printArray(int[], int);
void printStringArray(string[], int);
void swap(int &a, int &b);
void Q1();

int main()
{
  /* Question #1 */
  Q1();

  /* Question #2 */
  // This would reverse the order that the list is sorted in
  // Thus going [greatest, least]

  /* Question #3 */
  // (a)
  // Instead of swapping immediately, add a checker to make sure the swap is useful:
  /*
  if(array[nextSmallest] < array[sorted])
    swap(array[nextSmallest], array[sorted]);
  */
  // (b)
  // Unstability is more efficient as there is one less condition to be met

  /* Question #4 */
  cout << "Q4" << endl;

  int array[] = {8, 9, 6, 1, 2, 4};
  printArray(array, 6);
  int * arraySorted = selectionSort(array, 6);

  /* Question #5 */
  cout << "Q5" << endl;

  int n, k; cin >> n >> k;
  int * arrayInput = new int[n];
  for(int i = 0; i < n; i++) cin >> arrayInput[i];
  selectionSort(arrayInput, n, k);
}

int * selectionSort(int array[], int length)
{
  // var nextSmallest holds the smallest value index
  int nextSmallest;

  // loop through the array while keeping track of how much is sorted
  for(int sorted = 0; sorted < length - 1; sorted++)
  {
    // the smallest value is current the sorted value
    nextSmallest = sorted;
    for(int i = sorted + 1; i < length; i++)
    {
      // find the smallest value index after array[sorted]
      if(array[i] < array[nextSmallest]) nextSmallest = i;
    }

    // swap the smallest with the sorted value
    swap(array[nextSmallest], array[sorted]);

    printArray(array, length);
  }

  return array;
}

void selectionSort(int array[], int length, int k)
{
  int nextLargest;

  for(int sorted = length - 1; sorted > (length - 1) - k; sorted--)
  {
    nextLargest = sorted;

    for(int i = 0; i <= sorted; i++)
    {
      if(array[i] > array[nextLargest]) nextLargest = i;
    }

    swap(array[sorted], array[nextLargest]);
  }

  printArray(array, length);
}

void swap(int &a, int &b)
{
  int c; c = a; a = b; b = c;
}

void printArray(int array[], int length)
{
  for(int i = 0; i < length; i++) cout << array[i] << " ";
  cout << endl;
}

void printStringArray(string array[], int length)
{
  for(int i = 0; i < length; i++) cout << array[i] << " ";
  cout << endl;
}

void Q1()
{
  cout << "Q1" << endl;

  string array[] = {"Robert", "Brian", "Victor", "David", "Scott"};

  printStringArray(array, 5);

  int length = 5;

  int nextLargest;

  for(int sorted = length - 1; sorted > 0; sorted--)
  {
    nextLargest = sorted;

    for(int i = sorted - 1; i >= 0; i--)
    {
      if(array[i] > array[nextLargest]) nextLargest = i;
    }

    swap(array[sorted], array[nextLargest]);

    printStringArray(array, length);
  }
}
