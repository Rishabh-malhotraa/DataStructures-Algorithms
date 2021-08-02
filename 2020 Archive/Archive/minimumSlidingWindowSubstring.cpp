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

string minWindow(string s, string t)
{
    /**
	 * *. WE need to acquire a subtring of any length which contains the sequecne
	 * *. Once we acquire we start reducuing the left pointer to see
	 * 1. Make a hash map for string t
	 * 2. Keep a cumulative freuency country with the help of a hash
	 * 3. Check if the size of the window is bigger than k 
	 * 	  Then start moving the left pointer to shrink
	 * 4, Shirink the ting its not in the t ot by reducing it still  	
	 * 	  keeps the frequency above the asked limit	 
	 * 5. have a min counter which keeps track of the min len and min string
	 * 6. you only want to change the substring when the value of min changes
	 */
    unordered_map<char, int> umap;
    unordered_map<char, int> window;

    int lenghtOfWindow = 0, l = 0, r = 0;
    int minLen = INT_MAX;
    string result = "";
    for (int i = 0; i < t.size(); i++)
        umap[t[i]] += 1;

    //  A	B	A	A	C	B	A	B
    // |
    for (r = 0; r < s.size(); r++)
    {
        char ch = s[r];
        if (umap.find(ch) != umap.end())
        {
            window[ch] += 1;
            // we only want to execute the second code once we have the valid substring
            // adding addition characters will casue the second part to be execuited before-hand
            if (window[ch] <= umap[ch])
                lenghtOfWindow++;
        }

        // shrink;
        if (lenghtOfWindow >= t.length())
        {
            // can you reduce the string???
            while (!umap.count(s[l]) || window[s[l]] - 1 >= umap[s[l]])
            {
                window[s[l]]--;
                l++;
            }
            if (r - l + 1 < minLen)
            {
                minLen = r - l + 1;
                result = s.substr(l, minLen);
            }
        }
    }
    return result;
}

void solve()
{
    string s, t;
    cin >> s >> t;

    cout << minWindow(s, t) << endl;

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