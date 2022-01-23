/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> rearrangeArray(vector<int> &nums)
  {
    vector<int> pos, neg;

    for (int el : nums)
    {
      if (el > 0)
        pos.push_back(el);
      else
        neg.push_back(el);
    }

    vector<int> result;

    for (int i = 0; i < pos.size(); i++)
    {
      result.push_back(pos[i]);
      result.push_back(neg[i]);
    }
    return result;
  }
};