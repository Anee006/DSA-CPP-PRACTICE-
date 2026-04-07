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
using namespace std;

int main() {
    // adjacency matrix where if an edge exists, we write the edge capacity
    vector<vector<int>> graph = {
        {0, 11, 12, 0, 0, 0},
        {0, 0, 1, 12, 0, 0},
        {0, 0, 0, 0, 11, 0},
        {0, 0, 0, 0, 7, 19},
        {0, 0, 0, 0, 0, 4},
        {0, 0, 0, 0, 0, 0}
    };

    int source = 0, sink = 5;

    return 0;
}