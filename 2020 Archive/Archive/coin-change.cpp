#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007LL
#define ll long long
#define ULL unsigned long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define pnl cout << endl
#define deb(x) cout << #x << " " << x << endl;
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MEMSET(x) memset(x, 0, sizeof x)
#define ABS(x) ((x) < 0 ? -(x) : (x))
#define FO(i, n) for (int i = 0; i < (n); i++)
#define FOR(i, n) for (int i = (n); i >= 0; i--)
#define FOA(i, a, b) for (int i = (a); i < (b); i++)

// fewest number of coins to make upto the amount
int coinChange(vector<int> &coins, int amount)
{
    // lets start with 0 then make our way upto the amount

    int dp[amount + 1];

    // each coin has certain value !!!
    // memset(dp, 0, sizeof dp);
    fill(dp, dp + amount + 1, (INT_MAX - 1));

    dp[0] = 0;
    int n = coins.size();
    /** amount 6 coints - 1-2-3
	 *  0 - (0)
	 *  1 - (1)  
	 *  2 - (1)
	 *  3 - (1)
	 *  4 - (2)
	 *  5 - (2)
	 *  6 - (2) 
	 *  ideas is denominate the amount and look at the dp
	 */
    const int check = INT_MAX;
    for (int i = 1; i < amount + 1; i++)
    {
        // loop through all the coins val to check if this can be optimised
        for (int j = 0; j < n; j++)
        {
            if (i - coins[j] >= 0)
            {
                dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
            }
        }
    }

    return ((dp[amount] == INT_MAX - 1) ? -1 : dp[amount]);
}

void solve()
{
    int n, amount;
    cin >> n >> amount;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << coinChange(arr, amount) << endl;
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