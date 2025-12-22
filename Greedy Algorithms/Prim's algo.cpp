// PRIMS'S ALGORITHM FOR MST

#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <climits>
using namespace std;

int main()
{
    int V = 6; // no. of vertices

    // Adjacency list: each entry stores (neighbor, weight)
    list<pair<int, int>> adj[V];

    // Edges for undirected graph: adj[u] stores a list of (v, weight) pairs
    adj[0].push_back({1,7});
    adj[1].push_back({0,7});

    adj[0].push_back({2,8});
    adj[2].push_back({0,8});

    adj[1].push_back({3,6});
    adj[3].push_back({1,6});

    adj[1].push_back({2,3});
    adj[2].push_back({1,3});

    adj[2].push_back({4,3});
    adj[4].push_back({2,3});

    adj[2].push_back({3,4});
    adj[3].push_back({2,4});

    adj[3].push_back({4,2});
    adj[4].push_back({3,2});

    adj[3].push_back({5,5});
    adj[5].push_back({3,5});

    adj[4].push_back({5,2});
    adj[5].push_back({4,2});

    // Prim's algo

    // minWeight[i] -> minimum weight needed to connect vertex i to MST
    vector<int> minWeight(V, INT_MAX);

    vector<int> parent(V, -1); // parent of vertex in MST
    vector<bool> mstSet(V, false); // used to track which vertices have been included

    // Min Heap (priority queue). Stores (weight, vertex)
    priority_queue<
        pair<int, int>,
        vector<pair<int,int>>,
        greater<pair<int,int>> // is max-heap by default, so used to change it to a min heap
    > pq;

    // 1. Start from any vertex. Here, choosing vertex 0 as source.
    minWeight[0] = 0;
    pq.push({0,0});
    

    // 2. Continue until all vertices of graph are processed
    while(!pq.empty())
    {
        // extract always the min edge from a vertex
        int u = pq.top().second;
        pq.pop();

        // ignore if a vertex is already included in the MST
        if(mstSet[u]) continue;

        // otherwise, include vertex in MST
        mstSet[u] = true;

        // 3. Traverse adj list of u
        for(auto edge: adj[u])
        {
            int v = edge.first; // neighbor 
            int weight = edge.second;

            /*
                Relaxation condition:
                1. v not in MST
                2. Edge weight smaller than current known minimum
            */

            if(!mstSet[v] && weight< minWeight[v])
            {
                minWeight[v] = weight; // update min weight known
                parent[v] = u;
                pq.push({weight, v});
            }
        }
    }

    int mstCost = 0; // to find sum of all edges in MST

    cout << "\nEdge \tWeight\n";
    for(int i=1; i<V; i++)
    {
        cout << parent[i] << " - " << i << "\t" << minWeight[i] << endl;
        mstCost += minWeight[i];
    }

    cout << "\nTotal MST cost = " << mstCost << endl;
    
    return 0;
}

// TC = O(E log V)