/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

// METHOD 1: SORTING
class Solution
{
public:
  vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
  {
    sort(points.begin(), points.end(), [](vector<int> &a, vector<int> &b)
         { return a[0] * a[0] + a[1] * a[1] < b[0] * b[0] + b[1] * b[1]; });

    return vector<vector<int>>(points.begin(), points.begin() + k);
  }
};

// METHOD 2 : HEAP

class Solution
{
public:
  vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
  {
    auto comparator = [](vector<int> &a, vector<int> &b)
    {
      return a[0] * a[0] + a[1] * a[1] < b[0] * b[0] + b[1] * b[1];
    };

    priority_queue<vector<int>, vector<vector<int>>, decltype(comparator)> pq(comparator);

    for (vector<int> &point : points)
    {
      pq.push(point);
      if (pq.size() > k)
        pq.pop();
    }

    vector<vector<int>> result;
    while (pq.empty() == false)
    {
      result.push_back(pq.top());
      pq.pop();
    }
    return result;
  }
};

// Method 3: K select

class Solution
{
private:
  bool distance(vector<int> &a, vector<int> &b)
  {
    return a[0] * a[0] + a[1] * a[1] <= b[0] * b[0] + b[1] * b[1];
  }
  int partition(int l, int r, vector<vector<int>> &points)
  {
    int idx = 0;
    for (int i = 0; i <= r; i++)
    {
      if (distance(points[i], points[r]))
        swap(points[i], points[idx++]);
    }
    return idx - 1;
  }

public:
  vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
  {
    int l = 0, r = points.size() - 1;
    k--;

    while (l < r)
    {
      int pivot = partition(l, r, points);

      if (pivot == k)
        break;

      else if (pivot < k)
        l = pivot + 1;
      else
        r = pivot - 1;
    }
    return vector<vector<int>>(points.begin(), points.begin() + k + 1);
  }
};