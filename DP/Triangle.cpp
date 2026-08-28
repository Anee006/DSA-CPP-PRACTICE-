// LeetCode 120

// Given a triangle array, return the minimum path sum from top to bottom.
// For each step, you may move to an adjacent number of the row below. 
// If you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

/*
Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
*/

#include <iostream>
#include <vector>
using namespace std;

int minimumTotal(vector<vector<int>>& triangle) {
}

int main() {
    vector<vector<int>> triangle = {{2},{3,4},{6,5,7},{4,1,8,3}};

    cout << minimumTotal(triangle);

    return 0;
}