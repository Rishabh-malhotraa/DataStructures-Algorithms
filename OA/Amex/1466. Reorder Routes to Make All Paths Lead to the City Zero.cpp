//  ____  _     _           _     _       __  __       _ _           _
// |  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
// | |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
// |  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
// |_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> &A, vector<int> &B)
{
  int a = *max_element(A.begin(), A.end());
  int b = *max_element(B.begin(), B.end());
  int n = max(a, b) + 1;
  // cout << n << endl;
  vector<vector<int>> forward(n), back(n);
  vector<bool> visited(n, false);
  queue<int> q;
  q.push(0);
  int result = 0;
  for (int i = 0; i < A.size(); i++)
  {
    int u = A[i], v = B[i];
    forward[u].push_back(v);
    back[v].push_back(u);
  }
  while (!q.empty())
  {
    int curr = q.front();
    q.pop();
    visited[curr] = true;

    for (int a : forward[curr])
    {
      if (!visited[a])
      {
        q.push(a);
        result++;
      }
    }
    // push other nodes so we visit everything
    for (auto b : back[curr])
    {
      if (!visited[b])
        q.push(b);
    }
  }
  // cout << result << endl;
  return result;
}
