// LeetCode 3619

// You are given an m x n matrix grid and a positive integer k. An island is a group of positive integers (representing land) that are 
// 4-directionally connected (horizontally or vertically). The total value of an island is the sum of the values of all cells in the 
// island. Return the number of islands with a total value divisible by k.

// Input: grid = [[0,2,1,0,0],[0,5,0,0,5],[0,0,1,0,0],[0,1,4,7,0],[0,2,0,0,8]], k = 5
// Output: 2
// Explanation: The grid contains four islands. Only 2 are divisible by 5.

#include <iostream>
#include <vector>
using namespace std;

int countIslands(vector<vector<int>>& grid, int k) {
}

int main() {
    vector<vector<int>> grid = {{0,2,1,0,0}, {0,5,0,0,5}, {0,0,1,0,0}, {0,1,4,7,0}, {0,2,0,0,8}};
    int k = 5;

    cout << countIslands(grid, k);
    
    return 0;
}

