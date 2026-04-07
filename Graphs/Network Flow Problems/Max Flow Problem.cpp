// Max Flow Problem using Ford-Fulkerson Algorithm

// Given a graph which represents a flow network where every edge has a capacity. Also given two vertices: 
// source 's' and sink 't' in the graph, we need to find the maximum possible flow from s to t using Ford Fulkerson algo 
// with following constraints:
// a) Flow on an edge doesn't exceed the given capacity of the edge.
// b) Incoming flow is equal to outgoing flow for every vertex except s and t.

// STEPS:
// Convert graph into residual graph.
// Repeatedly:
// Find path from source (s) -> sink (t) using BFS- Edmonds-Karp.
// Find minimum capacity (bottleneck) in that path
// Update residual capacities
// Stop when no augmenting path exists

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

#define V 6 // no. of vertices

// BFS to find if path exists from src to sink
bool bfs(vector<vector<int>>& residual, int s, int t, vector<int>& parent) {
    vector<bool> visited(V, false);
    queue<int> q;

    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        for(int v = 0; v < V; v++) {
            // if not visited and capacity > 0
            if(!visited[v] && residual[u][v] > 0) {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    return visited[t]; // if sink is reached returns true else false
}

// Ford-Fulkerson Algorithm
int fordFulkerson(vector<vector<int>>& graph, int s, int t) {
    vector<vector<int>> residual = graph; // residual graph
    vector<int> parent(V);

    int maxFlow = 0;

    // while there exists an augmenting path
    while(bfs(residual, s, t, parent)) {
        int pathFlow = INT_MAX;

        // find min capacity in path
        for(int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            pathFlow = min(pathFlow, residual[u][v]);
        }

        // update residual capacities
        for(int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            residual[u][v] -= pathFlow;
            residual[v][u] += pathFlow;
        }
        maxFlow += pathFlow; // add to the total max flow
    }
    return maxFlow;
}


int main() {
    // adjacency matrix where if an edge exists, we write the edge capacity
    vector<vector<int>> graph = {
        {0, 11, 12, 0, 0, 0},
        {0, 0, 0, 12, 0, 0},
        {0, 1, 0, 0, 11, 0},
        {0, 0, 0, 0, 0, 19},
        {0, 0, 0, 7, 0, 4},
        {0, 0, 0, 0, 0, 0}
    };

    int source = 0, sink = 5;

    cout << "Max Flow: " << fordFulkerson(graph, source, sink);

    return 0;
}

// TC = O(V * E²)  , using BFS – Edmonds-Karp
// SC = O(V^2) --> residual graph