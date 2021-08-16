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
  /**
     * return the steps
     * have a unordered map - vector
     * have a Queue and do level order travel-ish on it (while-for)
     * the next which counts the stepn, its importannt to pass by reference and the clear() it
     * Visited array to only add unvisted indices to the queue
     */
  int minJumps(vector<int> &arr)
  {
    int n = arr.size();
    unordered_map<int, vector<int>> umap;

    for (int i = 0; i < n; i++)
      umap[arr[i]].push_back(i);

    vector<bool> visited(n, false);
    // visited[0] = true;
    queue<int> q;
    q.push(0);
    int steps = 0;

    while (q.empty() == false)
    {
      for (int i = q.size() - 1; i >= 0; i--)
      {
        int pos = q.front();
        q.pop();

        if (pos == n - 1)
          return steps;
        // you have a fookin next_el array
        vector<int> &next_el = umap[arr[pos]];
        next_el.push_back(pos - 1);
        next_el.push_back(pos + 1);

        for (int j : next_el)
        {
          // here what we do is selectively add things to look in the queue
          if (j >= 0 && j < n && visited[j] == false)
          {
            q.push(j);
            visited[j] = true;
          }
        }
        next_el.clear();
      }
      steps++;
    }
    return 0;
    // level order traversal
  }
};