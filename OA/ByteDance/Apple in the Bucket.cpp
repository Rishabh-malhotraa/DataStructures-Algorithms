#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'applesInTheBucket' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY buckets
 *  2. INTEGER k
 */

vector<int> applesInTheBucket(vector<int> buckets, int k)
{
  vector<int> result;
  unordered_map<int, int> prefixSum;
  prefixSum.insert({0, -1});
  int n = buckets.size(), currSum = 0;

  pair<int, int> coord = {10, -10};

  for (int i = 0; i < n; i++)
  {
    currSum += buckets[i];
    int keySum = currSum - k;

    if (prefixSum.find(keySum) != prefixSum.end())
    {
      coord = {prefixSum[keySum] + 1, i};
      break;
      /*
      1 2 4  5  6  7
      1 3 7 12 18 25
     */
    }
    prefixSum.insert({currSum, i});
  }

  for (int j = coord.first; j <= coord.second; j++)
    result.push_back(buckets[j]);

  return result;
}