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
  bool isValidSerialization(string preorder)
  {
    if (preorder.empty())
      return false;
    preorder += ',';
    int sz = preorder.size(), idx = 0;
    int capacity = 1;
    for (idx = 0; idx < sz; idx++)
    {
      if (preorder[idx] != ',')
        continue;
      capacity--;
      if (capacity < 0)
        return false;
      if (preorder[idx - 1] != '#')
        capacity += 2;
    }
    return capacity == 0;
  }
};