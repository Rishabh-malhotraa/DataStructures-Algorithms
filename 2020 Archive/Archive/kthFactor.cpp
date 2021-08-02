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

// 1
// 12 3

int kthFactor(int n, int k)
{
    vector<int> arr;
    int count = 0;
    for (int i = 1; i < (int)sqrt(n); i++)
    {
        if (n % i == 0)
        {
            count++;
            arr.push_back(i);
        }
        if (count == k)
            return arr[k - 1];
    }

    return -1;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    cout << kthFactor(n, k) << endl;
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
        solve();

    return 0;
}