#include <iostream>
using namespace std;

int * twopowerInit(int n, int arr[], int count);
int power(int x, int y);

int main()
{
  int n;
  int count = 0;
  cin >> n;

  int arr[n];

  int * arrFilled;
  arrFilled = twopowerInit(n, arr, count);

  for(int i = 0; i < n; i++)
  {
    cout << *(arrFilled + i) << " ";
  }
  cout << endl;

}

int * twopowerInit(int n, int arr[], int count)
{
  if(count < n)
  {
    arr[count] = power(2, count);
    twopowerInit(n, arr, count + 1);
  }

  return arr;

}

int power(int x, int y)
{
  if(y != 0)
  {
    return x * power(x, y - 1);
  }
  else if(y == 0)
  {
    return 1;
  }
  return 0;
}