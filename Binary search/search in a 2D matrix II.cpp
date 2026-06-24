// #notes
// LeetCode 240 

// Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix.It has the following properties:
// Integers in each row are sorted in ascending from left to right.
// Integers in each column are sorted in ascending from top to bottom.

// For the given 5x5 matrix: {{1,4,7,11,15}, {2,5,8,12,19}, {3,6,9,16,22}, {10,13,14,17,24}, {18,21,23,26,30}} and target = 5
// Here m x n = 5x5 (is the size of matrix)

// LOGIC:
// In this case we do not have a unique row in which our target will exist
// In matrix we know for sure that the lowest value will exist in 1st cell i.e, matrix[0][0]
// and the highest value will exist in the last cell i.e, in matrix[m-1][n-1].
// so range becomes- (0,0) and (m-1, n-1)
// we can assume either the val 15(i.e, (0,n-1) cell) or 18(i.e, (m-1,0) cell) as the mid for our 2D matrix

// See lec 36 on youtube for complete logic 

#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) { 
    int m = matrix.size(); // to find no. of rows
    int n = matrix[0].size(); // to find no. of cols

    int row = 0, col = n-1; // to make the corner el (0, n-1) i.e, in this case 15 as out mid value

    while(row < m && col >= 0) {
        if(target == matrix[row][col]) return true;
        
        else if(target < matrix[row][col]) col--; // go left, that is decrease col by one
        
        else row++; // go one row down i.e, increase row by one
    }
    return false;
}

int main() {
    vector<vector<int>> matrix= {{1,4,7,11,15}, {2,5,8,12,19}, {3,6,9,16,22}, {10,13,14,17,24}, {18,21,23,26,30}};
    
    cout << searchMatrix(matrix, 5) << endl; // target = 34

    return 0;
}

// TC: O(log(m*n))