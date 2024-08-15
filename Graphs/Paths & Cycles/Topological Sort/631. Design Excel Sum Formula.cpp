/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

struct Cell
{
  int value;
  string formula;
  vector<string> formulas;
};

class Excel
{
private:
  vector<vector<Cell>> grid;

  unordered_map<string, list<string>> graph;

  const pair<int, int> toIndex(int x, char ch)
  {
    return make_pair(x - 1, ch - 'A');
  }

  const pair<int, int> toIndex(string s)
  {
    int i = s[1] - '0';
    int j = s[0] - 'A';

    return make_pair(i, j);
  }

  vector<string> getFormula(string number)
  {
    stringstream ss(number);
    string token;
    vector<string> tokens;
    while (getline(ss, token, ':'))
      tokens.push_back(token);
    return tokens;
  }

public:
  Excel(int height, char width)
  {
    auto &[i, j] = toIndex(height, width);
    grid.resize(i, vector<Cell>(j));
  }

  void set(int row, char column, int val)
  {
    auto &[i, j] = toIndex(row, column);

    grid[i][j].value = val;
  }

  int get(int row, char column)
  {
    auto &[i, j] = toIndex(row, column);

    // precalculate Formulat
    grid[i][j].value;
  }

  int sum(int row, char column, vector<string> numbers)
  {

    string cellCode = to_string(column) + to_string(row);
    for (string number : numbers)
    {
      vector<string> s = getFormula(number);

      if (s.size() == 1)
      {
        graph[s[0]].push_back(cellCode);
      }
      else
      {
        int n = toIndex(s[1]).first - toIndex(s[0]).first;
        int m = toIndex(s[1]).second - toIndex(s[0]).second;

        for (int i = 0; i < n; i++)
        {
          for (int j = 0; j < m; j++)
          {
            string cellFormula = grid[i][j].formula;
            if (!cellFormula.empty())
            {
              graph[cellFormula].push_back(cellCode);
            }
          }
        }

        // return topologically sorted the graph!
        // evaluate in topoloical order!
        // evaluate sum
      }
    }
  }
};