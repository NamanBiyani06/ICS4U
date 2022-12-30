#include <iostream>
using namespace std;

int main()
{
  int number;
  int * pnumber;

  number = 123;
  pnumber = &number;

  cout << number << endl;
  cout << &number << endl;
  cout << pnumber << endl;
  cout << *pnumber << endl;

  int num1 = 50, num2 = 100;
  int * pnum = NULL;
  pnum = &num1;
  *pnum += 10;
  cout << num1 << endl;
  cout << *pnum << endl;

  pnum = &num2;
  *pnum = *pnum*10;
  num1 = *pnum;
  cout << num1 << endl;
  cout << pnum << endl;
  cout << *pnum << endl;

  double value1, value2;
  value1 = 200000;
  double * lPtr;
  lPtr = &value1;
  cout << *lPtr << endl;
  value2 = *lPtr;
  cout << value2 << endl;
  cout << &value1 << endl;
  cout << &value2 << endl;
  cout << lPtr << endl;
  //The address of lPtr is the same as the address of value1
  
}