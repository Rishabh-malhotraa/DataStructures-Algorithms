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
  int numberOfBeams(vector<string> &bank)
  {
    int m = bank[0].size(), n = bank.size();
    long long prev = 0, laser = 0;
    for (string floor : bank)
    {
      long long count = 0;
      for (char ch : floor)
        if (ch == '1')
          count++;

      if (count)
      {
        laser += count * prev;
        prev = count;
      }

      // cout << laser << " " << prev << " " << count << endl;
    }
    return laser;
  }
};