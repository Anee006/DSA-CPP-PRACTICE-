// Bellman Ford Algorithm (using Dynamic Programming)
// For single source shortest path. Used for -ve edge weights.

// NOTE: TC of Bellman Ford is worse than that of Dijkstra. Use Bellman Ford only if we have -ve weights.

#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

class Edge
{
public:
    int v;
    int w;

    Edge(int v, int w)
    {
        this->v = v;
        this->w = w;
    }
};

void printPath(int v, vector<int>& parent)
{
    if(parent[v] == -1) // src node
    {
        cout << v;
        return;
    }
    printPath(parent[v], parent);
    cout << " -> " << v;
}

void bellmanFord(int src, vector<vector<Edge>> g, int V)
{
    vector<int> dis(V, INT_MAX); // to store shortest dis from src to each node
    dis[src] = 0;

    vector<int> parent(V, -1);

    // do edge relaxation for V-1 times
    for(int i=0; i< V-1; i++)
    {
        for(int u=0; u<V; u++) // for an edge:  u ---> v
        {
            for(Edge e: g[u])
            {
                if(dis[u] != INT_MAX && dis[u] + e.w < dis[e.v])
                {
                    dis[e.v] = dis[u] + e.w;
                    parent[e.v] = u;
                }
            }
        }
    }

    // to detect negative weight cycles (if exists, Bellman Ford algo fails and needs to stop)
    for(int u=0; u<V; u++)
    {
        for(Edge e: g[u])
        {
            if(dis[u] != INT_MAX && dis[u] + e.w < dis[e.v])
            {
                cout << "Negative weight cycle detected! Cannot proceed further.." << endl;
                return;
            }
            
        }
    }

    for(int i=0; i<V; i++)
    {
        cout << "Shortest distance to " << i << " = " << dis[i] << " , Path: ";
        printPath(i, parent);
        cout << endl;
    }
    cout << endl;
}

int main()
{
    int V = 5; // 5 vertices
    vector<vector<Edge>> g(V);

    g[0].push_back(Edge(1,2));
    g[0].push_back(Edge(2,4));

    g[1].push_back(Edge(4,-1));
    g[1].push_back(Edge(2,-4));

    g[2].push_back(Edge(3,2));

    g[3].push_back(Edge(4,4));

    bellmanFord(0, g, V);

    return 0;
}

// TC = O(V*E)