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

/**
 * return the steps
 * have a unordered map - vector
 * have a Queue and do level order travel-ish on it (while-for)
 * the next which counts the stepn, its importannt to pass by reference and the clear() it
 * Visited array to only add unvisted indices to the queue
 */
int minJumps(vector<int> &arr)
{
    int n = arr.size();
    unordered_map<int, vector<int>> umap;
    FO(i, n)
    {
        umap[arr[i]].push_back(i);
    }
    vector<bool> visited(n, false);
    visited[0] = true;
    queue<int> q;
    q.push(0);
    int steps = 0;

    while (q.empty() == false)
    {
        for (int i = q.size() - 1; i >= 0; i--)
        {
            int pos = q.front();
            q.pop();

            if (pos == n - 1)
                return steps;
            // you have a fookin next_el array
            vector<int> &next_el = umap[arr[pos]];
            next_el.push_back(pos - 1);
            next_el.push_back(pos + 1);

            for (int j : next_el)
            {
                // here what we do is selectively add things to look in the queue
                if (j >= 0 && j < n && visited[j] == false)
                {
                    q.push(j);
                    visited[j] = true;
                }
            }
            next_el.clear();
        }
        steps++;
    }
    return 0;
    // level order traversal
}

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << minJumps(arr) << endl;
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