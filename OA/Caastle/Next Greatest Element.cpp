//  ____  _     _           _     _       __  __       _ _           _
// |  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
// | |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
// |  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
// |_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElements(vector<int> &arr)
{
  int n = arr.size();
  vector<int> result(n, -1);

  stack<int> monotone;
  for (int i = 0; i < 2 * n - 1; i++)
  {
    int idx = i % n;
    int curr = arr[idx];
    while (!monotone.empty() && curr > arr[monotone.top()])
    {
      result[monotone.top()] = curr;
      monotone.pop();
    }
    monotone.push(idx);
  }

  return result;
}