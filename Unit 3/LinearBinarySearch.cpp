#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

/* function declaration */
int linearSearch(int[], int, int);
int binarySearch(int[], int, int);

int main()
{
  int n, x; cin >> n >> x;
  int array[n];
  
  for(int i = 0; i < n; i++) cin >> array[i];
  
  sort(array, array + n);

  /* linear search */
  cout << "Linear Search" << endl;

  int linearSearchReturn = linearSearch(array, n, x);

  if(linearSearchReturn == -1) cout << "not found" << endl << endl;
  else cout << "found at index " << linearSearchReturn << endl << endl;

  /* binary search */
  cout << "Binary Search" << endl;

  int binarySearchReturn = binarySearch(array, n, x);
  
  if(binarySearchReturn == -1) cout << "not found" << endl;
  else cout << "found at index " << binarySearchReturn << endl;
}

int linearSearch(int array[], int length, int value)
{
  for(int i = 0; i < length; i++)
  {
    for(int j = i; j < length; j++)
    {
      cout << array[j] << " ";
    }
    cout << endl;
    if(array[i] == value) return i;
  }
  return -1;
}

int binarySearch(int array[], int length, int value)
{
  int left, right;
  left = 0;
  right = length - 1;

  while((right - left) > 0)
  {
    for(int i = left; i <= right; i++) cout << array[i] << " ";
    cout << endl;

    float middleFloat = ((right + left)/2.0);
    int middle = round(middleFloat);
    int middleValue = array[middle];

    if(middleValue != value)
    {
      if(middleValue > value) right = middle - 1;
      if(middleValue < value) left = middle + 1;
    }
    else
    {
      cout << array[middle] << endl;
      return (middle);
    }
  }
  if((right - left) == 0 && array[right] == value)
  {
    cout << array[right] << endl;
    return right;
  }
  if(value > array[right]) cout << array[right] << endl;
  else cout << array[left] << endl;
  return -1;
}