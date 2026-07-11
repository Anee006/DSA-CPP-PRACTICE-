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

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
}

int main() {
    vector<vector<int>> connections = {{0,1},{1,2},{2,0},{1,3}};

    vector<vector<int>> ans = criticalConnections(4, connections);

    for(int i=0; i<ans.size(); i++) {
        cout << "[";
        for(int j=0; j<ans[i].size(); j++) {
            cout << ans[i][j] << ",";
        }
        cout << "]\n";
    }

    return 0;
}