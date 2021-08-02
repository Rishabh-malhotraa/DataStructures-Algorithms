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

struct Petrol
{
    int gas;
    int dist;
};
int printTour(Petrol *arr, int n)
{
    int sum = 0;
    FO(i, n)
    {
        sum += arr[i].gas - arr[i].dist;
    }
    if (sum < 0)
    {
        return -1;
    }

    int curr = 0, start = 0;
    FO(i, n)
    {
        curr += arr[i].gas - arr[i].dist;

        if (curr < 0)
        {
            start = i + 1;
            curr = 0;
        }
    }
    return start;
}

int main()
{
    Petrol arr[] = {{6, 4}, {3, 6}, {7, 3}};

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n = sizeof(arr) / sizeof(arr[0]);
    int start = printTour(arr, n);

    (start == -1) ? cout << "No solution" : cout << "Start = " << start;

    return 0;
}