// Using Tarjan's algo for finding Articulation point
// A node is an articulation point if removing it increases the number of connected components.

// Conditions for Articulation Point:
// For a node u:

// Case 1: Root node of DFS
// If root has more than 1 child: children > 1 -> u is articulation point.

// Case 2: Non-root node
// If: low[child] >= disc[u] -> u is articulation point.

#include <iostream>
#include <vector>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;
    vector<int> disc;
    vector<int> low;
    vector<bool> visited;
    vector<bool> isArticulation;
    int timer;

public:

    Graph(int vertices) {
        V = vertices;
        adj.resize(V);
        disc.resize(V);
        low.resize(V);
        visited.assign(V, false);
        isArticulation.assign(V, false);
        timer = 0;
    }

    void addEdge(int u , int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void DFS(int u, int parent) {
        visited[u] = true;
        disc[u] = low[u] = timer++;
        int children = 0;

        for(int v : adj[u]) {
            if(v == parent) continue;

            if(!visited[v]) {
                children++;
                DFS(v, u);
                low[u] = min(low[u], low[v]);

                // Non-root articulation point:
                if(parent != -1 && low[v] >= disc[u]) {
                    isArticulation[u] = true;
                }
            }

            else {
                low[u] = min(low[u], disc[v]);
            }
        }

        // Root articulation point
        if(parent == -1 && children > 1) {
            isArticulation[u] = true;
        }
    }

    void findAP() {
        for(int i = 0; i < V; i++) {
            if(!visited[i]) {
                DFS(i, -1);
            }
        }

        cout << "Articulation Points:\n";

        for(int i = 0; i < V; i++) {
            if(isArticulation[i]) cout << i << " ";
        }
        cout << endl;
    }
};

int main()
{
    Graph g(7);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,0);
    g.addEdge(1,3);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(5,3);
    g.addEdge(3,6);

    g.findAP();

    return 0;
}

// TC = O(V+E)
// SC = O(V)