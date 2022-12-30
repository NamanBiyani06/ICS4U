#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
  //input
  int size, target; cin >> size >> target;

  //init
  int* *square = new int*[size];
  for(int i = 0; i < size; i++)
  {
    square[i] = new int[size];

    fill_n(square[i], size, 0);
  }

  //algorithm
  square[size/2][0] = 1;

  //dealloc
}