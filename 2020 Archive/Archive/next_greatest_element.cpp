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

#include <chrono>
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

    stack<int> s;
    s.push(0);
    vector<int> nge(n, -1);

    for (int i = 1; i < n; i++)
    {

        if (!s.empty())
        {

            while (!s.empty() && arr[s.top()] < arr[i])
            {
                nge[s.top()] = arr[i];
                s.pop();
            }

            // it is important we dont check this as this causes seg sev fault
            // even thought this it is correct to check this if you have it above the loop
            // else no because the condition becomes redundant and cause segsev if the stack
            // becomes empty after the while loop
            // if (arr[s.top()] >= arr[i])
            s.push(i);
        }
    }
    FO(i, n)
    {
        cout << nge[i] << " ";
    }
    pnl;

    return;
}

int main()
{
    Timer time;
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