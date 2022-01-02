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
        A   B   C   D   E   B   D   D   E
    0   1   2   3   4   5   6   7   8   9
B  -1  -1   1   1   1   1   5   5   5   5
D  -1  -1  -1  -1   1   1   1   5   5   5
E  -1  -1  -1  -1  -1   1   1   1   1   5

*/

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
        A   B   C   D   E   B   D   D   E
    0   1   2   3   4   5   6   7   8   9
B  -1  -1   1   1   1   1   5   5   5   5
D  -1  -1  -1  -1   1   1   1   5   5   5
E  -1  -1  -1  -1  -1   1   1   1   1   5

*/

class Solution
{
public:
  string minWindow(string s1, string s2)
  {
    int m = s2.size(), n = s1.size();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

    for (int i = 0; i <= n; i++)
      dp[0][i] = i;

    for (int i = 1; i <= m; i++)
    {
      for (int j = 1; j <= n; j++)
      {
        if (s1[j - 1] == s2[i - 1])
          dp[i][j] = dp[i - 1][j - 1];
        else
          dp[i][j] = dp[i][j - 1];
      }
    }

    int minLen = INT_MAX, start = -1;
    for (int i = 1; i <= n; i++)
    {
      if (dp[m][i] != -1)
      {
        int len = i - dp[m][i];

        if (len < minLen)
        {
          minLen = len;
          start = dp[m][i];
        }
      }
    }

    // for (int i = 0; i <= m; i++)
    // {
    //   for (int j = 0; j <= n; j++)
    //   {
    //     cout << setw(3) << dp[i][j] << " ";
    //   }
    //   cout << endl;
    // }

    return (start == -1) ? "" : s1.substr(start, minLen);
  }
};
