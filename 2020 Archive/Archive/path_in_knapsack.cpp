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

struct Element
{
    int row;
    int col;
    string path;
};

void solve()
{
    int n, w;
    cin >> n >> w;
    vector<int> cost(n), wt(n);

    for (int i = 0; i < n; i++)
        cin >> wt[i];

    for (int i = 0; i < n; i++)
        cin >> cost[i];

    int dp[n + 1][w + 1];

    MEMSET(dp);

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < w + 1; j++)
        {
            // include - exclude the element
            if (wt[i - 1] <= j)
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - wt[i - 1]] + cost[i - 1]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    queue<Element> q;

    // do a bfs of the following

    cout << "Solution of Knapscak Problem -> " << dp[n][w] << endl;
    q.push({n, w, ""});
    while (!q.empty())
    {
        Element front = q.front();
        q.pop();

        // now check the neighbours of the element
        // add those elements in the queue which can form to the value of the dp
        int i = front.row;
        int j = front.col;
        string path = front.path;

        int val = dp[i][j];

        if (i == 0 || j == 0)
        {
            cout << path << endl;
            continue;
        }

        //val of prev if you include/ exclude the current elemetn
        int exclude = dp[i - 1][j];
        int include = 0;
        if (j >= wt[i - 1])
            include = dp[i - 1][j - wt[i - 1]] + cost[i - 1];

        if (exclude == val)
            q.push({i - 1, j, path});
        if (include == val)
            q.push({i - 1, j - wt[i - 1], to_string(wt[i - 1]) + " " + path});
    }

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