//  ____  _     _           _     _       __  __       _ _           _
// |  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
// | |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
// |  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
// |_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

#include <bits/stdc++.h>
using namespace std;

// Greedy | Priority Queue | STL
/**
- Have a list of k elements in a list with k top efficienciency
- now we would add an element which would effect the min efficiency since it would 
  have the minimum efficiecy, since we are iterating a sorted array
- min_eff*(sum)
- No to get the optimal answer we need to remove that employee which contributes the
  least speed, since we don't care about its efficiency as the efficiency would be set
  by the incoming employee.
*/

class Solution
{
public:
  int maxPerformance(int n, vector<int> &speed, vector<int> &efficiency, int k)
  {
    vector<pair<int, int>> eff;
    for (int i = 0; i < n; i++)
      eff.push_back({efficiency[i], speed[i]});
    sort(eff.rbegin(), eff.rend());
    priority_queue<int, vector<int>, greater<int>> pq;

    long long result = INT_MIN, sum = 0;
    for (pair<int, int> el : eff)
    {
      int s = el.second, e = el.first;
      sum += s;
      pq.push(s);
      if (pq.size() > k)
      {
        sum -= pq.top();
        pq.pop();
      }
      result = max(result, sum * e);
    }
    return result % (int)1e+7;
  }
};