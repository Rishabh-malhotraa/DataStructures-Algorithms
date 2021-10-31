#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

int m, n;
bool isValid(int i, int j)
{
  return (i >= 0 && i < n && j >= 0 && j < m);
}

int dfs(vector<vector<int>> &board, int i, int j, vector<vector<int>> &visited, int length)
{

  if (i < 0 || i >= n || j < 0 || j >= m || length == 0 || visited[i][j] == 1)
    return 0;

  int number = board[i][j] * pow(10, length - 1);
  visited[i][j] = 1;
  int result = number;

  for (vector<int> &d : dir)
  {
    int ni = i + d[0];
    int nj = j + d[1];
    result = max(result, number + dfs(board, ni, nj, visited, length - 1));
  }

  visited[i][j] = 0;
  return result;
}

int getDigit(int a, int b, int c, int d)
{
  return (a * 1000 + b * 100 + c * 10 + d);
}

int oneRow(vector<vector<int>> board)
{
  int number = 0;
  for (int i = 0; i + 3 < m; i++)
    number = max(number, getDigit(board[0][i], board[0][i + 1], board[0][i + 2], board[0][i + 3]));

  for (int i = m - 1; i >= 3; i--)
    number = max(number, getDigit(board[0][i], board[0][i - 1], board[0][i - 2], board[0][i - 3]));
  return number;
}

int oneCol(vector<vector<int>> board)
{
  int number = 0;
  for (int i = 0; i + 3 < n; i++)
    number = max(number, getDigit(board[i][0], board[i + 1][0], board[i + 2][0], board[i + 3][0]));
  for (int i = n - 1; i >= 3; i--)
    number = max(number, getDigit(board[i][0], board[i - 1][0], board[i - 2][0], board[i - 3][0]));
  return number;
}

int solution(vector<vector<int>> &board)
{
  n = board.size();
  m = board[0].size();

  if (n == 1)
  {
    return oneRow(board);
  }
  if (m == 1)
  {
    return oneCol(board);
  }

  int maxVal = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      maxVal = max(maxVal, board[i][j]);

  int number = 0;
  int length = 4;
  vector<vector<int>> visited(n, vector<int>(m, 0));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
    {
      if (board[i][j] == maxVal)
      {
        int value = dfs(board, i, j, visited, length);
        number = max(number, value);
      }
    }
  return number;
}

int main()
{
  int n, m;
  cin >> n >> m;
  vector<vector<int>> board(n, vector<int>(m, 0));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> board[i][j];

  cout << solution(board);
  return 0;
}