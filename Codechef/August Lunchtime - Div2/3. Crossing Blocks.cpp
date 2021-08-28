/*
 ____  _     _           _     _       __  __       _ _           _             
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _ 
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

int solve()
{
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  vector<int> visited(n, false);
  visited[0] = true;
  queue<vector<int>> q({{0, 0}});

  while (!q.empty())
  {
    vector<int> front = q.front();
    q.pop();
    int idx = front[0], moves = front[1];
    if (idx == n - 1)
      return front[1] + 1;

    int height = arr[idx];
    int max_height = INT_MIN;
    for (int i = idx + 1; i < n; i++)
    {
      if (visited[i] == true)
        continue;

      if (arr[i] <= height && arr[i] >= max_height && visited[i] == false)
      {
        q.push({i, moves + 1});
        visited[i] = true;
      }
      max_height = max(max_height, arr[i]);
    }
  }

  return -1;
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
    cout << solve() << endl;
  }
  return 0;
}

// ----------------------------------------------------

// Approach 1 -> USING BFS (TLE)

/*
 ____  _     _           _     _       __  __       _ _           _             
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _ 
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

// ----------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

int solve()
{
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  queue<vector<int>> q({{0, 0}});

  while (!q.empty())
  {
    vector<int> front = q.front();
    q.pop();
    int idx = front[0], moves = front[1];
    if (idx == n - 1)
      return front[1];

    int height = arr[idx];
    int max_height = INT_MIN;
    int max_idx = -1;
    for (int i = idx + 1; i < n; i++)
    {

      if (arr[i] <= height && arr[i] >= max_height)
        max_idx = i;

      max_height = max(max_height, arr[i]);
    }
    if (max_idx != -1)
      q.push({max_idx, moves + 1});
  }

  return -1;
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
    cout << solve() << endl;
  }
  return 0;
}