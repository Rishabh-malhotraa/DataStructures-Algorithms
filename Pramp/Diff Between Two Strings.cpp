/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

// https://meet.google.com/daf-pkid-jqx

/*


source = ABCDEFG

          ABD
target = ABDFFGH

A B C D E F G

A B D F F G H

A B  {COULD EITHE ADD 'D' OR DELETE 'C'}


one recursive call we would delete and one we would add

-->  7   -> 4  2^(N)

    (1,1)  [A  -> AB
   {} A B D F F G H
{}  0 1 2 3 4 5 6 7    -- BASE Conditions          A -> AB -> 1    min(dp[i-1][j], dp[i][j-1]) + 1
A   1 0 1 2 3 4 5 6
B   2 1 0 1                                                      source AB    target A
C   3
D   4
E   5
F   6
G   7

    {} A B D ^  -(D)
{}  0  1 2 3 |
A      0 1 2 |
B        0 1 |
       <-----
           +D                                   ^
       if we are moving sideway basicaltr <-  |







if the src[i] == target[j]  dp[i][j] = dp[i-1][j-1]

ABZZC   src

DEC    trg

minmimum edits for ABZZ and DE

BAT

DAB
      MIN[edit_distanc(BAT , DA), edit_distance(BA, DAT)]


  TIME Complexity  -> O(n*n) + O(M+N)
  Space Complexity -> O(n*m)


        // if the dp values are same we would like to go up meaning we would like to remove from the source
        // s
        // o
        // u     *
        // r     []


        ABDE G
        FSDA G

       src    ABD E G
     target   ZEF G

*/

using namespace std;

vector<string> diffBetweenTwoStrings(const string &s, const string &t)
{

  string source = s;
  string target = t;

  int m = source.size(), n = target.size();

  vector<string> result;
  vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));

  for (int j = 0; j < n + 1; j++)
    dp[0][j] = j;

  for (int i = 0; i < m + 1; i++)
    dp[i][0] = i;

  for (int i = 1; i < m + 1; i++)
  {
    for (int j = 1; j < n + 1; j++)
    {
      if (source[i - 1] == target[j - 1])
        dp[i][j] = dp[i - 1][j - 1];
      else
        dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
    }
  }

  for (int i = 0; i < m + 1; i++)
  {
    for (int j = 0; j < n + 1; j++)
    {
      cout << dp[i][j] << "    ";
    }
    cout << endl;
  }

  queue<pair<int, int>> q;

  q.push({1, 1});

  while (q.empty() == false)
  {
    pair<int, int> curr = q.front();
    int i = curr.first, j = curr.second;
    q.pop();

    if (i == m && j == n)
    {
      while ((j - 1) < target.size())
      {
        string str = "+" + string(1, target[j - 1]);
        result.push_back(str);
        j++;
      }
      return result;
    }

    int bottom = (i == m) ? INT_MAX : dp[i + 1][j];
    int right = (j == n) ? INT_MAX : dp[i][j + 1];

    if (source[i - 1] == target[j - 1])
    {
      string s = string(1, source[i - 1]);
      result.push_back(s);

      i = i == m ? i : i + 1;
      j = j == n ? j : j + 1;

      q.push({i, j});
    }
    else
    {
      if (bottom <= right)
      {
        string str = "-" + string(1, source[i - 1]);
        result.push_back(str);
        q.push({i + 1, j});
      }
      else
      {
        string str = "+" + string(1, target[j - 1]);
        result.push_back(str);
        q.push({i, j + 1});
      }
    }
  }
  return vector<string>{};
}

int main()
{
  string s1, s2;
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  cin >> s1 >> s2;
  auto res = diffBetweenTwoStrings(s1, s2);
  for (string el : res)
    cout << el << " ";
  return 0;
}

/*
   {} A B D F F G H   /// target
{}  0 1 2 3 4 5 6 7
A   1 0 1 2 3 4 5 6
B   2 1 0 1 2 3 4 5
C   3 2 1 2 3 4 5 6
D   4 3 2 1 2 3 4 5
E   5 4 3 2 3 4 5 6
F   6 5 4 3 2 3 4 5
G   7 6 5 4 3 4 3 4

A B -C D +F -E F G +H
A B -C D -E F +F G +H
*/