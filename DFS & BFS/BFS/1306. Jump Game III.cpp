//  ____  _     _           _     _       __  __       _ _           _
// |  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
// | |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
// |  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
// |_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool canReachDFS(vector<int> &arr, int start)
  {
    if (start < 0 || start >= arr.size() || arr[start] < 0)
      return false;
    arr[start] *= -1; // flipping same as for visited = true

    return arr[start] == 0 || canReachDFS(arr, start - arr[start]) || canReachDFS(arr, start + arr[start]);
  }
  bool canReachBFS(vector<int> &arr, int start)
  {
    queue<int> q;
    q.push(start);
    int n = arr.size();
    bool flag = false;
    vector<bool> visited(n, false);
    while (!q.empty())
    {
      int front = q.front();
      q.pop();
      visited[front] = true;
      if (arr[front] == 0)
      {
        flag = true;
        break;
      }
      int start = front - arr[front];
      int end = front + arr[front];
      if (start >= 0 && visited[start] == false)
        q.push(start);
      if (end < n && visited[end] == false)
        q.push(end);
    }
    return flag;
  }
};