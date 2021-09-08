/*
 ____  _     _           _     _       __  __       _ _           _             
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _ 
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> getMaze(string s, int n)
{
  vector<vector<char>> maze(n, vector<char>(n, 'X'));
  vector<bool> isValid(n, false);

  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      if (s[i] == '1' && s[j] == '1')
        maze[i][j] = maze[j][i] = '=';
      else if (s[i] == '2' && s[j] == '2')
      {
        if (isValid[i] == false)
        {
          isValid[i] = true;
          maze[i][j] = '+', maze[j][i] = '-';
        }
        else
        {
          maze[i][j] = '-', maze[j][i] = '+';
          isValid[j] = true;
        }
      }
      else
      {
        maze[i][j] = maze[j][i] = '=';
      }
    }
    if (isValid[i] == false)
    {
      if (s[i] == '1')
      {
        isValid[i] = true;
        for (char ch : maze[i])
          if (ch == '-')
            return {};
      }
      else
        return {};
    }
  }

  return maze;
}

void solve()
{
  int n;
  string s;
  cin >> n;
  cin >> s;

  auto maze = getMaze(s, n);

  if (maze.size() == 0)
    cout << "NO" << endl;
  else
  {
    cout << "YES" << endl;

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
        cout << maze[i][j];
      cout << endl;
    }
  }

  return;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int t;
  cin >> t;
  while (t--)
  {
    solve();
  }
  return 0;
}