#include <iostream>
using namespace std;

int power(int x, int y);

int main()
{
  int x;
  int y;

  cin >> x;
  cin >> y;

  string output = to_string(power(x, y));
  cout << output << endl;
}

int power(int x, int y)
{
  switch(y)
  {
    case 0:
      return 1;
    default:
      return(x * power(x, y - 1));
  }
}