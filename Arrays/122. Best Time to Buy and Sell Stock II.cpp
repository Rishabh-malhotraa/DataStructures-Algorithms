#include <bits/stdc++.h>
using namespace std;

// Solution 1 only add the increasing slopes

class Solution
{
public:
  int maxProfit(vector<int> &prices)
  {
    int sum = 0;
    for (int i = 1; i < prices.size(); i++)
      if (prices[i] > prices[i - 1])
        sum += prices[i] - prices[i - 1];
    return sum;
  }
};

class Solution
{
public:
  int maxProfit(vector<int> &prices)
  {
    int result = 0, minima = 0, maxima = 0;
    int n = prices.size(), i = 0;
    while (i < n)
    {
      while (i < n - 1 && prices[i] > prices[i + 1])
        i++;

      minima = prices[i];

      while (i < n - 1 && prices[i] < prices[i + 1])
        i++;

      maxima = prices[i];

      result += maxima - minima;
    }
    return result;
  }
};

void solve()
{
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  Solution *sol = new Solution();

  cout << sol->maxProfit(arr);
}

int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int t;
  cin >> t;
  while (t--)
  {
    solve();
  }
  return 0;
}