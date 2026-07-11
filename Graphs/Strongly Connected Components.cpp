// Using Kosaraju's Algorithm
// SCC is a grp of vertices where every vertex is reachable from every other vertex in the same group.

// LOGIC:
// Look for cycles in the graph. If no cycle exists, individual nodes will be SCC.
// Store nodes in the stack in topological sorted order.
// Transpose the graph --> vertices are same, only edges are reversed.
// Do DFS according to stack nodes on the transpose graph that is created.

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Graph {
public:
    vector<vector<int>> adj;
    int V;

    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    void kosaraju() {

    }
};

int main() {
    Graph g(5);

    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(1, 0);
    g.addEdge(2, 1);
    g.addEdge(3, 4);

    g.kosaraju();

    return 0;
}