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

https://github.com/Rishabh-malhotraa/caucus

matrix of size mxn and you need to check if its toeplitz of not



Method

- Find a way to diagonally traverse the matrix
- check if all the elements in that diagonal traversal are same or not
    - the moment we have a different element than our current in our diagonal traversal we return false


1
2 1
 2 1
  2 1

n * m

(3*4)
[
1 1 1 1
1 1 1 1
1 1 1 1
]

(n + m -1)

 i+1 j+1


  4,2

  1 1
  1 1
  1 1
  1 1

  min(n,m)*2

*/

int m, n;

/*
list<tuple<int,int, int>>

<0,3,1>
<1,0,2>


0 0 0 1
2 0 0 0

n = 1e6
m = 1e6
size(list) = 1e6


*/

bool isValid(int i, int j)
{
  return (i >= 0 && i < m && j >= 0 && j < n);
}

// 1 + 2 + 3 + 4 ... n => (n+1)/2

// Sparse matrix -> almsot all values 0

//  O(n*m)
// Time Complexity O((n+m-1)*avergae diagonal length )
// Space complexity would be O(1)

bool checkDiagonal(int row, int col, const vector<vector<int>> &arr)
{
  int initialValue = arr[row][col];
  for (int i = row, j = col; isValid(i, j); i++, j++)
    if (arr[i][j] != initialValue)
      return false;

  return true;
}

bool isToeplitz(const vector<vector<int>> &arr)
{
  m = arr.size(), n = arr[0].size();

  bool result = true;
  // row- wise traversal
  for (int i = 0; i < m; i++)
    if (!checkDiagonal(i, 0, arr))
      return false;

  // column wise traversal
  for (int j = 0; j < n; j++)
    if (!checkDiagonal(0, j, arr))
      return false;

  return true;
}

int main()
{
  return 0;
}

bool Toeplitz(list<tuple<int, int, int>> grid, int m, int n)
{
  unordered_map<int, pair<int, int>> intercept;

  for (auto &[y, x, val] : grid)
  {
    int c = y - x;
    if (intercept.find(c) == intercept.end())
      intercept.insert({c, {val, 1}});
    else if (intercept[c].first != c)
      return false;
    else
      intercept[c].second++;
  }

  for (auto &[c, el] : intercept)
  {
    int num = m - abs(c);
    auto &[val, freq] = el;

    if (num != freq)
      return false;
  }

  return true;
}