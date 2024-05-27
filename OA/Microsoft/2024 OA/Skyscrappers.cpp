/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

// No two skyscrappers can have same height, so if they have same height you need to reduce the height of any one of them
// by the minimum possible value


vector<int> solution(vector<int> &A)
{
  int n = A.size();
  vector<pair<int, int>> arr;
  for (int i = 0; i < n; i++)
  {
    arr.push_back({A[i], i});
  }

  sort(arr.begin(), arr.end());

  set<int> heights({0});
  stack<pair<int, int>> range;

  int maxValue = 1;

  for (int i = 0; i < n; i++)
  {
    int el = arr[i].first;
    if (heights.find(el) != heights.end())
    {
      int p1 = range.top().first;
      int p2 = range.top().second;
      arr[i].first = p2;
      range.pop();
      if (p1 != p2)
      {
        range.push({p1, p2 - 1});
      }
    }
    else
    {
      if (heights.find(el - 1) == heights.end())
      {
        range.push({maxValue, el - 1});
      }
      maxValue = el + 1;
    }
    heights.insert(el);
  }

  vector<int> result(n);

  for (auto &[value, index] : arr)
  {
    result[index] = value;
  }
  return result;
}

/*

height of the skscrapers

O(N^2)

3 4 8 7 9

9 4 3 7 7

3 4 7 7 9

1 - 2
5 - 6
8  - 8

minimum value > that is not in set!


                             <>
1000  1001  1002 ...  1010  1010
*/