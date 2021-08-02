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

bool solve()
{
    string str;
    cin >> str;
    stack<char> s;
    for (int i = 0; i < str.length(); i++)
    {
        char element = str[i];

        if (element == '{' || element == '(' || element == '[')
        {
            s.push(element);
            continue;
        }

        // we need to check whether the stack is empty of nah

        if (s.empty())
            return false;

        if (element == ')')
        {
            char x = s.top();
            if (x == '(')
                s.pop();
            else
            {
                return false;
            }
        }
        else if (element == '}')
        {
            char x = s.top();
            if (x == '{')
                s.pop();
            else
            {
                return false;
            }
        }
        else if (element == ']')
        {
            char x = s.top();
            if (x == '[')
                s.pop();
            else
            {
                return false;
            }
        }
    }

    return (s.empty());
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    int t;
    cin >> t;
    while (t--)
    {
        (solve()) ? cout << "balanced" << endl : cout << "not balanced" << endl;
    }
    return 0;
}