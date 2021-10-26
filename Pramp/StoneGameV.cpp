#include <bits/stdc++.h>
using namespace std;

/*
There are several stones arranged in a row, and each stone has an associated value which is an integer given in the array stoneValue.

In each round of the game, Alice divides the row into two non-empty rows (i.e. left row and right row),
then Bob calculates the value of each row which is the sum of the values of all the stones in this row.


Bob throws away the row which has the maximum value, and Alice's score increases by the value of the remaining row.

If the value of the two rows are equal, Bob lets Alice decide which row will be thrown away. The next round starts with the remaining row.

The game ends when there is only one stone remaining. Alice's is initially zero.

Return the maximum score that Alice can obtain.



Example 1:

Input: stoneValue = [6,2,3,4,5,5]
Output: 18
Explanation: In the first round, Alice divides the row to [6,2,3], [4,5,5]. The left row has the value 11 and the right row has value 14. Bob throws away the right row and Alice's score is now 11.
In the second round Alice divides the row to [6], [2,3]. This time Bob throws away the left row and Alice's score becomes 16 (11 + 5).
The last round Alice has only one choice to divide the row which is [2], [3]. Bob throws away the right row and Alice's score is now 18 (16 + 2). The game ends because only one stone is remaining in the row.
Example 2:

Input: stoneValue = [7,7,7,7,7,7,7]
Output: 28
Example 3:

Input: stoneValue = [4]
Output: 0


Alice Bob
           11
stone->   [6,2,3,4,5,5]
               |  14

               Bob will eliminate the row with more value

               score of ALice += sum of subarray left

termination condition is 1 stone left

|     |
7,7,7,7,7,7,7


Method 1 :
   |     |
[6,2,3,4,5,5]


Step 1:

i   j
6 2 3 4 5 5

cache[i][j]

prefixSUm

6            2 3 4 5 5

6 2          3 4 5 5

6 2 3        4 5 5  XXX   =>    11  || 14  ->   11 + recusion[6 , 2, 2]

6 2 3 4      5 5

6 2 3 4 5    5


N -> O(N^4)

N*()

Constraints:

1 <= stoneValue.length <= 500
1 <= stoneValue[i] <= 10^6
*/

/*

[6,2,3,4,5,5]

              0 1 2  3  4  5  6
prefixSUM  =  0 6 8 11 15 20 25


       0 1 2 3 4 5
arr = [6,2,3,4,5,5]

l = 0
r = 5
split = 2

spit => [1 - 4]

left  = p[2] - p[0] => 8  - > dfs(0,21 => 9
right = p[6] - p[1] => 17



 result = 6


O(n^2)  ->  [1] - [2,3,4,5]
                    -> [2]  [3,4,5]

O(N) -> N(N+1)/2 => O(N^2)
 */

class Solution
{
private:
  vector<int> prefixSum;
  vector<vector<int>> cache;

  void getPrefix(vector<int> &arr)
  {
    int n = arr.size();
    for (int i = 1; i <= n; i++)
      prefixSum[i] = arr[i - 1] + prefixSum[i - 1];
  }

  int dfs(int l, int r)
  {
    if (r - l <= 0)
      return cache[l][r] = 0;

    if (cache[l][r] != -1)
      return cache[l][r];

    int result = INT_MIN, score = 0;

    for (int split = l; split < r; split++)
    {
      int left = prefixSum[split + 1] - prefixSum[l];
      int right = prefixSum[r + 1] - prefixSum[split + 1];

      if (left < right)
        score = left + dfs(l, split);
      else if (left > right)
        score = right + dfs(split + 1, r);
      else
        score = max(left + dfs(l, split), right + dfs(split + 1, r));

      result = max(result, score);
    }

    return cache[l][r] = result;
  }

public:
  int stoneGameV(vector<int> &stoneValue)
  {
    int n = stoneValue.size();
    cache = vector<vector<int>>(n, vector<int>(n, -1));
    prefixSum.assign(n + 1, 0);
    getPrefix(stoneValue);

    return dfs(0, n - 1);
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

  cout << sol->stoneGameV(arr);
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