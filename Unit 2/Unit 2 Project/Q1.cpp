#include <iostream>
using namespace std;

int recursiveOne(int);
int recursiveTwo(int);

int main()
{
  int n; cin >> n;
  cout << recursiveOne(n) << "\n";
  cout << recursiveTwo(n) << "\n";
}

int recursiveOne(int n)
{
  if(n == 1) return 3;
  else return recursiveOne(n-1) - 2;
}

int recursiveTwo(int n)
{
  if(n == 1) return -1;
  else return 2 * recursiveTwo(n-1);
}