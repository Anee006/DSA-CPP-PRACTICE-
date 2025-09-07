// #notes
//CHECK KNIGHTS TOUR CONFIGURATION 
//using recursion

//There is a knight on an n x n chessboard. In a valid configuration, the knight starts at the top-left cell of the board and visits every cell 
//on the board exactly once.

//You are given an n x n integer matrix grid consisting of distinct integers from the range [0, n * n - 1] where grid[row][col] indicates that 
//the cell (row, col) is the grid[row][col]th cell that the knight visited. The moves are 0-indexed.

//Return true if grid represents a valid configuration of the knight's movements or false otherwise.

//Note: A valid knight move consists of moving two squares vertically and one square horizontally, or two squares horizontally and one square 
//vertically. There are total eight moves possible of a knight from some cell.

//Input: grid = [[0,3,6],[5,8,1],[2,7,4]]
//Output: false
//Explanation: In this grid, the 8th move of the knight is not valid considering its position after the 7th move.

//Constraints:
//3 <= n <= 7
//0 <= grid[row][col] < n * n
//All integers in grid are unique.

#include <iostream>
#include <vector>
using namespace std;

//helper fn
bool isValid(vector<vector<int>>& grid, int r, int c, int n, int expectedValue) //here r = row, c = column and n = size of grid
{
    //base case for false value (i.e, invalid val):
    if(r<0 || c<0 || r >=n || c >= n || grid[r][c] != expectedValue) //the last condition is to check if we are moving in the correct order or not
    //here: r<0 || c<0 || r >=n || c >= n || , are to ensure that knight does not go out of the boundary of the grid
    {
        return false;
    }

    if(expectedValue == n*n - 1) //total moves we can make = n*n - 1. So if expVal == n*n-1 means we have checked all values.
    {
        return true;
    }

    //-----------------------------------------------------------------------------------------------------------------------------
    //NOTE:
    //true: means we are at correct configuration
    //false: means we are at incorrect configuration. Means knight is not going in the correct way. We need to change it
    //-----------------------------------------------------------------------------------------------------------------------------


    //check the 8 possible moves:

    //for move 1:
    int ans1 = isValid(grid, r-2, c+1, n, expectedValue+1); //expected val becomes +1 each time : from 0 to 1 to 2 and so on

    //for move 2:
    int ans2 = isValid(grid, r-1, c+2, n, expectedValue+1);

    //for move 3:
    int ans3 = isValid(grid, r+1, c+2, n, expectedValue+1);

    //for move 4:
    int ans4 = isValid(grid, r+2, c+1, n, expectedValue+1);

    //for move 5:
    int ans5 = isValid(grid, r+2, c-1, n, expectedValue+1);

    //for move 6:
    int ans6 = isValid(grid, r+1, c-2, n, expectedValue+1);

    //for move 7:
    int ans7 = isValid(grid, r-1, c-2, n, expectedValue+1);

    //for move 8:
    int ans8 = isValid(grid, r-2, c-1, n, expectedValue+1);

    return ans1 || ans2 || ans3 || ans4 || ans5 || ans6 || ans7 || ans8; 
    //if even one of the moves return true we will also return true or vice versa
}

bool checkValidGrid(vector<vector<int>>& grid)
{
    
    return isValid(grid, 0, 0, grid.size(), 0);
} 

int main()
{
    vector <vector<int>> grid_1 = { {0,3,6}, {5,8,1}, {2,7,4} };
    cout << checkValidGrid(grid_1) <<endl;

    vector <vector<int>> grid_2 = {{0,11,16,5,20},{17,4,19,10,15},{12,1,8,21,6},{3,18,23,14,9},{24,13,2,7,22}};
    cout << checkValidGrid(grid_2) <<endl;

    
    return 0;
}

//TC = for n*n cells we can take 8 different choices
//TC = O(8 ^ (n*n))

//SC = O(n*n)  ,[due to the call stack]
