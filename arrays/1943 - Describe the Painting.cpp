#include <bits/stdc++.h>
using namespace std;

// Very Simlar to 1942 which itself uses the concept of the syline problem

class Solution
{
public:
  vector<vector<long long>> splitPainting(vector<vector<int>> &segments)
  {
    vector<vector<long long>> result;

    int n = segments.size();
    vector<pair<int, int>> intervals;
    for (int i = 0; i < n; i++)
    {
      intervals.push_back({segments[i][0], (i + 1)});
      intervals.push_back({segments[i][1], -(i + 1)});
    }
    sort(intervals.begin(), intervals.end());

    // position to value;
    deque<pair<int, int>> list;
    int firstColor = segments[abs(intervals[0].second) - 1][2];
    list.push_back({intervals[0].first, firstColor});

    long long currSum = firstColor;
    for (int i = 1; i < intervals.size(); i++)
    {
      auto interval = intervals[i];
      int idx = abs(interval.second) - 1;

      if (interval.second > 0)
      {

        int start = list.front().first;
        int newStart = segments[idx][0];
        int paint = segments[idx][2];
        list.pop_front();
        list.push_back({newStart, paint});
        if (start != newStart && currSum != 0)
          result.push_back({start, newStart, currSum});
        currSum += paint;
      }
      else
      {

        int start = list.front().first;
        int newEnd = segments[idx][1];
        int paint = segments[idx][2];
        list.pop_front();
        if (start != newEnd && currSum != 0)
          result.push_back({start, newEnd, currSum});
        currSum -= paint;
        list.push_back({newEnd, paint});
        // end point
      }
    }
    return result;
  }
};
