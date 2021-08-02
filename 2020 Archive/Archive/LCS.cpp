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
#define ABS(x) ((x) < 0 ? -(x) : (x))
#define FO(i, n) for (int i = 0; i < (n); i++)
#define FOR(i, n) for (int i = (n); i >= 0; i--)
#define FOA(i, a, b) for (int i = (a); i < (b); i++)

int LCS(string s1, string s2, int m, int n)
{
    if (m == 0 || n == 0)
        return 0;

    else if (s1[m] == s2[n])
        return 1 + LCS(s1, s2, m - 1, n - 1);

    return max(LCS(s1, s2, m - 1, n), LCS(s1, s2, m, n - 1));
}

int LCSDP(string s1, string s2, int m, int n)
{
    int dp[m + 1][n + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i < m + 1; i++)
    {
        FOA(j, 1, n + 1)
        {

            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[m][n];
}

void solve()
{
    string s1, s2;
    cin >> s1 >> s2;

    // using recurssion
    int val = LCS(s1, s2, s1.length(), s2.length());
    // using dp
    int valDP = LCSDP(s1, s2, s1.length(), s2.length());

    cout << "RECURSSION solution " << val << endl;
    cout << "DYNAMIC PROGRAMMING solution " << valDP << endl;
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