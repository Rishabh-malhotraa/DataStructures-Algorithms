#include <bits/stdc++.h>
#include <string>
using namespace std;
#define MOD 1000000007LL
typedef long long ll;
#define ULL unsigned long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define pnl cout << endl
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(x) ((x) < 0 ? -(x) : (x))
#define FO(i, n) for (int i = 0; i < (n); i++)
#define FOR(i, n) for (int i = (n); i >= 0; i--)
#define FOA(i, a, b) for (int i = (a); i < (b); i++)

/**
 *  @param{s}  -> string to be tested
 * @param{N} -> length of string
 * @param{k} -> length of substring
 *
 * 1. for k blocks using the window analogy set for ?
 * 2. for k blocks using the window analogy set for !?
 *
 * 3. if shifiting windows results in a non same answer then return false
 *
 * 4. count the number of 0, 1 in the substring and if its
 *    less than k/2 then then print yes else no
 **/

void solve(string s, int n, int k)
{
    for (int i = 0; i < k; i++)
        if (s[i] == '?')
            for (int j = i + k; j < n; j += k)
                if (s[j] != '?')
                {
                    s[i] = s[j];
                    break;
                }

    for (int i = 0; i < k; i++)
        if (s[i] != '?')
            for (int j = i + k; j < n; j += k)
                if (s[j] == '?')
                    s[j] = s[i];
                else if (s[j] != s[i])
                {
                    cout << "NO" << endl;
                    return;
                }

    int c0 = 0, c1 = 0;
    FO(j, k)
    {
        if (s[j] == '0')
            c0++;
        else if (s[j] == '1')
            c1++;
    }

    if (c0 <= (k / 2) && c1 <= (k / 2))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

int main()
{
#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        solve(s, n, k);
    }
    return 0;
}
