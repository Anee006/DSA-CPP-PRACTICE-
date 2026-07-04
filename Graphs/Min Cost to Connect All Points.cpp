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


// Manhattan distance b/w all points:
//       P0      P1      P2      P3      P4
//  P0   0       4       13      7       7
//  P1   4       0       9       3       7
//  P2   13      9       0       10      14
//  P3   7       3       10      0       4
//  P4   7       7       14      4       0


#include <iostream>
#include <vector>
using namespace std;

int minCostConnectPoints(vector<vector<int>>& points) {
        
}

int main() {
    vector<vector<int>> points = {{0,0},{2,2},{3,10},{5,2},{7,0}};

    cout << minCostConnectPoints(points);

    return 0;
}