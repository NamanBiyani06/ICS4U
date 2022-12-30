#include <iostream>
using namespace std;

void bubbleSort(int[], int);
void printArray(int[], int);
void swap(int&, int&);

int main()
{
  /* Question #1 */
  cout << "Q1" << endl;
}

void bubbleSort(int array[], int length)
{
  for(int sorted = 0; sorted < length - 1; sorted++)
  {
    for(int i = 0; i < (length - 1) - sorted; i++)
    {
      if(array[i] > array[i + 1]) swap(array[i], array[i + 1]);

      printArray(array, length);
    }
  }
}

void swap(int &a, int &b)
{
  int c = a; a = b; b = c;
}

void printArray(int array[], int length)
{
  for(int i = 0; i < length; i++) cout << array[i] << " ";
  cout << endl;
}