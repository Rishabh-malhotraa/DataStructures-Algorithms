/*
 ____  _     _           _     _       __  __       _ _           _             
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _ 
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

/*
  EVEN     -> +
  PRIME    -> *
  ODD      -> -
  composite   -> /
*/

bool isPrime(int n)
{
  for (int i = 2; i < n; i++)
    if (n % i == 0)
      return false;

  return true;
}

string evaluate(string s, bool &negative)
{

  int a = s[0] - '0';
  a = a * (negative ? -1 : 1);
  int b = s[1] - '0';
  int c = 0;
  if (a % 2 == 0)
  {
    c = a + b;
    if (c > 0)
      negative = false;
  }
  else if (isPrime(a) == true)
  {
    c = a * b;
  }
  else if (a % 2 == 1)
  {
    c = abs(a - b);
    if (a - b < 0)
      negative = true;
  }
  else
  {
    c = a / b;
  }
  if (c == 0)
    s = s.substr(2);
  else
    s = to_string(c) + s.substr(2);

  return s;
}

string getResult(string &nums)
{
  string value;
  int n = nums.size();
  value.push_back(nums[0]);
  int idx = 1;
  bool negative = false;
  while (idx < n)
  {
    value.push_back(nums[idx++]);

    while (value.size() > 1)
      value = evaluate(value, negative);
    

    cout << value << endl;
      
  }

  cout << value << endl;
  return ((negative ? "-" : "") + value);
}

int main()
{

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif
    
  string s = "98668317981";

  cout << getResult(s) << endl;
  return 0;
}