#include <iostream>
#include <vector>x`

using namespace std;

/*

0,0 -> (n-1)(n-1)

1. i >= j





. . . . ()
. . . X X
. . X X X
. X X X X
X X X X X
0
  -->  (X)   ways[i][j] = ways[i][j-1] + ways[i+1][j]
        ^
^
|
|
----->
“EEENNN”, “EENENN”, “ENEENN”, “ENENEN”, “EENNEN”

TC : O(N^2)
SC : O(N^2)
*/

int numOfPathsToDest(int n)
{

  vector<vector<int>> dp(n, vector<int>(n, 0));

  /*
  X . . . .
  X X . . .
  X X X . .
  X X X X .
  X X X X X

  1
  1 1
  1 2 2
  1 3 5 5
  1 4 9 13
 */

  dp[0][0] = 1;
  for (int i = 1; i < n; i++)
  {
    for (int j = 0; j <= i; j++)
    {
      int left = (j == 0) ? 0 : dp[i][j - 1];
      int up = (i == j) ? 0 : dp[i - 1][j];
      dp[i][j] = left + up;
    }
  }
  return dp[n - 1][n - 1];
}

int main()
{
  return 0;
}