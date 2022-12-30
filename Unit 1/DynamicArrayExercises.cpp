#include <iostream>
using namespace std;

void q1a();
void q1b();
void q1c();
void q1d();

int main()
{
  q1a();
  q1b();
  q1c();
  q1d();
  return 0;
}

void q1a()
{
  int length;
  cout << "Enter the length of the dynamic array:";
  cin >> length;
  int * dynamicArray = new int[length];

  cout << "Enter the contents of the array:";
  for(int i = 0; i < length; i++) cin >> dynamicArray[i];
  for(int i = 0; i < length; i++) cout << dynamicArray[i] << " ";
  cout << endl;
  delete[] dynamicArray;
}

void q1b() 
{
  int length;
  cout << "Enter the length of the dynamic array:";
  cin >> length;
  int * dynamicArrayb = new int[length];

  cout << "Enter the contents of the array:";
  for(int i = 0; i < length; i++) cin >> dynamicArrayb[i];
  for(int i = length; i > -1; i--) cout << dynamicArrayb[i] << " ";
  cout << endl;
  delete[] dynamicArrayb;
}

void q1c()
{
  srand(time(0));
  int length;
  cout << "Enter the length of the dynamic array:";
  cin >> length;
  int * dynamicArrayc = new int[length];

  int sum = 0;
  cout << "Enter the contents of the array:";
  for(int i = 0; i < length; i++) dynamicArrayc[i] = rand() % 50 + 1;
  for(int i = length; i > -1; i--) sum += dynamicArrayc[i];

  cout << sum << endl;;
  delete[] dynamicArrayc;
}

void q1d()
{
  int length1, length2;
  cout << "Enter the length of the dynamic array 1:";
  cin >> length1;
  int * dynamicArray1 = new int[length1];
  cout << "Enter the length of the dynamic array 2:";
  cin >> length2;
  int * dynamicArray2 = new int[length2];

  cout << "Enter the contents of the array 1: ";
  for(int i = 0; i < length1; i++) cin >> dynamicArray1[i];
  cout << endl;
  cout << "Enter the contents of the array 2: ";
  for(int i = length2; i > -1; i--) cin >> dynamicArray1[i];
  cout << endl;

  int * dynamicArray3 = new int[length1 + length2];
  for (int i = 0; i < length1; i++)
  {
    dynamicArray3[i] = dynamicArray1[i];
  }
  for (int i = length1; i < length2; i++)
  {
    dynamicArray3[i] = dynamicArray2[i];
  }
  
  cout << "Array 1: ";
  for (int i = 0; i < length1; i++)
  {
    cout << dynamicArray1[i];
  }
  cout << endl;

  cout << "Array 2: ";
  for (int i = 0; i < length2; i++)
  {
    cout << dynamicArray2[i];
  }
  cout << endl;

  cout << "Array 3: ";
  for (int i = 0; i < length1 + length2; i++)
  {
    cout << dynamicArray3[i];
  }
  cout << endl;
  
  delete[] dynamicArray1;
  delete[] dynamicArray2;
  delete[] dynamicArray3;
}
