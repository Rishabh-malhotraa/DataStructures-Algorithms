#include <bits/stdc++.h>
using namespace std;

class Solution
{
  unordered_map<int, int> match;

public:
  bool canMatch(vector<vector<int>> &grid, int boy, vector<vector<bool>> &visited)
  {

    for (int girl = 0; girl < grid[0].size(); girl++)
    {

      if (grid[boy][girl] == 1 && visited[boy][girl] == false)
      {
        visited[boy][girl] = true;

        if (match.find(girl) != match.end() || canMatch(grid, match[girl], visited))
        {
          match[girl] = boy;
          return true;
        }
      }

      return false;
    }
  }

  int maximumInvitations(vector<vector<int>> &grid)
  {
    int m = grid.size(), n = grid[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, false));

    for (int boy = 0; boy < m; boy++)
    {
      canMatch(grid, boy, visited);
    }
    return match.size();
  }
};