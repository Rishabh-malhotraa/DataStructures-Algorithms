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
|   |
AAA BBB
O(m+n)

use rolling has -> Rabin karp
precompute the hash value



ss1
AAA
BBB --
CCC  --



ss2
BBB   --
CCC  --
DDD
CCC  --

N pos

i = 0


AAA
BBB    BBB
CCC    CCC    CCC

n rows, m characters


starting ss1[n-1]

and we find possible canidates in ss2-> and we start looking from that position

CCC   -> true
CCC   ->
CCC
CCC   ->


O(N^N)


merged
AAA
BBB
CCC
DDD

AAA
CCC
CCC

CCC
CCC
DDD



AAA
CCC
CCC
DDD



AAA
CCC  - X
CCC  -

CCC  -
CCC  - X
DDD


s1[n-1] == s2[0]

overlap

*/

/*

ss1
AAA
BBB --
CCC  --



ss2
BBB  --
CCC  --
DDD







AAA
BBB
CCC


CCC  ->
CCC  ->
CCC


CCC -> {0, 1,2} // indecies in s2
BBB -> {}
index value>?

we can make certain progess


assign a unique id whenver a new string is given


AAA -> 1
BBB -> 2

AAA -> 1

CCC -> 3


hash_map


AAA BBB
*/

// AAA -> hashFunction(AAA) -> 123543
//                    (BBB) ->
/*

  123 -> A A A  -> 10^3
            (Base(2)*A + Base(1)*A + Base(0)*A)% 10^9+7


*/

/*


/*




    AAA BBB CCC
DDD   0  0   0
BBB   0  1   0
CCC   0  0   2
*/

vector<string> mergedScreenshots(vector<string> &screenshot1, vector<string> &screenshot2)
{
  int n = screenshot1.size();
  vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
  reverse(screenshot2.begin(), screenshot2.end());

  int maxLen = 0, result = 0;

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      // use Rabin Karp to hash the strings for quicker checking
      if (screenshot1[i] == screenshot2[j])
        dp[i][j] = 1 + dp[i - 1][j - 1];
      if (i == n)
        result = max(result, dp[i][j]);
    }
  }
  vector<string> mergedScreenshot(screenshot1.begin(), screenshot1.begin() + n - maxLen);
  mergedScreenshot.insert(mergedScreenshot.end(), screenshot2.begin(), screenshot2.end());

  return mergedScreenshot;
}

int dfs(vector<vector<int>> &dp, vector<string> &s1, vector<string> &s2, int i, int j, int len)
{
  if (dp[i][j] != 0)
    return dp[i][j];

  if (j < 0 || i < 0)
    return 0;

  if (j == 0)
    return len;

  // hashS1[i] == hashS2[j] &&  checkstring(s1[i], s2[j])
  if (s1[i] == s2[j]) // help here
    return dp[i][j] = dfs(dp, s1, s2, i - 1, j - 1, len + 1);

  return 0;
}

vector<string> mergedScreenshots(vector<string> &screenshot1, vector<string> &screenshot2)
{
  int n = screenshot1.size();
  vector<int> hashS1(n, 0), hashS2(n, 0);
  vector<vector<int>> dp(n, vector<int>(n, 0));

  // preComputeHash(screenshot1, screenshot1, hashS1, hashS2);

  vector<string> candidate;
  int maxLen = 0;
  for (int j = 0; j < n; j++)
  {
    if (screenshot2[j] == screenshot1.back()) // help here
      maxLen = max(maxLen, dfs(dp, screenshot1, screenshot2, n - 2, j - 1, 0));
  }

  vector<string> screenshotMerged = screenshot1;

  for (int i = maxLen; i < n; i++)
    screenshotMerged.push_back(screenshot2[i]);

  return screenshotMerged;
}