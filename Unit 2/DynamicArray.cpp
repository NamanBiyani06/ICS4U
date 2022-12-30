#include <cstdlib>
#include <iostream>
using namespace std;

void init_array(int [], int);

int main()
{
  srand(time(NULL));
  int array[10];
  init_array(array, 9);
  for(int i = 0; i < 10; i++) cout << array[i] << endl;
}

void init_array(int array[], int index)
{
  if(index != -1)
  {
  array[index] = (rand() % 50 + 1);
  init_array(array, index-1);
  }
}