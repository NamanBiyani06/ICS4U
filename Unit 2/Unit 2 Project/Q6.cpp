#include <iostream>
using namespace std;

long long lcm(long long, long long);
long long gcd(long long, long long);
long long fractorial(long long);

int main()
{
  long long n; cin >> n;

  cout << fractorial(n) << endl;
}

long long fractorial(long long n)
{
  if(n == 0) return 1;
  return lcm(n, fractorial(n-1));
}

long long lcm(long long a, long long b)
{
  return (a/gcd(a, b)) * b;
}

long long gcd(long long a, long long b)
{
  if(b == 0) return a;
  return gcd(b, a % b);
}
