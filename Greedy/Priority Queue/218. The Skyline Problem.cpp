/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

/**
 * 1. Bifurcate start and end values based on inverted heights
 * 2. If curr height and previous height changes then we have a POI
 * 3. The point to be inserted is x-coords || curr-> height
 * 4. Add o to the multiset for base cases
 * 5. get the current height for a *heightSet.rbegin();
 *
 */
class Solution
{
public:
  vector<vector<int>> getSkyline(vector<vector<int>> &buildings)
  {
    vector<pair<int, int>> heights;
    vector<vector<int>> skyline;
    for (const vector<int> building : buildings)
    {
      heights.push_back(make_pair(building[0], -building[2]));
      heights.push_back(make_pair(building[1], building[2]));
    }
    // height done!

    sort(heights.begin(), heights.end());
    multiset<int> mset;
    int prev = 0;
    for (const auto &h : heights)
    {
      // height < 0 == starting position || > 0 is ending position
      int height = -h.second, position = h.first;
      if (height > 0)
        mset.insert(height);
      else
        mset.erase(mset.find(-height));

      int currHeight = (mset.empty()) ? 0 : *mset.rbegin();
      int prevHeight = (skyline.empty()) ? 0 : skyline.back()[1];

      if (prevHeight != currHeight)
        skyline.push_back({h.first, currHeight});
    }
    return skyline;
  }
};