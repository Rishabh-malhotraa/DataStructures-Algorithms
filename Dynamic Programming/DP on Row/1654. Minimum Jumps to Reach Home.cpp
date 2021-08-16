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
  int minimumJumps(vector<int> &forbidden, int a, int b, int x)
  {
    /**
    * Queue and BFS Solution -- Enter a in the queue
    * Loop level order wise in the queue 
    * Don't add positions that are forbiddent 
    * take care of the case when there are two backwads in a row!!?
    */
    queue<pair<int, bool>> q;

    // true -> means don't go back else you can go back
    q.push({0, false});

    unordered_set<int> forb(forbidden.begin(), forbidden.end());
    int steps = 0;
    vector<vector<bool>> visited(2, vector<bool>(6000, false));
    while (q.empty() == false)
    {
      for (int size = q.size(); size > 0; size--)
      {
        int pos = q.front().first;
        bool flag = q.front().second;
        q.pop();
        if (pos == x)
          return steps;
        int forward = pos + a;
        int backward = pos - b;

        if (forward < 6000 && visited[0][forward] == 0 && !forb.count(forward))
        {
          q.push({forward, false});
          visited[0][forward] = 1;
        }
        if (backward >= 0 && visited[1][backward] == 0 && !forb.count(backward) && !flag)
        {
          q.push({backward, true});
          visited[1][backward] = 1;
        }
      }
      steps++;
    }
    return -1;
  }
};