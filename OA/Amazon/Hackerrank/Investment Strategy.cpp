/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

/*
Your team at Amazon has been asked to help outline options for a hypothetical investment strategy.
Imagine an investor opens a new account and wants to invest in a number of assets. Each asset begins with a balance of 0, an its value is stored in an array using 1-based indexing.
Periodically, a contribution is received ci equal investments are made in a subset of the portfolio. Each contribution will be given by investment amount, start index, end index. Eact-investment in that range will receive the contribution amount. Determine the maximum amount invested in any one investment after all contributions.
For example, start with an array of 5 elements. investments = [0, 0, 0, 0, O]* The variables left and right represent the starting anc ending indices, inclusive. Another variable, contribution, is the new funds to invest per asset. The first investment is at index 1.


n = 5
[0,0,0,0,0]

rounds[0] = [1, 2, 100]  => [100, 100,   0 ,   0,   0]
rounds[1] = [2, 5, 100]  => [100, 200, 100 , 100, 100]
rounds[2] = [3, 4, 100]  => [100, 200, 200 , 200, 100]

max investment in one asset => 200
*/

// MEETING ROOMS II renamed :DDD

long maxValue(int n, vector<vector<int>> rounds)
{

  sort(rounds.begin(), rounds.end());
  priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

  long long currentCost = 0, len = rounds.size(), result = INT_MIN;

  for (int i = 0; i < len; i++)
  {
    vector<int> round = rounds[i];
    int start = round[0], end = round[1], cost = round[2];

    while (pq.empty() == false && start > pq.top()[0])
    {
      currentCost -= pq.top()[2];
      pq.pop();
    }
    currentCost += cost;
    pq.push({end, start, cost});
    result = max(result, currentCost);
  }
  return result;
}