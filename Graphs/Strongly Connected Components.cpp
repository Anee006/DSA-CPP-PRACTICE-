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

    // perform topological sort
    void topoSort(int curr, vector<bool>& vis, stack<int>& s) {
        vis[curr] = true;

        for(int neigh : adj[curr]) {
            if(!vis[neigh]) topoSort(neigh, vis, s);
        }

        s.push(curr);
    }

    void dfs(int curr, vector<bool>& vis, vector<vector<int>>& transpose) {
        vis[curr] = true;
        cout << curr << " ";

        for(int neigh : transpose[curr]) {
            if(!vis[neigh]) {
                dfs(neigh, vis, transpose);
            }
        }
    }

    void kosaraju() {
        stack<int> s;
        vector<bool> vis(V, false);

        for(int i=0; i<V; i++) {
            if(!vis[i]) topoSort(i, vis, s);
        }

        // transpose the graph
        vector<vector<int>> transpose(V);

        for(int u=0; u<V; u++) { // edge is u --> v
            vis[u] = false; // reassign vis vector so that we can use it again

            for(int v : adj[u]) {
                transpose[v].push_back(u); // Now edge is v --> u
            }
        }

        // perform dfs on the transpose graph
        while(s.size() > 0) {
            int curr = s.top();
            s.pop();

            if(!vis[curr]) {
                dfs(curr, vis, transpose);
                cout << endl;
            }
        }
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

// TC = O(V + E)