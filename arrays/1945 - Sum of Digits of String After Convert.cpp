#include <bits/stdc++.h>
using namespace std;

// implementation - strings

class Solution
{
public:
  int getLucky(string s, int k)
  {
    string num;
    int number = 0;
    for (char ch : s)
    {
      int x = ch - 'a' + 1;
      num += to_string(x);
    }
    while (k--)
    {
      number = 0;
      for (int i = 0; i < num.size(); i++)
      {
        number += (num[i] - '0');
      }
      num = to_string(number);
    }
    return number;
  }
};
