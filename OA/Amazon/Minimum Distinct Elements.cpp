//  ____  _     _           _     _       __  __       _ _           _
// |  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
// | |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
// |  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
// |_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

#include <bits/stdc++.h>
using namespace std;

int distinctIds(int arr[], int n, int mi)
{
  unordered_map<int, int> m;
  vector<pair<int, int>> v;
  int count = 0;

  // Store the occurrence of ids
  for (int i = 0; i < n; i++)
    m[arr[i]]++;

  // Store into the vector second as first and vice-versa
  for (auto it = m.begin(); it != m.end(); it++)
    v.push_back(make_pair(it->second, it->first));

  // Sort the vector
  sort(v.begin(), v.end());

  int size = v.size();

  // Start removing elements from the beginning
  for (int i = 0; i < size; i++)
  {

    // Remove if current value is less than
    // or equal to mi
    if (v[i].first <= mi)
    {
      mi -= v[i].first;
      count++;
    }

    // Return the remaining size
    else
      return size - count;
  }
  return size - count;
}