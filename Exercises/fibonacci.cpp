
#include <iostream>
using namespace std;

int fib(int n);

int main()
{
  int n;
  cin >> n;
  string output = to_string(fib(n));
  cout << output << endl;
}

int fib(int n)
{
  switch(n)
  {
    case 0:
      return 0;
    case 1:
      return 1;
    default:
      return fib(n - 1) + fib(n - 2);
  }
}
