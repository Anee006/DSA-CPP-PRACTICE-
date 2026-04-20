// To find all pairs shortest path : Floyd Warshall algo

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int V = 4; // no. of vertices
    const int INF = 1e9;

    vector<vector<int>> dist = {{0, 1, INF, INF}, {INF, 0, -2, -1}, {3, INF, 0, 2}, {INF, 5, INF, 0}};

    for(int k = 0; k < V; k++) {
        for(int i = 0; i < V; i++) {
            for(int j = 0; j < V; j++) {
                if(dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    cout << "Shortest distance matrix: " << endl;
    for(auto row : dist) {
        for(int x : row) cout << x << "\t";
        cout << endl;
    }

    return 0;
}

// TC = O(V^3), SC = O(V^2)