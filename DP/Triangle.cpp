// LeetCode 120
// Using bottom-up DP

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
    int n = triangle.size();

    // start from 2nd last row (n-2) and move to top row(0)
    for(int row = n-2; row >= 0; row--) {
        for(int col = 0; col <= row; col++) {
            triangle[row][col] += min(triangle[row+1][col], triangle[row+1][col+1]); // based on given condition
        }
    }

    return triangle[0][0]; // top element hold the min path sum
}

int main() {
    vector<vector<int>> triangle = {{2},{3,4},{6,5,7},{4,1,8,3}};

    cout << minimumTotal(triangle);

    return 0;
}

// TC = O(N^2)
// SC = O(1)