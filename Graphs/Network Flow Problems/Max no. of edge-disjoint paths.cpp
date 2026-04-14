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

int maxFiles(vector<vector<int>>& graph, int s , int t) {

}

int main() {
    vector<vector<int>> graph = {
        {0,1,1,0,0,0},
        {0,0,1,1,0,0},
        {0,0,0,1,1,0},
        {0,0,0,0,0,1},
        {0,0,0,0,0,1},
        {0,0,0,0,0,0}
    };

    int s = 0, t = 5;

    cout << "Max no. of files: " << maxFiles(graph, s, t);

    return 0;
}