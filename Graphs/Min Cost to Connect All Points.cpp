// Leetcode 1584

// You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].
// The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, 
// where |val| denotes the absolute value of val.

// Return the min cost to make all points connected. All points are connected if there is exactly one simple path between any two points.

/*
Input: points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
Output: 20
*/

// LOGIC:
// There are 'n' points (vertices) and each point can make connection with (n-1) points.
// Min cost to connect all points --> MST cost of graph.
// Since, it is a dense graph (many edges can exist), use Prims algo to find MST.

// Manhattan distance b/w all points of the given graph:
//       P0      P1      P2      P3      P4
//  P0   0       4       13      7       7
//  P1   4       0       9       3       7
//  P2   13      9       0       10      14
//  P3   7       3       10      0       4
//  P4   7       7       14      4       0


#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// manhattan distance
int manDist(vector<vector<int>>& points, int p1, int p2) {
    return abs(points[p1][0] - points[p2][0]) + abs(points[p1][1] - points[p2][1]); //  |x1-x2| + |y1-y2|
}

int minCostConnectPoints(vector<vector<int>>& points) {
    int n = points.size();
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // min heap

    vector<bool> mstSet(n, false);
    int mstCost = 0;

    pq.push({0, 0}); // stores {weight, node}

    while(!pq.empty()) {
        auto p = pq.top();
        int wt = p.first;
        int node = p.second;

        pq.pop();

        if(mstSet[node]) continue; // we only need 1 edge till each node in MST

        mstSet[node] = true;
        mstCost += wt;

        // visit unvisited neighbors
        for(int i=0; i<n; i++) {
            if(!mstSet[i]) {
                int edgeWt = manDist(points, node, i);
                pq.push({edgeWt, i});
            }
        }
    }
    return mstCost;
}

int main() {
    vector<vector<int>> points = {{0,0},{2,2},{3,10},{5,2},{7,0}};

    cout << minCostConnectPoints(points);

    return 0;
}

// TC = O(n^2  log n)
// SC = O(n^2)