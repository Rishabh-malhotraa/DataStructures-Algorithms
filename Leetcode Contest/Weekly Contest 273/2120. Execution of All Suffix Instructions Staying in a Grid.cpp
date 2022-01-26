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
  int m, n;
  bool isValid(int i, int j)
  {
    return (i >= 0 && i < m && j >= 0 && j < n);
  }
  unordered_map<int, vector<int>> dir = {
      {'R', {0, 1}},
      {'L', {0, -1}},
      {'U', {-1, 0}},
      {'D', {1, 0}}};

  int countOps(string &op, int idx, int i, int j)
  {
    if (idx == op.size())
      return 0;

    i = i + dir[op[idx]][0];
    j = j + dir[op[idx]][1];

    if (isValid(i, j) == false)
      return 0;
    else
      return 1 + countOps(op, idx + 1, i, j);
  }

public:
  vector<int> executeInstructions(int n, vector<int> &startPos, string s)
  {
    this->m = n, this->n = n;
    int len = s.size();
    string op = "";
    vector<int> result(len, 0);

    for (int i = len - 1; i >= 0; i--)
    {
      op = s[i] + op;
      // cout << op << endl;
      result[i] = countOps(op, 0, startPos[0], startPos[1]);
    }
    return result;
  }
};