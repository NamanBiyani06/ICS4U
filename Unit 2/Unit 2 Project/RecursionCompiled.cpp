#include <iostream>
#include <pthread.h>
#include <string>
#include <cctype>
#include <algorithm>
#include <ratio>
#include <cmath>
using namespace std;

int recursiveOne(int);
int recursiveTwo(int);
int gcd(int, int); //overloaded gcd with more efficiency due to integers 
void reverse(string &str, int, int);
bool isPalindrome(string);
string decimalToBinary(int, string);
float recursiveAverage(float[], int);
long long lcm(long long, long long);
long long gcd(long long, long long);
long long fractorial(long long);

int main()
{
  //Q1
  int n; cin >> n;
  cout << recursiveOne(n) << "\n";
  cout << recursiveTwo(n) << "\n";

  //Q2
  int x, y; cin >> x >> y;
  cout << gcd(x, y) << endl;

  //Q3
  string str; int size; getline(cin, str); size = str.length();

  //reverse
  reverse(str, 0, size - 1);
  cout << str << endl;

  //palindrome
  transform(str.begin(), str.end(), str.begin(), ::tolower);
  str.erase(remove(str.begin(), str.end(), ' '), str.end());
  bool isPal = isPalindrome(str);
  if(isPal) cout << "true" << endl;
  else cout << "false" << endl;

  //Q4
  cin >> n;
  string binary = "";
  string out = decimalToBinary(n, binary);
  reverse(out, 0, out.length() - 1);
  if(out == "") cout << "0" << endl;
  else cout << out << endl;

  //Q5
  cin >> n;
  float * array = new float[n];
  for(int i = 0; i < n; i++)
  {
    cin >> array[i];
  }

  cout << round(recursiveAverage(array, n) * 10.0)/10.0 << endl;

  //Q6
  long long longN; cin >> longN;

  cout << fractorial(longN) << endl;
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

int gcd(int x, int y)
{
  if(y == 0) return x;
  else return gcd(y, x%y);
}

void reverse(string &str, int low, int high)
{
  if(low < high)
  {
    char temp; 
    temp = str[low];
    str[low] = str[high];
    str[high] = temp;
    reverse(str, low + 1, high - 1);
  }
}

bool isPalindrome(string str)
{
  if(str.length() == 1 || str.length() == 0) return true;
  if(str[0] == str[(str.length() - 1)]) return isPalindrome(str.substr(1, str.length() - 2));
  return false;
}

string decimalToBinary(int n, string binary)
{
  if(n == 0) return binary;
  binary += to_string(n % 2);
  return decimalToBinary(n / 2, binary);
}

float recursiveAverage(float array[], int i)
{
  if(i == 0) return array[0];
  return recursiveAverage(array, i-1) + ((1.0/i) * (array[i-1] - recursiveAverage(array, i-1)));
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
