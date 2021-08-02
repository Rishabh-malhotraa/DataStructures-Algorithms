#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007LL
#define ll long long
#define ULL unsigned long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define pnl cout << '\n'
#define deb(x) cout << #x << " " << x << endl;
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MEMSET(x) memset(x, 0, sizeof x)
#define ABS(x) ((x) < 0 ? -(x) : (x))
#define FO(i, n) for (int i = 0; i < (n); i++)
#define FOR(i, n) for (int i = (n); i >= 0; i--)
#define FOA(i, a, b) for (int i = (a); i < (b); i++)

vector<vector<int>> generateMatrix(int n)
{
    // Declaration
    vector<vector<int>> matrix(n, vector<int>(n, 0));

    // Edge Case

    int rowStart = 0;
    int rowEnd = n - 1;
    int colStart = 0;
    int colEnd = n - 1;
    int count = 1;

    while (rowStart <= rowEnd && colStart <= colEnd)
    {

        for (int i = colStart; i <= colEnd; i++)
            matrix[rowStart][i] = count++;

        rowStart++;

        for (int i = rowStart; i <= rowEnd; i++)
            matrix[i][colEnd] = count++;

        colEnd--;

        for (int i = colEnd; i >= colStart; i--)
            // this is for the case in which the final elemnt is a line and not a box
            if (rowStart <= rowEnd)
                matrix[rowEnd][i] = count++;

        rowEnd--;

        for (int i = rowEnd; i >= rowStart; i--)
            if (colStart <= colEnd)
                matrix[i][colStart] = count++;

        colStart++;
    }

    return matrix;
}

void solve()
{
    int n;
    cin >> n;

    vector<vector<int>> arr = generateMatrix(n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        pnl;
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