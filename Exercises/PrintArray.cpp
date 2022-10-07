#include <iostream>
using namespace std;

void printArrayRecursive(int arr[], int n, int count);

int main()
{
  int n;
  int count = 0;
  cin >> n;

  int arr[n];
  for(int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  printArrayRecursive(arr, n, count);
  cout << endl;
}

void printArrayRecursive(int arr[], int len, int count)
{ 
  if(count != len)
  {
    cout << arr[count] << " ";
    printArrayRecursive(arr, len, count+1);
  }
}