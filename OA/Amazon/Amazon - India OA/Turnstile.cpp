
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> solve(vector<int> &t, vector<int> &dir)
  {
    queue<pair<int, int>> exit, entry; // pair <time[index], index>
    int N = t.size();
    vector<int> res(N);

    for (int i = 0; i < N; i++)
    {
      if (dir[i] == 1)
        exit.push({t[i], i});
      else
        entry.push({t[i], i});
    }

    int ct = 0, lc = -1; // ct is the current time & lc indicates who used
                         // turnstile in the previous second lc = -1 if none
                         // used the turnstile in the last second

    while (!exit.empty() || !entry.empty())
    {
      // checking for exit queue
      if (!exit.empty() && exit.front().first <= ct &&
          (lc == 1 || lc == -1 || entry.empty() ||
           (entry.front().first > ct)))
      {
        res[exit.front().second] = ct;
        lc = 1;
        exit.pop();
      }
      // checking for entry queue
      else if (!entry.empty() && entry.front().first <= ct)
      {
        res[entry.front().second] = ct;
        lc = 0;
        entry.pop();
      }
      else
      {
        lc = -1;
      }

      ct++;
    }

    return res;
  }
};