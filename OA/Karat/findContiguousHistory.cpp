//  ____  _     _           _     _       __  __       _ _           _
// |  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
// | |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
// |  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
// |_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

#include <bits/stdc++.h>
using namespace std;

/*  
We have some clickstream data that we gathered on our client's website. Using cookies, we collected snippets of users' anonymized URL histories while they browsed the site. The histories are in chronological order, and no URL was visited more than once per person.

Write a function that takes two users' browsing histories as input and returns the longest contiguous sequence of URLs that appears in both.

Sample input:

user0 = ["/start", "/green", "/blue", "/pink", "/register", "/orange", "/one/two"]
user1 = ["/start", "/pink", "/register", "/orange", "/red", "a"]
user2 = ["a", "/one", "/two"]
user3 = ["/pink", "/orange", "/yellow", "/plum", "/blue", "/tan", "/red", "/amber", "/HotRodPink", "/CornflowerBlue", "/LightGoldenRodYellow", "/BritishRacingGreen"]
user4 = ["/pink", "/orange", "/amber", "/BritishRacingGreen", "/plum", "/blue", "/tan", "/red", "/lavender", "/HotRodPink", "/CornflowerBlue", "/LightGoldenRodYellow"]
user5 = ["a"]
user6 = ["/pink","/orange","/six","/plum","/seven","/tan","/red", "/amber"]

Sample output:

findContiguousHistory(user0, user1) => ["/pink", "/register", "/orange"]
findContiguousHistory(user0, user2) => [] (empty)
findContiguousHistory(user0, user0) => ["/start", "/green", "/blue", "/pink", "/register", "/orange", "/one/two"]
findContiguousHistory(user2, user1) => ["a"] 
findContiguousHistory(user5, user2) => ["a"]
findContiguousHistory(user3, user4) => ["/plum", "/blue", "/tan", "/red"]
findContiguousHistory(user4, user3) => ["/plum", "/blue", "/tan", "/red"]
findContiguousHistory(user3, user6) => ["/tan", "/red", "/amber"]

n: length of the first user's browsing history
m: length of the second user's browsing history
*/

/*
!EXPLANATION USING DP TABLE
user0 = ["/start", "/green", "/blue", "/pink", "/register", "/orange", "/one/two"]
user1 = ["/start", "/pink", "/register", "/orange", "/red", "a"]

      {}    s       p    blue   pink  register orange /one/two
  {}
  s        1       0       0      0       0          0       0      
  p        0       1 + 1       
  r
  o                              
  r
  a 
dp[i-1][j-1]
*/

vector<string> getLCS(vector<string> &s1, vector<string> s2)
{
  int m = s1.size();
  int n = s2.size();
  int max = 0;
  pair<int, int> coord;
  vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

  for (int i = 1; i < m; i++)
  {
    for (int j = 1; j < n; j++)
    {
      if (s1[i - 1] == s2[j - 1])
        dp[i][j] = 1 + dp[i - 1][j - 1];

      if (dp[i][j] > max)
      {
        max = dp[i][j];
        coord = {i, j};
      }
    }
  }
  int idx = coord.first;
  vector<string> result(s1.begin() + (idx - 1 - max), s1.begin() + idx - 1);
  return result;
}

int main()
{

  vector<string> user0 = {"/start", "/green", "/blue", "/pink", "/register", "/orange", "/one/two"};
  vector<string> user1 = {"/start", "/pink", "/register", "/orange", "/red", "a"};
  vector<string> user2 = {"a", "/one", "/two"};
  vector<string> user3 = {"/pink", "/orange", "/yellow", "/plum", "/blue", "/tan", "/red", "/amber", "/HotRodPink", "/CornflowerBlue", "/LightGoldenRodYellow", "/BritishRacingGreen"};
  vector<string> user4 = {"/pink", "/orange", "/amber", "/BritishRacingGreen", "/plum", "/blue", "/tan", "/red", "/lavender", "/HotRodPink", "/CornflowerBlue", "/LightGoldenRodYellow"};
  vector<string> user5 = {"a"};
  vector<string> user6 = {"/pink", "/orange", "/six", "/plum", "/seven", "/tan", "/red", "/amber"};

  vector<string> result = getLCS(user0, user1);

  for (string &el : result)
    cout << el << " ";
  cout << endl;

  return 0;
}
