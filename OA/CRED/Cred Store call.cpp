#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'maxDistinctGoodies' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER nEmployees
 *  2. INTEGER_ARRAY goodyTypes
 */

int maxDistinctGoodies(int k, vector<int> arr)
{
  unordered_map<int, int> cache;
  int n = arr.size();
  for (int i = 0; i < n; i++)
  {
    int value = arr[i];
    cache[value]++;
  }
  int distinctEl = cache.size();
  int cost = 0;
  for (auto el : cache)
  {
    int freq = el.second;
    cost += freq - 1;
  }

  if (cost >= k)
    return distinctEl;

  return distinctEl - (k - cost);
}