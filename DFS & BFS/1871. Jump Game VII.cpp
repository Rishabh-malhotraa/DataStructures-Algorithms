//  ____  _     _           _     _       __  __       _ _           _
// |  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
// | |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
// |  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
// |_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

#include <bits/stdc++.h>
using namespace std;

// Breadth First Search | Deque

// its like a sliding window of k elements using a monotone queue
// monotone means constantly decreasing bruh
// Highest ---> low
int maxResult(vector<int> &nums, int k)
{
  int n = nums.size();
  list<pair<int, int>> monotoneQueue({{0, nums[0]}});
  int result = 0;

  for (int i = 1; i < n; i++)
  {
    int currSum = monotoneQueue.front().second + nums[i];
    while (!monotoneQueue.empty() && currSum > monotoneQueue.back().second)
      monotoneQueue.pop_back();

    monotoneQueue.push_back({i, currSum});
    if (i - k >= monotoneQueue.front().first)
      monotoneQueue.pop_front();
  }

  return monotoneQueue.back().second;
}