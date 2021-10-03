#include <bits/stdc++.h>
using namespace std;

/*
 * Complete the 'countMoves' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts INTEGER_ARRAY numbers as parameter.
 */

long countMoves(vector<int> nums)
{
  long long minimum = *min_element(nums.begin(), nums.end());
  long long sum = accumulate(nums.begin(), nums.end(), 0LL);
  int n = nums.size();

  return (sum - n * minimum);
}
