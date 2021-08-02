#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007LL
#define ll long long
#define ULL unsigned long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define pnl cout << "\n"
#define deb(x) cout << #x << " " << x << endl;
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MEMSET(x) memset(x, 0, sizeof x)
#define ABS(x) ((x) < 0 ? -(x) : (x))
#define FO(i, n) for (int i = 0; i < (n); i++)
#define FOR(i, n) for (int i = (n); i >= 0; i--)
#define FOA(i, a, b) for (int i = (a); i < (b); i++)

/**
 * 1. Initialse a 2d vector for queens placement
 * 2. we only place one queen per column so check the rows if you can fit in
 * 3. if the queen is safe to be placed then recur to the placement of the next queen
 * 	  we have an bounding condition to return true is no.of queen >=N		
 * 4. If the recusion does not return true then backtack( that means make that cell as 0) and 
 * 	  look for other positions in the board to put that cell in	
 */
const int N = 10;
int board[N][N];

// The is safe function checks for left columsn and left up diagonals and
// left down diagonals, we do not need to think abour right diagonals because
// we havent placed anything on the right yet and that job is given to the next
// queen position to look at
bool isSafe(int board[N][N], int row, int col)
{
  for (int i = 0; i < col; i++)
  {
    if (board[row][i])
      return false;

    // upper diagonal & lower diaginal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
      if (board[i][j])
        return false;
    }
    for (int i = row, j = col; i < N && j >= 0; i++, j--)
    {
      if (board[i][j])
        return false;
    }
  }
  return true;
}

bool Nqueens(int board[N][N], int col)
{
  if (col >= N)
    return true;

  for (int i = 0; i < N; i++)
  {
    if (isSafe(board, i, col))
    {
      board[i][col] = 1;

      if (Nqueens(board, col + 1))
        return true;

      // backtrack-- you made a wrong choice now correct it and choice differently
      board[i][col] = 0;
    }
  }
  return false;
}

void solve()
{
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  return;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
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