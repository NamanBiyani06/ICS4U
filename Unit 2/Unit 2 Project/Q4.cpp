#include <iostream>
#include <ratio>
#include <string>
using namespace std;

void reverse(string &str, int, int);
string decimalToBinary(int, string);

int main()
{
  int n; cin >> n;
  string binary = "";
  string out = decimalToBinary(n, binary);
  reverse(out, 0, out.length() - 1);
  if(out == "") cout << "0" << endl;
  else cout << out << endl;
}

string decimalToBinary(int n, string binary)
{
  if(n == 0) return binary;
  binary += to_string(n % 2);
  return decimalToBinary(n / 2, binary);
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