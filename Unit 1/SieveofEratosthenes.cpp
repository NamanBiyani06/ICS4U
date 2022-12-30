#include <iostream>
using namespace std;

void sieve(int[], int);

int main()
{
  int n; cin >> n;

  int * array = new int[n + 1];

  fill_n(array, n + 1, 1);

  sieve(array, n + 1);

  for(int i = 2; i < n + 1; i++)
  {
    if(array[i] == 1)
    {
      cout << i << " ";
    }
  }
  cout << endl;

  return 0;
}

void sieve(int array[], int size)
{
  for (int i = 2; i < size; i++) 
  {
    if(array[i] == 1)
    {
      for(int j = i + i; j < size; j += i)
      {
        array[j] = 0;
      }
    }
  }
}