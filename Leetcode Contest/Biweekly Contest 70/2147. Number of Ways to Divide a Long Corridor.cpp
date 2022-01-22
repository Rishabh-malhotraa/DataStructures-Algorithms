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
  int numberOfWays(string corridor)
  {
    int count = 0;
    for (char &el : corridor)
      if (el == 'S')
        count++;

    if (count % 2 != 0 || count == 0)
      return 0;

    vector<long long> spaces;

    int space = 0;
    count = 0;
    for (char &el : corridor)
    {

      if (el == 'S')
      {
        if (count == 2)
        {
          spaces.push_back(space + 1);
          space = 0;
          count = 0;
        }
        count++;
      }
      if (el == 'P' && count == 2)
        space++;
    }

    // spaces.push_back(space + 1);

    long long ways = 1;
    int MOD = 1e9 + 7;
    for (long long space : spaces)
    {
      // cout << space << " ";
      ways = (ways * space) % MOD;
    }
    // cout << endl;
    return ways;
  }
};