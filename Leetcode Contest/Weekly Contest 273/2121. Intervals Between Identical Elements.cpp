/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<long long> getDistances(vector<int> &arr)
  {
    unordered_map<int, vector<long>> positionsMap;
    vector<long long> result(arr.size(), 0);
    for (int i = 0; i < arr.size(); i++)
      positionsMap[arr[i]].push_back(i);

    for (auto [val, positions] : positionsMap)
    {
      int n = positions.size();
      vector<long> prefix(n, 0), suffix(n, 0);

      // cout << val << "--------";
      // for (int i = 0; i < n; i++)
      //   cout << positions[i] << " ";
      // cout << endl;

      for (int i = 1; i < n; i++)
        prefix[i] = prefix[i - 1] + i * (positions[i] - positions[i - 1]);

      for (int i = n - 2; i >= 0; i--)
        suffix[i] = suffix[i + 1] + (n - 1 - i) * (positions[i + 1] - positions[i]);

      //       for (int i = 0; i < n; i++)
      //         cout << prefix[i] << "   ";

      //       cout << endl;
      //       for (int i = 0; i < n; i++)
      //         cout << suffix[i] << "   ";
      //       cout << endl;

      for (int i = 0; i < n; i++)
        result[positions[i]] = suffix[i] + prefix[i];
    }

    return result;
  }
};