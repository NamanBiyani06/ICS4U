#include <iostream>
#include <cmath>
using namespace std;

float recursiveAverage(float[], int);

int main()
{
  int n; cin >> n;
  float * array = new float[n];
  for(int i = 0; i < n; i++)
  {
    cin >> array[i];
  }

  cout << round(recursiveAverage(array, n) * 10.0)/10.0 << endl;
}

float recursiveAverage(float array[], int i)
{
  if(i == 0) return array[0];
  return recursiveAverage(array, i-1) + ((1.0/i) * (array[i-1] - recursiveAverage(array, i-1)));
}