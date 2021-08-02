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

struct Element
{
    int value;
    bool visited;
};

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    Element dp[n];
    for (int i = 0; i < n; i++)
    {
        dp[i].value = 2;
        dp[i].visited = false;
    }
    dp[0].value = 0;
    int count = 1;
    for (int i = 0; i < n; i++)
    {
        int el = arr[i];
        if (dp[i].visited == false)
        {
            int temp_i = i;
            for (int j = i + 1; j < n; j++)
            {
                if (arr[j] == el)
                {
                    count++;
                    if (j - temp_i > 1)
                    {
                        dp[i].value += 1;
                    }
                    dp[j].visited = true;
                    temp_i = j;
                }
            }
        }
    }
    dp[0].value = (count == n && dp[0].value == 1) ? -1 : dp[0].value;
    dp[0].value += 1;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " -> " << setw(2) << dp[i].value << "     ";
    cout << endl;
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