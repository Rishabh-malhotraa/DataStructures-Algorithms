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
private:
  vector<vector<int>> dir = {{0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};
  int m, n;
  bool isValid(int i, int j)
  {
    return (i >= 0 && i < m && j >= 0 && j < n);
  }

  int checkPeriphery(vector<vector<char>> &board, int i, int j)
  {
    int count = 0;
    for (vector<int> &d : dir)
    {
      int ni = i + d[0];
      int nj = j + d[1];

      if (isValid(ni, nj) && board[ni][nj] == 'M')
        count++;
    }

    return count;
  }

public:
  vector<vector<char>> updateBoard(vector<vector<char>> &board, vector<int> &click)
  {
    m = board.size(), n = board[0].size();

    int x = click[0], y = click[1];
    queue<pair<int, int>> q({{x, y}});

    if (board[x][y] == 'M')
    {
      board[x][y] = 'X';
      return board;
    }

    if (checkPeriphery(board, x, y) != 0)
    {
      board[x][y] = (char)('0' + checkPeriphery(board, x, y));
      return board;
    }
    else
      board[x][y] = 'B';

    while (q.empty() == false)
    {
      auto [i, j] = q.front();
      q.pop();

      for (vector<int> d : dir)
      {
        int ni = i + d[0];
        int nj = j + d[1];

        if (isValid(ni, nj) && board[ni][nj] == 'E')
        {
          int neighbours = checkPeriphery(board, ni, nj);
          if (neighbours == 0)
          {
            board[ni][nj] = 'B';
            q.push({ni, nj});
          }
          else
          {
            board[ni][nj] = (char)('0' + neighbours);
          }
        }
      }
    }
    return board;
  }
};
