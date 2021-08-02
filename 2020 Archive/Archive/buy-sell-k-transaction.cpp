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

int maxProfit(int k, vector<int> &prices)
{
    int n = prices.size();
    if (n == 0)
        return 0;

    int dp[k + 1][n];
    memset(dp, 0, sizeof dp);

    for (int i = 1; i < k + 1; i++)
    {
        int max_el = INT_MIN;
        for (int j = 1; j < n; j++)
        {
            max_el = max(max_el, dp[i - 1][j - 1] + prices[j] - prices[j - 1]);

            dp[i][j] = max(dp[i][j - 1], max_el);
        }
    }

    return dp[k][n - 1];
}
// cout << "-------------------------" << endl;
// for (int j = 0; j < n; j++)
// 	cout << prices[j] << " ";
// pnl;
// for (int i = 0; i <= k; i++)
// {
// 	for (int j = 0; j < n; j++)
// 		cout << dp[i][j] << " ";
// 	cout << endl;
// }
// cout << "-------------------------" << endl;

void solve()
{
    int n, k;

    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << maxProfit(k, arr) << endl;

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
