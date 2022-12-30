#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

void reverse(string &str, int, int);
bool isPalindrome(string);

int main()
{
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