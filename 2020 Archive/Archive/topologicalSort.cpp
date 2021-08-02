#include <bits/stdc++.h>
#include <string>
using namespace std;
#define MOD 1000000007LL
#define ll long long
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

class Graph
{
    list<int> *adj;
    int V;

public:
    Graph(int N)
    {
        V = N;
        adj = new list<int>[N];
    }
    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
    }
    void topologicalSortUtil(vector<bool> &visited, stack<int> &s, int node)
    {
        visited[node] = true;
        // printing the element here would basically be dfs
        for (int i : adj[node])
        {
            if (visited[i] == false)
                topologicalSortUtil(visited, s, i);
        }

        s.push(node);
    }

    void topologicalSort()
    {
        vector<bool> visited(V, false);
        stack<int> s;

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
                topologicalSortUtil(visited, s, i);
        }

        while (!s.empty())
        {
            cout << s.top() << " ";
            s.pop();
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    cout << "Following is a Topological Sort of the given graph \n";
    g.topologicalSort();

    return 0;
}