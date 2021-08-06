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
  int maxArea(int h, int w, vector<int> &horizontalCuts, vector<int> &verticalCuts)
  {
    set<int> s;
    int mod = (int)1e9 + 7;
    horizontalCuts.push_back(0);
    horizontalCuts.push_back(h);
    verticalCuts.push_back(0);
    verticalCuts.push_back(w);

    sort(horizontalCuts.begin(), horizontalCuts.end());
    sort(verticalCuts.begin(), verticalCuts.end());
    int hmax = 0, vmax = 0;
    for (int i = 1; i < horizontalCuts.size(); i++)
      hmax = max(hmax, horizontalCuts[i] - horizontalCuts[i - 1]);
    for (int i = 1; i < verticalCuts.size(); i++)
      vmax = max(vmax, verticalCuts[i] - verticalCuts[i - 1]);

    long long result = (long long)hmax * vmax;
    return result % mod;
  }
};