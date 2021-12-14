/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

class TicTacToe
{
private:
  vector<int> rows, cols;
  int d1, d2, N;

public:
  TicTacToe(int n)
  {
    N = n;
    rows.assign(n, 0);
    cols.assign(n, 0);
    d1 = 0, d2 = 0;
  }

  // . .   . X   . X
  // . .   . .   O O

  int move(int row, int col, int player)
  {
    int point = (player == 1) ? 1 : -1;

    rows[row] += point;
    cols[col] += point;

    if (row == col)
      d1 += point;

    if (row + col == N - 1)
      d2 += point;

    if (abs(rows[row]) == N)
      return rows[row] < 0 ? 2 : 1;

    if (abs(cols[col]) == N)
      return cols[col] < 0 ? 2 : 1;

    if (abs(d1) == N)
      return d1 < 0 ? 2 : 1;

    if (abs(d2) == N)
      return d2 < 0 ? 2 : 1;

    return 0;
  }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */