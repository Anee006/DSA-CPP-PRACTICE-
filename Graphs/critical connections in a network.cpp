// Leetcode 1192
// use the logic of finding bridge in a graph (Tarjan's algo)

// There are n servers numbered from 0 to n - 1 connected by undirected server-to-server connections forming a network where 
// connections[i] = [ai, bi] represents a connection between servers ai and bi. 
// Any server can reach other servers directly or indirectly through the network.
// A critical connection is a connection that, if removed, will make some servers unable to reach some other server.

// Return all critical connections in the network in any order.

// Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
// Output: [[1,3]]
// Explanation: [[3,1]] is also accepted.

// LOGIC:
// critical connection --> bridge in a graph

#include <iostream>
#include <vector>
using namespace std;

class Graph {
public:
    int time;
    vector<int> dt, low;

    void dfs(int u, int parent, vector<vector<int>>& adj, vector<vector<int>>& bridges) {
        dt[u] = low[u] = time++;

        for(int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i];

            if(dt[v] == -1) { // v is not visited
                dfs(v, u, adj, bridges);
                low[u] = min(low[u], low[v]); // update low

                if(low[v] > dt[u]) { // bridge condition
                    bridges.push_back({u, v});
                }
            }

            else if(v!= parent) {
                low[u] = min(low[u], dt[v]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        // convert graph to adj list
        vector<vector<int>> adj(n);

        for(int i = 0; i < connections.size(); i++) {
            int u = connections[i][0];
            int v = connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        time = 0;
        dt.resize(n, -1); // for each vertex there will be discovery time
        // for an unvisited node, its disc time will be = -1. So we don't need to create a vis array for dfs.

        low.resize(n); // for each vertex there will be lowest discovery time

        vector<vector<int>> bridges; // to store (u,v) for each bridge

        for(int i=0; i<n; i++) {
            if(dt[i] == -1) {
                dfs(i, -1, adj, bridges);
            }
        }
        return bridges;
    }
};

int main() {
    vector<vector<int>> connections = {{0,1},{1,2},{2,0},{1,3}};
    int n = 4;

    Graph g;

    vector<vector<int>> bridges = g.criticalConnections(n, connections); 

    cout << "Bridges are:\n";
    for (int i = 0; i < bridges.size(); i++) {
        cout << bridges[i][0] << "," << bridges[i][1] << endl;
    }

    return 0;
}

// TC = O(V + E) , where V = no. of vertices and E = no. of edges
// SC = O(V)