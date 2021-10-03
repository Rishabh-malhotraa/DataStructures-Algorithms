#include <bits/stdc++.h>
using namespace std;

int getMinimumTransactions(int idx, vector<int> &debt)
{
  while (idx < debt.size() && debt[idx] == 0)
    idx++;

  if (idx == debt.size())
    return 0;

  int result = INT_MAX;
  for (int i = idx + 1; i < debt.size(); i++)
  {
    if (debt[idx] * debt[i] < 0)
    {
      debt[i] += debt[idx];
      result = min(result, (1 + getMinimumTransactions(idx + 1, debt)));
      debt[i] -= debt[idx];
    }
  }
  return result;
}

class Solution
{
public:
  int minTransfers(vector<vector<int>> &transactions)
  {
    unordered_map<int, int> balence;

    for (vector<int> &transaction : transactions)
    {
      int u = transaction[0], v = transaction[1], cost = transaction[2];
      balence[u] -= cost;
      balence[v] += cost;
    }

    vector<int> debt;

    for (auto &[id, cost] : balence)
      if (cost != 0)
        debt.push_back(cost);

    return getMinimumTransactions(0, debt);
  }
};