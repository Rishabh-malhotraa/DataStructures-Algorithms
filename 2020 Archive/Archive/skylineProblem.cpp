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
 * 1. Bifurcate start and end values based on inverted heights
 * 2. If curr height and previous height changes then we have a POI
 * 3. The point to be inserted is x-coords || curr-> height
 * 4. Add o to the multiset for base cases 
 * 5. get the current height for a *heightSet.rbegin();  
 * 
 */
vector<pair<int, int>> getSkyline(vector<vector<int>> &buildings)
{
    vector<pair<int, int>> heights;
    vector<pair<int, int>> result;
    for (const vector<int> building : buildings)
    {
        heights.push_back(make_pair(building[0], building[2]));
        heights.push_back(make_pair(building[1], -building[2]));
    }
    // height done!

    sort(heights.begin(), heights.end());
    set<int> mset = {0};
    int prev = 0;
    for (const auto &h : heights)
    {
        if (h.second > 0)
            mset.insert(h.second);
        else
            mset.erase(mset.find(-h.second));

        int curr = *mset.rbegin();

        if (prev != curr)
        {
            result.push_back({h.first, curr});
            prev = curr;
        }
    }
    return result;
}

void solve()
{
    int n, x;
    cin >> n;
    vector<vector<int>> arr(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 3; j++)
        {
            cin >> x;
            arr[i].push_back(x);
        }

    vector<pair<int, int>> heights = getSkyline(arr);

    for (int i = 0; i < heights.size(); i++)
        cout << heights[i].first << " " << heights[i].second << endl;

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
/* tescase
1
5
2 9 10
3 7 15
5 12 12
15 20 10
19 24 8
*/