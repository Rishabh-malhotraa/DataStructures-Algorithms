#include <bits/stdc++.h>
using namespace std;

// Priority Queue Similar to 218.Skyline Problem

// Leetcode Discuss Answer: https://leetcode.com/problems/the-number-of-the-smallest-unoccupied-chair/discuss/1359912/Priority-Queue-or-C%2B%2B-or-Concise-Code-or-Skyline-Problem

class Solution
{
public:
  int smallestChair(vector<vector<int>> &times, int targetFriend)
  {
    int idx = 0;
    vector<pair<int, int>> timeline;
    for (vector<int> &time : times)
    {
      timeline.push_back({time[0], (idx + 1)});
      timeline.push_back({time[1], -(idx + 1)});
      idx++;
    }

    sort(timeline.begin(), timeline.end());

    int prevLow = 0;
    unordered_map<int, int> cache;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (pair<int, int> time : timeline)
    {
      idx = abs(time.second) - 1; // getting the correct idx position
      if (time.second > 0)
      {
        int a = pq.empty() ? prevLow : pq.top(); // if pq iks empty then a = prevLow
        int b = prevLow;
        int seat = 0;
        if (a < b)
        {
          seat = a;
          pq.pop();
        }
        else
        {
          seat = b;
          prevLow++;
        }
        cache.insert({idx, seat});
        if (targetFriend == idx)
          return seat;
      }
      else
      {
        pq.push(cache[idx]);
      }
    }
    return -1;
  }
};
