//  ____  _     _           _     _       __  __       _ _           _
// |  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
// | |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
// |  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
// |_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

#include <bits/stdc++.h>
using namespace std;

// Level Order BFS | Graphs
// minimum distance on a grid but you have to generate neighbours based on certain rules

class Solution
{
public:
  vector<string> generateNeighbour(string s)
  {
    vector<string> result;

    for (int i = 0; i < 4; i++)
    {
      for (int j = -1; j <= 1; j += 2)
      {
        string curr = s;
        char ch = ((s[i] - '0') + j + 10) % 10 + '0';
        curr[i] = ch;
        result.push_back(curr);
      }
    }
    return result;
  }

  int openLock(vector<string> &deadends, string target)
  {
    // BFS LEVEL ORDER AND SHIZZ
    unordered_set<string> keys(deadends.begin(), deadends.end());
    queue<string> q({"0000"});
    if (keys.count("0000"))
      return -1;
    for (int steps = 0; !q.empty(); ++steps)
    {
      // now level order traversal here
      int n = q.size();
      for (int i = 0; i < n; i++)
      {
        string curr = q.front();
        q.pop();
        if (curr == target)
          return steps;
        for (string neighbour : generateNeighbour(curr))
        {
          if (keys.count(neighbour))
            continue;
          keys.insert(neighbour);
          q.push(neighbour);
        }
      }
    }
    return -1;
  }
};