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
    int V;
    list<int> *adj;

public:
    Graph(int V)
    {
        this->V = V;
        adj = new list<int>[V];
    }

    // undirected graph
    void addEdge(int u, int v)
    {
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    /**
     * 1. modified DFS -> if a node has degree less than k than we need to process it neighbours
     * 
     * 2. check the k value of v if its less than k than process the its adjacent node
     * meaning decrese its k value(degree) by 1
     * 
     * the decrememnt will happen before we check the if statement because we may visit that node
     * from our first neighbour and never and needs to decrement its value even though we have explored
     * it we have not decreased it value
     * 
     * a3. gain if the node has k value > key but after processing its neigbour it k value 
     * decreases then we need to decrease the degree of our main node
     *
     * return is vDegree[v]> k true || or false

     */
    bool DFSUtil(int v, vector<bool> &visited, vector<int> &vDegree, int k)
    {
        visited[v] = true;

        for (auto i : adj[v])
        {
            if (vDegree[v] < k)
                vDegree[i]--;

            if (visited[i] = false)
            {

                if (!DFSUtil(i, visited, vDegree, k))
                    vDegree[v]--;
            }
        }

        return (vDegree[v] > k);
    }
    /**
     * 
     * int the core 
     * 
     * 1. compute the vDegree list array -> vDegree[i] = adj[i].size()
     * 
     * while you are at it also find the start vertex, the node  with the minimum
     * degree for improved complexity ,maybe idk
     * 
     * 2. looping throught the array for connected dfs thingy to visit all nodes and shizz
     * 
     * 3. print all the nodes vDegree[v]>=k and the if true while printing it node also
     * check if the neighbour satisfy the conditions
     */
    void printKCores(int k)
    {
        vector<bool> visited(V, false);
        vector<int> vDegree(V);

        int min = INT_MAX, start = 0;

        for (int i = 0; i < V; i++)
        {
            vDegree[i] = adj[i].size();

            if (vDegree[i] < min)
            {
                min = vDegree[i];
                start = i;
            }
        }
        DFSUtil(start, visited, vDegree, k);

        for (int i = 0; i < V; i++)
        {
            if (visited[i] == false)
                DFSUtil(i, visited, vDegree, k);
        }

        cout << "K-Cores : \n";

        for (int i = 0; i < V; i++)
        {
            if (vDegree[i] >= k)
            {
                cout << "\n[" << i << "] :- ";

                for (auto it : adj[i])
                {
                    if (vDegree[it] >= k)
                        cout << " " << it << " ";
                }
            }
        }
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

    // Create a graph given in the above diagram
    int k = 3;
    Graph g1(9);
    g1.addEdge(0, 1);
    g1.addEdge(0, 2);
    g1.addEdge(1, 2);
    g1.addEdge(1, 5);
    g1.addEdge(2, 3);
    g1.addEdge(2, 4);
    g1.addEdge(2, 5);
    g1.addEdge(2, 6);
    g1.addEdge(3, 4);
    g1.addEdge(3, 6);
    g1.addEdge(3, 7);
    g1.addEdge(4, 6);
    g1.addEdge(4, 7);
    g1.addEdge(5, 6);
    g1.addEdge(5, 8);
    g1.addEdge(6, 7);
    g1.addEdge(6, 8);
    g1.printKCores(k);

    cout << endl
         << endl;

    Graph g2(13);
    g2.addEdge(0, 1);
    g2.addEdge(0, 2);
    g2.addEdge(0, 3);
    g2.addEdge(1, 4);
    g2.addEdge(1, 5);
    g2.addEdge(1, 6);
    g2.addEdge(2, 7);
    g2.addEdge(2, 8);
    g2.addEdge(2, 9);
    g2.addEdge(3, 10);
    g2.addEdge(3, 11);
    g2.addEdge(3, 12);
    g2.printKCores(k);

    return 0;
}