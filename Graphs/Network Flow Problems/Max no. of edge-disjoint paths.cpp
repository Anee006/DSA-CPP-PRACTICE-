// Given a directed graph (representing a network) and two vertices in it, source 's' and destination 't'. 
// Suppose you want to send some large files from s to t but never have two files use the same network link (to avoid congestion on the links). 
// Implement an algorithm to find out the maximum number of files that can be sent from s to t.

// "No two files use the same link" -> each edge can be used at most once. So, treat every edge capacity = 1

// LOGIC:
// Each augmenting path = one file sent
// Once an edge is used -> capacity becomes 0 (cannot reuse)
// Keep finding paths until none exist

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool bfs(vector<vector<int>>& residual, int V, int s, int t, vector<int>& parent) {
    vector<bool> visited(V, false);
    queue<int> q;

    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        for(int v = 0; v < V; v++) {
            if(!visited[v] && residual[u][v] > 0) {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    return visited[t];
}

int maxFiles(vector<vector<int>>& graph, int V, int s , int t) {
    vector<vector<int>> residual = graph;
    vector<int> parent(V);
    int maxFlow = 0;

    while(bfs(residual, V, s, t, parent)) {
        int pathFlow = INT_MAX;

        for(int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            pathFlow = min(pathFlow, residual[u][v]);
        }

        // update residual graph
        for(int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            residual[u][v] -= pathFlow;
            residual[v][u] += pathFlow;
        }
        maxFlow += pathFlow;
    }
    return maxFlow;
}

int main() {

    int V = 6;

    // Example graph (1 -> edge exists, capacity = 1)

    vector<vector<int>> graph = {
        {0,1,1,0,0,0},
        {0,0,1,1,0,0},
        {0,0,0,1,1,0},
        {0,0,0,0,0,1},
        {0,0,0,0,0,1},
        {0,0,0,0,0,0}
    };

    int s = 0, t = 5;

    cout << "Max no. of files: " << maxFiles(graph, V, s, t);

    return 0;
}

// TC = O(V * E^2)
// SC = O(V^2)