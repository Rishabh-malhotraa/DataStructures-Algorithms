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

      <---
ABC   BCD


  C
 B
A

              BCD
A - B-C   =>  B-C-D


C -> BC  -> ABC


B -> BC

Longest common suffix and prefix

     A
    B
   C


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




    AAA BBB CCC DDD BBB CCC
DDD   0  0   0    1   0   0
BBB   0  1   0    0   2   0
CCC   0  0   2    0   0   3
*/

vector<string> mergeScreenshots(vector<string> &screenshot1, vector<string> &screenshot2)
{
  int n = screenshot1.size();
  vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

  int maxLen = 0;

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      // use Rabin Karp to hash the strings for quicker checking
      if (screenshot1[i - 1] == screenshot2[j - 1])
        dp[i][j] = (dp[i - 1][j - 1] != -1) ? 1 + dp[i - 1][j - 1] : -1;
      else
        dp[i][j] = -1;
      if (i == n)
        maxLen = max(maxLen, dp[i][j]);
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

vector<string> mergeScreenshots(vector<string> &screenshot1, vector<string> &screenshot2)
{
  int n = screenshot1.size();
  vector<int> hashS1(n, 0), hashS2(n, 0);
  vector<vector<int>> dp(n, vector<int>(n, 0));

  // preComputeHash(screenshot1, screenshot2, hashS1, hashS2);

  int maxLen = 0;
  for (int j = 0; j < n; j++)
  {
    if (screenshot2[j] == screenshot1.back()) // help here
      maxLen = max(maxLen, dfs(dp, screenshot1, screenshot2, n - 2, j - 1, 0));
  }

  vector<string> document = screenshot1;

  for (int i = maxLen; i < n; i++)
    document.push_back(screenshot2[i]);

  return document;
}

/**************************************
 *  WORKING CODE
 * **********************************/

/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

int dfs(vector<vector<int>> &dp, vector<string> &s1, vector<string> &s2, int i, int j, int len)
{
  if (j < 0)
    return len;

  if (i < 0)
    return 0;

  if (dp[i][j] != 0)
    return dp[i][j];

  // hashS1[i] == hashS2[j] &&  checkstring(s1[i], s2[j])
  if (s1[i] == s2[j]) // help here
    return dp[i][j] = dfs(dp, s1, s2, i - 1, j - 1, len + 1);

  return 0;
}

vector<string> mergeScreenshots(vector<string> &screenshot1, vector<string> &screenshot2)
{
  int n = screenshot1.size();
  vector<int> hashS1(n, 0), hashS2(n, 0);
  vector<vector<int>> dp(n, vector<int>(n, 0));

  // preComputeHash(screenshot1, screenshot2, hashS1, hashS2);

  int maxLen = 0;
  for (int j = 0; j < n; j++)
    maxLen = max(maxLen, dfs(dp, screenshot1, screenshot2, n - 1, j, 0));

  vector<string> document = screenshot1;
  cout << maxLen << endl;
  document.insert(document.end(), screenshot2.begin() + maxLen, screenshot2.end());

  return document;
}

void solve()
{
  int n;
  cin >> n;
  vector<string> arr(n), brr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  for (int i = 0; i < n; i++)
    cin >> brr[i];

  auto result = mergeScreenshots(arr, brr);

  for (string el : result)
    cout << el << endl;

  return;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int t;
  cin >> t;
  while (t--)
  {
    solve();
  }
  return 0;
}

// O(N*m) Solution
// UPDATE: No this is not N*m since comparing two strings would be
// m*n that would increase the TC to m*m*n
// Update Update :: Does using unordered_set solve the problem
/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

vector<string> mergeScreenshots(vector<string> &screenshot1, vector<string> &screenshot2)
{
  int m = screenshot1.size(), n = screenshot1[0].size();
  string prefix, suffix;
  int len = 0;

  unordered_set<string> cache;
  for (int i = m - 1, j = 0; j < m; i--, j++)
  {
    suffix = screenshot1[i] + suffix;
    prefix += screenshot2[j];

    if (prefix == suffix) // O(m*n) in worst case
      len = j + 1;
  }

  vector<string> document = screenshot1;
  document.insert(document.end(), screenshot2.begin() + len, screenshot2.end());

  return document;
}

vector<string> mergeScreenshots(vector<string> &screenshot1, vector<string> &screenshot2)
{
  int m = screenshot1.size(), n = screenshot1[0].size();
  deque<string> prefix, suffix;
  int len = 0;

  for (int i = m - 1, j = 0; j < m; i--, j++)
  {
    suffix.push_front(screenshot1[i]);
    prefix.push_back(screenshot2[j]);

    if (prefix == suffix)
      len = j + 1;
  }

  vector<string> document = screenshot1;
  document.insert(document.end(), screenshot2.begin() + len, screenshot2.end());

  return document;
}

vector<int> getZArray(string text)
{
  int n = text.size();
  vector<int> z(n, 0);
  for (int i = 1, l = 0, r = 0; i < n; i++)
  {
    if (i <= r)
      z[i] = min(r - i + 1, z[i - l]);
    while (z[i] + i < n && text[z[i]] == text[z[i] + i])
      z[i]++;

    if (i + z[i] - 1 > r)
      l = i, r = i + z[i] - 1;
  }
  return z;
}

vector<string> mergeScreenshots(vector<string> &screenshot1, vector<string> &screenshot2)
{
  string s1, s2;
  int n = screenshot1.size(), m = screenshot1[0].size();
  for (int i = 0; i < n; i++)
    s1 += screenshot1[i], s2 += screenshot2[i];

  // ABC  BCD
  // BCD#ABC
  vector<int> arr = getZArray(s2 + "#" + s1);
  int len = 0;
  for (int el : arr)
    if (el % m == 0)
      len = max(len, el / m);

  vector<string> document = screenshot1;
  document.insert(document.end(), screenshot2.begin() + len, screenshot2.end());
  return document;
}

void solve()
{
  int n;
  cin >> n;
  vector<string> arr(n), brr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  for (int i = 0; i < n; i++)
    cin >> brr[i];

  auto result = mergeScreenshots(arr, brr);

  for (string el : result)
    cout << el << endl;

  return;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int t;
  cin >> t;
  while (t--)
  {
    solve();
  }
  return 0;
}
