#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int V = 5;

    vector<vector<int>> adj = {{1,2}, {0,2,3}, {0,1,3}, {1,2,4}, {3}};
    vector<int> color(V, -1);
    color[0] = 0;

    return 0;
}

// TC = O(V^2)