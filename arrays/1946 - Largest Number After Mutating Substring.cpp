#include <bits/stdc++.h>
using namespace std;
/*
"132",
change = [9,8,5,0,3,6,4,2,6,8]


Very annoying edge cases || The Questions Description wasn't apt I fell or maybe I misintepretted
"330"
[9,3,6,3,7,3,1,4,5,8] -> "339"

"334111"
[0,9,2,3,3,2,5,5,5,5] -> "334999"
*/

class Solution
{
public:
  string maximumNumber(string num, vector<int> &change)
  {
    string result;
    int n = num.size();
    bool flag = false;
    for (int i = 0; i < num.size(); i++)
    {
      int idx = num[i] - '0';

      int changes = change[idx];

      if (change[idx] > idx)
      {
        result += to_string(change[idx]);
        flag = true;
      }
      else if (change[idx] == idx)
        result += to_string(change[idx]);
      else
      {
        if (flag == false)
        {
          result += to_string(idx);
        }
        if (flag == true)
        {
          result += num.substr(i, n);
          break;
        }
      }
    }
    return result;
  }
};