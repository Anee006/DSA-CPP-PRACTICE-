// K Closest Points to Origin (LeetCode 973)

// List of points have been given on 2D Plane. Calculate K closest points to the origin (0,0) (Consider
// euclidean distance to find the distance between two points). 
// Write a code to return the answer in any order. The solution is guaranteed to be unique.

// LOGIC:
// compute the squared Euclidean distance: (d*d = x*x + y*y)
// sort the points based on this distance.
// return the first k points, which are the closest after sorting.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b) {
        return (a[0]*a[0] + a[1]*a[1]) < (b[0]*b[0] + b[1]*b[1]); // sorts in asc order
    });

    vector<vector<int>> result(points.begin(), points.begin() + k);
    return result;
}
// TC = O(nlogn)

int main() {
    vector<vector<int>> points = {{3,3}, {5,-1}, {-2, 4}};
    int k = 2;

    vector<vector<int>> ans = kClosest(points, k);

    for(auto p : ans) cout << "[" << p[0] << "," << p[1] << "] ";

    return 0;
}