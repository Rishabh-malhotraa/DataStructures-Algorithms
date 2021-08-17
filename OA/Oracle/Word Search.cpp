//  ____  _     _           _     _       __  __       _ _           _
// |  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
// | |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
// |  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
// |_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
  vector<vector<int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
  int m, n;
  vector<pair<int, int>> coordinates;
  bool isValid(int i, int j)
  {
    return (i >= 0 && i < m && j >= 0 && j < n);
  }

  string getCoordinates()
  {
    string s;
    for (pair<int, int> cord : coordinates)
      s = s + to_string(cord.first) + to_string(cord.second);
  }

  string dfs(int i, int j, string &word, vector<vector<char>> &board, vector<vector<bool>> &visited, int str_idx)
  {
    visited[i][j] = true;
    if (str_idx == word.size())
      return getCoordinates();

    for (vector<int> &d : dir)
    {
      int ni = i + d[0];
      int nj = j + d[1];

      if (isValid(ni, nj) && visited[ni][nj] == false)
      {

        if (board[ni][nj] == word[str_idx])
        {
          coordinates.push_back({ni, nj});

          string result = dfs(ni, nj, word, board, visited, str_idx + 1);
          if (result != "no")
            return result;

          coordinates.pop_back();
        }
      }
    }
    visited[i][j] = false;

    return "no";
  }

public:
  string exist(vector<vector<char>> &board, string word)
  {
    m = board.size(), n = board[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (board[i][j] == word.front())
        {
          coordinates.push_back({i, j});
          string isPresent = dfs(i, j, word, board, visited, 1);
          if (isPresent != "no")
            return isPresent;
          coordinates.pop_back();
        }
      }
    }
    return "no";
  }
};