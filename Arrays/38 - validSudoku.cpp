#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool isValidSudoku(vector<vector<char>> &board)
  {
    int n = board.size();
    vector<set<int>> rows(n), cols(n), boxs(n);
    int box_len = sqrt(n);
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        char ch = board[i][j];
        if (ch == '.')
          continue;

        // calculate the boxs len here

        int box_i = i / box_len;
        int box_j = j / box_len;
        int k = box_i * box_len + box_j;

        if (!rows[i].count(ch) && !cols[j].count(ch) && !boxs[k].count(ch))
        {
          rows[i].insert(ch);
          cols[j].insert(ch);
          boxs[k].insert(ch);
        }
        else
          return false;
      }
    }
    return true;
  }
};