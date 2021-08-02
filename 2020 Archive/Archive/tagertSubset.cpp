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

bool subset(vector<int> &arr, int n, int sum)
{
    if (sum == 0)
        return true;
    else if (n < 0 && sum != 0)
        return false;

    if (sum - arr[n] < 0)
        return subset(arr, n - 1, sum);

    else
        return subset(arr, n - 1, sum) || subset(arr, n - 1, sum - arr[n]);
}

bool isPossible(vector<int> &arr, int n)
{
    int sum = accumulate(arr.begin(), arr.end(), 0);

    if (sum % 2 == 1)
        return false;
    else
    {
        int target = sum / 2;

        int dp[n + 1][target + 1];

        for (int i = 0; i < n + 1; i++)
        {
            for (int j = 0; j < target + 1; j++)
            {
                if (i == 0 && j != 0)
                    dp[i][j] = false;
                else if (j == 0)
                    dp[i][j] = true;
                else
                {
                    dp[i][j] = dp[i - 1][j];
                    if (j - arr[i - 1] >= 0)
                        dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
                }
            }
        }
        return dp[n][target];
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

    bool flag = isPossible(arr, n - 1);
    cout << (flag ? "YES" : "NO") << endl;
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