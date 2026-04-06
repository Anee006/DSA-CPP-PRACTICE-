#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int V = 5;

    vector<vector<int>> adj = {{1,2}, {0,2,3}, {0,1,3}, {1,2,4}, {3}};
    vector<int> color(V, -1);
    color[0] = 0;

    for(int u = 1; u < V; u++) {
        set<int> used;

        for(int v : adj[u]) {
            if(color[v] != -1) {
                used.insert(color[v]);
            }
        }

        int c = 0;
        while(used.count(c)) c++;

        color[u] = c;
    }

    for(int i=0; i < V; i++) {
        cout << i;
    }

    return 0;
}

// TC = O(V^2)