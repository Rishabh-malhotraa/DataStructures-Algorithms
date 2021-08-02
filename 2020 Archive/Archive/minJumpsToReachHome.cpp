
// Getting TLE for aome reason ^_~
#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007LL
#define ll long long
#define ULL unsigned long long
#define pb push
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

int minimumJumps(vector<int> &forbidden, int a, int b, int x)
{
    /**
    * Queue and BFS Solution -- Enter a in the queue
    * Loop level order wise in the queue 
    * Don't add positions that are forbiddent 
    * take care of the case when there are two backwads in a row!!?
    */
    queue<pair<int, bool>> q;

    // true -> means don't go back else you can go back
    q.push({0, true});

    set<int> forb;

    for (int i = 0; i < forbidden.size(); i++)
    {
        forb.insert(forbidden[i]);
    }
    int steps = 0;

    while (q.empty() == false)
    {
        for (int size = q.size(); size > 0; size--)
        {
            pair<int, bool> el = q.front();
            int pos = el.first;
            q.pop();
            if (pos == x)
                return steps;
            if (forb.find(pos) == forb.end())
            {

                if (el.second == false)
                {

                    q.push({pos - b, true});
                    if (pos < x)
                        q.push({pos + a, false});
                    // go forward and backward
                }
                if (el.second == true && pos < x)
                    q.push({pos + a, false});
            }
        }
        steps++;
    }
    return -1;
}

class Timer
{
public:
    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
    std::chrono::duration<float> duration;
    Timer()
    {
        start = std::chrono::high_resolution_clock::now();
    }
    ~Timer()
    {
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        float ms = duration.count() * 1000.0f;
        cout << "\nCode executed in " << ms << "ms\n";
    }
};

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int a, b, x;
    cin >> a >> b >> x;

    cout << minimumJumps(arr, a, b, x) << endl;

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

    Timer time;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}