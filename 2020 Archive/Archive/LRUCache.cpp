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

class LRUCache
{
private:
    int capacity;
    list<int> dq;
    unordered_map<int, list<int>::iterator> map;

public:
    LRUCache(int capacity)
    {
        this->capacity = capacity;
    }

    void refer(int page_segment)
    {
        /**
         *  3 operations
         *  1. find if the segment is in the cache
         *  2. if yes move it to front
         *  3. if cache full remove LRU and add in front 
         */

        if (map.find(page_segment) == map.end())
        {
            if (capacity == dq.size())
            {
                int x = dq.back();
                dq.pop_back();
                map.erase(x);

                list<int>::iterator it = dq.begin();

                map[page_segment] = it;
                dq.push_front(page_segment);
            }
            else
            {
                dq.push_front(page_segment);
                map[page_segment] = dq.begin();
            }
        }
        else
        {
            auto it = map[page_segment];
            dq.erase(it);
            dq.push_front(page_segment);
            map[page_segment] = dq.begin();
        }
    }

    void display()
    {
        for (int i : dq)
            cout << i << " ";
        pnl;
    }
};

int main()
{
    Timer time;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    LRUCache ca(4);

    ca.refer(1);
    ca.refer(2);
    ca.refer(3);
    ca.refer(1);
    ca.refer(4);
    ca.refer(5);
    ca.display();

    return 0;
}