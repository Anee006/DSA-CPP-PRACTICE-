// To find the bridges in an undirected graph.
// A bridge is an edge whose removal increases the number of connected components.

// Condition: low[child] > disc[parent]
// Then: (parent,child) is a bridge.

#include <iostream>
#include <vector>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;
    vector<int> disc; // discovery time
    vector<int> low; // lowest discovery time
    vector<bool> visited;
    int timer;

public:
    Graph(int vertices) {
        V = vertices;
        adj.resize(V);
        disc.resize(V);
        low.resize(V);
        visited.assign(V, false);
        timer = 0;
    }

    void addEdge(int u, int v) { // add undirected edge
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void DFS(int u, int parent) {
        visited[u] = true;
        disc[u] = low[u] = timer++;

        for(int v : adj[u]) { // visit neighbors
            if(v == parent) continue; // ignore edge to parent

            // if neighbor is unvisited
            if(!visited[v]) {
                DFS(v, u);
                low[u] = min(low[u], low[v]);

                if(low[v] > disc[u]) { // check bridge condition
                    cout << u << " - " << v << " is a BRIDGE\n";
                }
            }

            // back edge (neighbor is visited)
            else {
                low[u] = min(low[u], disc[v]);
            }

        }
    }

    void findBridges() {
        for(int i = 0; i<V; i++) {
            if(!visited[i]) {
                DFS(i, -1);
            }
        }
    }
};

int main() {
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(1, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);

    cout << "Bridges are:\n";
    g.findBridges();

    return 0;
}

// TC = O(V + E)
// SC = O(V)