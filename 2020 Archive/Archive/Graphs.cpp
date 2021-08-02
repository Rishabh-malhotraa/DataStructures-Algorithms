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

    void BFS(int start_node)
    {
        int visited[V];
        memset(visited, false, sizeof visited);

        queue<int> q;
        visited[start_node] = true;

        q.push(start_node);

        while (!q.empty())
        {
            int x = q.front();
            cout << x << " ";
            q.pop();

            for (auto i : adj[x])
            {
                if (visited[i] == false)
                {
                    visited[i] == true;
                    q.push(i);
                }
            }
        }
    }

    void dfsUtil(int node, bool *visited)
    {
        visited[node] = true;

        for (auto i : adj[node])
        {
            if (visited[i] == false)
            {
                dfsUtil(i, visited);
            }
        }
    }

    void dfs()
    {
        bool visited[V];
        memset(visited, false, sizeof visited);

        // this is to make sure we visited all the node
        for (int i = 0; i < V; i++)
        {
            if (visited[i] == false)
            {
                dfsUtil(i, visited);
            }
        }
    }

    int minDistance(int *dist, bool *processed)
    {
        int min = INT_MAX;

        for (int i = 0; i < V; i++)
            if (!processed[i] && dist[i] < min)
                min = dist[i];

        return min;
    }
    /**
     * # this prgram find the startest distance from the source node
     * Things to do about Djikstra Algorithm
     * 1. Initialize the distance array int min @param dist[V] with INT_MAX
     * 2. @param processed to check which nodes are processed, initalise with all false
     * 3. find the minVertex, this is done by looping though all the node and return the node with the min distance
     * 4. set the node as processed=true
     * 5. explore all the neighboring nodes, loop 0 -> N with conditions
     *  check if edge exist, if dist[src] is not INF, and d[u]+d[u][v] > d[v]
     */
    void dijkstra_matrix(int start, int Graph[][9])
    {
        int dist[V];
        bool processed[V];
        fill(processed, processed + V, false);
        fill(dist, dist + V, INT_MAX);
        dist[start] = 0;
        for (int i = 0; i < V; i++)
        {
            int min = minDistance(dist, processed);
            processed[min] = true;

            for (int i : Graph[min])
            {
                //update the distance off all the nodes now
            }
        }
    }
    /** 
     * @param fiirst -> index
     * @param second -> distance
     */
    typedef pair<int, int> Pair;

#define INF 100000;

    /**
     * initialize the priority queue (min)
     * initialize the distance to zero for source and insert that pair
     * loop the pq(like bfs, extract the top element pop it off)
     * loop the adjacency list and check for the condition
     */

    list<Pair> *adj_;

    void dijkstra(int src)
    {
        adj_ = new list<Pair>(V);
        vector<int> dist(V, INF);
        priority_queue<Pair, vector<Pair>, greater<int>> pq;
        // pq.push(make_pair(src, 0));
        pq.push(make_pair(src, 0));

        while (!pq.empty())
        {
            pair<int, int> ele = pq.top();
            pq.pop();
            v = ele.first;
            for (auto ele : adj_[v])
            {
                int u = ele.first;
                int weight = ele.second;
                if (d[v] + weight < d[u])
                {
                    d[u] = d[v] + weight;
                    pq.push(make_pair(u, d[u]));
                }
            }
        }
    }
};

int main()
{

    int x;
    int n;
    cin >> n;
    Graph g(4);

    g.addEdge(0, 1);

    g.dfs();
    return 0;
}
