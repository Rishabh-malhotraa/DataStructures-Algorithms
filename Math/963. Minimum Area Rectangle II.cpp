#include <bits/stdc++.h>
using namespace std;

/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

class Diagonal
{
public:
  int x1;
  int y1;
  int x2;
  int y2;
};

class Solution
{
private:
  long long getDistance(int x1, int y1, int x2, int y2)
  {
    return pow((x2 - x1), 2) + pow((y2 - y1), 2);
  }

  bool checkParallel(Diagonal p1, Diagonal p2)
  {
    long long m1 = abs((p2.y1 - p2.y2) * (p1.x2 - p1.x2));
    long long m2 = abs((p1.y1 - p1.y2) * (p2.x2 - p2.x2));

    return (m2 % m1 == 0 || m2 % m1 == 0);
  }
  long long getArea(Diagonal p1, Diagonal p2)
  {
    long long l = getDistance(p1.x1, p1.y1, p2.x1, p2.y1);
    long long b = getDistance(p1.x1, p1.y1, p2.x2, p2.y2);
    return l * b;
  }

public:
  double minAreaFreeRect(vector<vector<int>> &points)
  {
    int n = points.size();
    unordered_map<string, vector<Diagonal>> cache;
    long long result = 0, area;
    for (int i = 0; i < n; i++)
    {
      int x1 = points[i][0], y1 = points[i][1];
      for (int j = i + 1; j < n; j++)
      {
        int x2 = points[j][0], y2 = points[j][1];
        long long distance = getDistance(x1, y1, x2, y2);

        string key = to_string(x2 / 2.0) + " " + to_string(y2 / 2.0) + " " + to_string(distance);
        cache[key].push_back({x1, y1, x2, y2});
      }
    }

    for (auto &[key, points] : cache)
    {
      for (int i = 0; i < points.size(); i++)
      {
        for (int j = i + 1; j < points.size(); j++)
        {
          if (checkParallel(points[i], points[j]) == false)
          {
            area = max(area, getArea(points[i], points[j]));
          }
        }
      }
    }
    return sqrt(area);
  }
};

void solve()
{
  int m, n;
  cin >> m >> n;
  vector<vector<int>> arr(m, vector<int>(m, 0));

  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      cin >> arr[i][j];

  Solution *sol = new Solution();

  cout << sol->minAreaFreeRect(arr);
}

int main()
{
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