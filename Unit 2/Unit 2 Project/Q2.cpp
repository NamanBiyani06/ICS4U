#include <iostream>
using namespace std;

int gcd(int, int);

int main()
{
  int x, y; cin >> x >> y;
  cout << gcd(x, y) << endl;
}

int gcd(int x, int y)
{
  if(y == 0) return x;
  else return gcd(y, x%y);
}