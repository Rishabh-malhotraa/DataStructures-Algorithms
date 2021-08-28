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
    int slidingPuzzle(vector<vector<int>> &board)
    {
      string destination = "123450", initial;

      for (vector<int> row : board)
        for (int cell : row)
          initial += to_string(cell);

      //    0 1 2
      //    3 4 5
      vector<vector<int>> dir = {{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}};
      int level = 0;
      queue<string> q;
      q.push(initial);
      set<string> visited;

      while (q.empty() == false)
      {
        int len = q.size();
        for (int i = 0; i < len; i++)
        {
          string curr = q.front();
          int idx = curr.find('0');
          q.pop();
          if (curr == destination)
            return level;

          for (int pos : dir[idx])
          {
            string new_state = curr;
            swap(new_state[pos], new_state[idx]);

            if (visited.count(new_state) == 0)
            {
              visited.insert(new_state);
              q.push(new_state);
            }
          }
        }
        level++;
      }
      return -1;
    }
  };

void solve()
{

  int n = 3, m = 2;
  vector<vector<int>> arr(n, vector<int>(m, 0));

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> arr[i][j];

  Solution *sol = new Solution();

  cout << sol->slidingPuzzle(arr) << endl;
}

int main()
{
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