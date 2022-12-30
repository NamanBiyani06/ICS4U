#include <iostream>
using namespace std;

int sum(int[], int);
int recursive_sum(int[], int);

int main()
{
  int n; cin >> n;
  int * array = new int[n];

  for(int i = 0; i < n; i++) cin >> array[i];

  // cout << sum(array, n) << endl;

  cout << recursive_sum(array, n-1) << endl;
}

int sum(int array[], int size)
{
  int sum = 0;
  for(int i = 0; i < size; i++) sum += array[i];
  return sum;
}

int recursive_sum(int array[], int index)
{
  if(index != -1) return (array[index] + recursive_sum(array, index-1));
  return 0;
}