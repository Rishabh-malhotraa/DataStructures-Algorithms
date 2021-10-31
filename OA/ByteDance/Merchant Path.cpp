#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'MerchantPath' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER rating
 *  2. STRING_ARRAY countries
 */

int m, n;

vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool isValid(int &i, int &j)
{
  return (i >= 0 && i < m && j >= 0 && j < n);
}

pair<int, int> getStartPosition(vector<vector<int>> &grid, int &rating)
{
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      if (grid[i][j] == rating)
        return {i, j};

  return {};
}

vector<vector<int>> buildGrid(vector<string> &countries)
{
  string token;
  vector<vector<int>> grid(m, vector<int>(n, 0));
  int idx = 0;
  for (string &country : countries)
  {
    for (int j = 0, j_ = 0; j_ < country.size(); j_++)
    {
      if (countries[idx][j_] != ' ')
      {
        grid[idx][j] = country[j_] - '0';
        j++;
      }
    }
    idx++;
  }
  return grid;
}

int MerchantPath(int rating, vector<string> countries)
{

  // cout << ":rating " << rating << endl;
  int count = 0;
  for (int i = 0; i < countries[0].size(); i++)
    if (countries[0][i] != ' ')
      count++;

  m = countries.size(), n = count;
  vector<vector<int>> grid = buildGrid(countries);

  auto [start_i, start_j] = getStartPosition(grid, rating);

  vector<vector<bool>> visited(m, vector<bool>(n, false));

  queue<tuple<int, int, int>> q;
  q.push({start_i, start_j, 0});

  while (q.empty() == false)
  {
    auto &[i, j, cost] = q.front();
    q.pop();

    visited[i][j] = true;

    if (grid[i][j] == rating && cost != 0)
      return cost;

    for (vector<int> &d : dir)
    {
      int ni = i + d[0];
      int nj = j + d[1];
      if (isValid(ni, nj) && visited[ni][nj] == false && grid[ni][nj] <= rating)
      {
        visited[ni][nj] = true;
        q.push({ni, nj, cost + 1});
      }
    }
  }

  return -1;
}

int main()