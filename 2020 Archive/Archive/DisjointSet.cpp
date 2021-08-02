

#include <bits/stdc++.h>
using namespace std;
class Graph
{
    list<int> *adj;
    int V;

public:
    Graph(int N)
    {
        V = N;
        adj = new list<int>(N);
    }
    void addEdge(int u, int v)
    {
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
};

/**
 * 1. Make A set kind of data strucutre
 * 2. Initialise every element with -1
 * 3. Then keep on nadding element to the disjoin set
 * 4. finding parent using recusrive call pf parent
 * 5. int find(int parent[], int i)
 * 6. union operation, get the root parent of both x1 and x2
 *    if different then parent[x1] = x2
 */
struct Subset
{
    int parent;
    int rank;
};

class DisjointSet
{
    vector<Subset> parent;

public:
    DisjointSet(int V)
    {
        parent.clear();
        parent.resize(V);
        for (int i = 0; i < V; i++)
        {
            parent[i].parent = -1;
            parent[i].rank = 0;
        }
    }

    int find(int node)
    {
        if (parent[node] == 1)
            return node;
        return find(parent[node]);
    }

    void Union(int node1, int node2)
    {
        int p1 = find(node1);
        int p2 = find(node2);

        // check based on their ranks

        if (p1 != p2)
        {
            parent[p1] = p2;
        }
    }
};

bool isCycle(list<int> adj[], int V)
{
    DisjointSet d(V);

    for (int i = 0; i < V; i++)
        for (int j : adj[i])
        {
            int p1 = d.find(i);
            int p2 = d.find(j);

            if (p1 != p2)
            {
                d.Union(p1, p2);
            }
            if (p1 == p2)
                return true;
        }
}

int main()
{

#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    return 0;
}