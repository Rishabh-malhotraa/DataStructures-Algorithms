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

void solve()
{
    int n, W;
    cin >> n >> W;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int dp[W + 1];

    // the significance if converted igf the weight to value is raken awaya mayber?
    memset(dp, 0, sizeof dp);
    for (int i = 1; i <= W; i++)
    {
        // int value = INT_MIN;
        for (int j = 0; j < i; j++)
            dp[i] = max(dp[i], arr[j] + dp[i - j - 1]);
        // dp[i] = value;
    }
    cout << dp[n] << endl;
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