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

void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& vis, int n, int m, long long& sum) {
    if(i < 0 || j < 0 || i >= n || j >= m || vis[i][j] || grid[i][j] <= 0) return; // base case

    vis[i][j] = true; // mark as visited
    sum += grid[i][j]; // calc sum of an island

    dfs(i-1, j, grid, vis, n, m, sum); // top neighbor
    dfs(i, j+1, grid, vis, n, m, sum); // right neighbor
    dfs(i+1, j, grid, vis, n, m, sum); // bottom neighbor
    dfs(i, j-1, grid, vis, n, m, sum); // left neighbor
}

int countIslands(vector<vector<int>>& grid, int k) {
    if(grid.empty() || grid[0].empty()) return 0;

    int islands = 0;
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<bool>> vis(n, vector<bool>(m, false));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] > 0 && !vis[i][j]) {
                long long sum = 0; // use long long to avoid overflow

                dfs(i, j, grid, vis, n, m, sum);

                if(sum % k == 0) islands++;
            }
        }
    }
    return islands;
}

int main() {
    vector<vector<int>> grid = {{0,2,1,0,0}, {0,5,0,0,5}, {0,0,1,0,0}, {0,1,4,7,0}, {0,2,0,0,8}};
    int k = 5;

    cout << countIslands(grid, k);
    
    return 0;
}

// TC = O(n*m) , where n = no. of rows, m = no. of cols
// SC = O(n*m)