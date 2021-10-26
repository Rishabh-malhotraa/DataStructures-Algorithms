/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
"a*"
"" "A" "aa"  .. "aaaaa" [.*]


a    acd a

ab   ac


a   ab  abbbb {}


a  a""  ab  abbb


ab*  a


a    a
ab   a


             X
   {}  a  b  b
{}  T  F  F  F
a   F  T  F  F
b   F  F  T  F
*   F  T  T


pattern[i] = '*'
1.  check if the current <text[j]  == text[j-1]

dp[i][j] = dp[i][j-1]


a  ab*

   {}  a  c  d
{}  T  F  F  F
a   F  T  F  F
b   F  F  F  F
*   F  T  F  F
c   F  F  T  F
.   F  F  F  T

TC: O(N*M)
SC: O(N*M)

   {}
{}  T
a   F
*   T
b   F
*   T



a [b*]
X -> dp[i-1][j]  || dp[i-2][j]


// grid 1-> s[i-1]
*/

void processGrid(vector<vector<bool>> &dp, int m, int n, string pattern)
{

  dp[0][0] = true;

  for (int i = 1; i < n + 1; i++)
    dp[0][i] = false;

  for (int i = 1; i < m + 1; i++)
  {
    if (pattern[i - 1] == '*')
      dp[i][0] = dp[i - 2][0];
    else
      dp[i][0] = false;
  }
  return;
}

bool isMatch(const string &text, const string &pattern)
{
  int m = pattern.size(), n = text.size();
  vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

  processGrid(dp, m, n, pattern);

  for (int i = 1; i < m + 1; i++)
  {
    for (int j = 1; j < n + 1; j++)
    {
      if (pattern[i - 1] == '.')
      {
        dp[i][j] = dp[i - 1][j - 1];
      }
      else if (pattern[i - 1] == '*')
      {
        // bool nil = dp[i - 2][j];
        // bool add = (pattern[i - 2] == text[j - 1] || pattern[i - 2] == '.') && dp[i][j - 1];
        // dp[i][j] = (nil || add);
        dp[i][j] = dp[i - 1][j] || dp[i - 2][j];

        if (pattern[i - 2] == text[j - 1] || pattern[i - 2] == '.')
          dp[i][j] = dp[i][j] || dp[i][j - 1];
      }
      else
      {
        if (pattern[i - 1] == text[j - 1])
          dp[i][j] = dp[i - 1][j - 1];
      }
    }
  }

  return dp[m][n];
}

int main()
{
  string pattern = "ab*d", text = "abbdbb";
  cout << isMatch(text, pattern) << endl;
  return 0;
}