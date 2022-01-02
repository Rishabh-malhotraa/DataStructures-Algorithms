/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

/**
 * Four conditions will be the invalid tic tac toe board:
 * 1. there are more 'O' than 'X'
 * 2. the board has 2 more 'X' than 'O'
 * 3. number of 'X' is equal to number of 'O', but 'X' wins, it is impossible because if 'X' wins, the game is over, 'O' cannot play again, then number of 'O' MUST less than 'X'
 * 4. number of 'X' is more than number of 'O', but 'O' wins, it is impossible because if 'O' wins, the game is over, 'X' cannot play again, then number of 'X' CANNOT greater than 'O'
 **/

class Solution
{
public:
  bool validTicTacToe(vector<string> &board)
  {
    int xCount = 0, oCount = 0;

    for (auto row : board)
      for (auto ch : row)
        if (ch != ' ')
          ch == 'X' ? xCount++ : oCount++;

    if (oCount > xCount or xCount - oCount > 1)
      return false;

    if (xCount >= 3)
      if (playerWins(board, 'X') and xCount - 1 != oCount)
        return false;

    if (oCount >= 3)
      if (playerWins(board, 'O') and oCount != xCount)
        return false;

    return true;
  }

  bool playerWins(vector<string> &board, char ch)
  {
    // check row wise
    for (int i = 0; i < 3; i++)
      if (board[i][0] == ch and board[i][1] == ch and board[i][2] == ch)
        return true;

    // check column wise
    for (int i = 0; i < 3; i++)
      if (board[0][i] == ch and board[1][i] == ch and board[2][i] == ch)
        return true;

    // check diagnal
    if (board[0][0] == ch and board[1][1] == ch and board[2][2] == ch)
      return true;

    // check anti-diagnal
    if (board[0][2] == ch and board[1][1] == ch and board[2][0] == ch)
      return true;

    return false;
  }
};