#include <bits/stdc++.h>
using namespace std;
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

    void addEdge(int v, int u)
    {
        adj[v].push_back(u);
    }

    bool cyclicPathUtil(int node, bool *visited, bool *recStack)
    {
        visited[node] = true;
        recStack[node] = true;
        for (auto i : adj[node])
        {
            // entry conditon for looping through vertices
            if (!visited[i] && cyclicPathUtil(i, visited, recStack))
                return true;
            // terminal condition for ending the recurssion
            else if (recStack[i])
                return true;
        }
        recStack[node] = false;
        return false;
    }

    bool isCyclic()
    {
        bool visited[V];
        bool recStack[V];
        memset(visited, false, sizeof visited);
        memset(recStack, false, sizeof recStack);

        for (int i = 0; i < V; i++)
            if (cyclicPathUtil(i, visited, recStack))
                return true;
        return false;
    }
};
int main()
{
    // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    if (g.isCyclic())
        cout << "Graph contains cycle";
    else
        cout << "Graph doesn't contain cycle";
    return 0;
}