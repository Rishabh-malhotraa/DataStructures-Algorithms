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

/**
 * Class of Graphs
 * No of vertices and adj list
 * a function to add edges
 * dfs util
 * how to do dfs in directed graph kinda way
 * check again if the shizz is the mother component
 */
class Graph
{
    int V;
    list<int> *adj;

public:
    Graph(int V)
    {
        this->V = V;
        adj = new list<int>[V];
    }

    void addEdge(int v, int node)
    {
        adj[v].push_back(node);
    }

    void dfsUtil(vector<bool> &visited, int v)
    {
        visited[v] = true;

        for (auto it = adj[v].begin(); it != adj[v].end(); it++)
        {
            if (visited[*it] == false)
            {
                dfsUtil(visited, *it);
            }
        }
    }

    int findMother()
    {
        vector<bool> visited(V, false);

        int mother_vertex = 0;

        for (int i = 0; i < V; i++)
        {
            if (visited[i] == false)
            {
                dfsUtil(visited, i);
                mother_vertex = i;
            }
        }

        fill(visited.begin(), visited.end(), false);
        dfsUtil(visited, mother_vertex);

        FO(i, V)
        {
            if (visited[i] == false)
                return -1;
        }
        return mother_vertex;
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
#endif

    // Graph g(7);
    Graph *G = new Graph(7);
    Graph g = *G;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(4, 1);
    g.addEdge(6, 4);
    g.addEdge(5, 6);
    g.addEdge(5, 2);
    g.addEdge(6, 0);

    cout << " The mother vertex is " << g.findMother();
    return 0;
}