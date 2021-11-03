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
  const int m = 800, n = 800;
  vector<vector<int>> dir = {
      {1, 2}, {2, 1}, {-1, 2}, {-2, 1}, {1, -2}, {2, -1}, {-1, -2}, {-2, -1}};
  bool isValid(int i, int j)
  {
    return (i >= 0 && i < m && j >= 0 && j < n);
  }

public:
  int minKnightMoves(int x, int y)
  {
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    pair<int, int> origin = {400, 400};

    x += origin.first, y += origin.second;

    queue<tuple<int, int, int>> q({{origin.first, origin.second, 0}});
    visited[origin.first][origin.second] = true;

    while (q.empty() == false)
    {
      auto [i, j, distance] = q.front();
      q.pop();
      if (i == x && j == y)
        return distance;

      for (vector<int> &d : dir)
      {
        int ni = i + d[0];
        int nj = j + d[1];

        if (visited[ni][nj] == false)
        {
          visited[ni][nj] = true;
          q.push({ni, nj, distance + 1});
        }
      }
    }
    return -1;
  }
};