//  ____  _     _           _     _       __  __       _ _           _
// |  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
// | |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
// |  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
// |_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

#include <bits/stdc++.h>
using namespace std;

void solve()
{
  string s, oper;
  cin >> s;
  cin >> oper;

  // string s = "TTFT";
  // string oper = "|&^";

  int n = s.length();

  vector<vector<int>> T(n, vector<int>(n, 0));
  vector<vector<int>> F(n, vector<int>(n, 0));
  // 	dp array kai bad, tabulation????? Dunnoo X-X
  for (int gap = 0; gap < n; gap++)
  {
    for (int i = 0, j = gap; j < n; i++, j++)
    {
      if (gap == 0)
      {
        T[i][j] = (s[i] == 'T') ? 1 : 0;
        F[i][j] = (s[i] == 'F') ? 1 : 0;
      }
      else
      {
        for (int k = i; k < j; k++)
        {
          int tik = T[i][k] + F[i][k];
          int tkj = T[k + 1][j] + F[k + 1][j];
          int total = tik * tkj;

          if (oper[k] == '&')
          {
            T[i][j] += T[i][k] * T[k + 1][j];
            F[i][j] += total - T[i][k] * T[k + 1][j];
          }
          else if (oper[k] == '|')
          {
            F[i][j] += F[i][k] * F[k + 1][j];
            T[i][j] += total - F[i][k] * F[k + 1][j];
          }
          else if (oper[k] == '^')
          {
            T[i][j] += T[i][k] * F[k + 1][j] + F[i][k] * T[k + 1][j];
            F[i][j] += T[i][k] * T[k + 1][j] + F[i][k] * F[k + 1][j];
          }
        }
      }
    }
  }
  cout << T[0][n - 1] << endl;
  return;
}