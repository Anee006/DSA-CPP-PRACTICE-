// LeetCode 118

// Given an integer numRows, return the first numRows of Pascal's triangle. 
// In Pascal's triangle, each number is the sum of the two numbers directly above it.

// Input: numRows = 5
// Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

// LOGIC:
// In Pascal's Triangle, the first and last elements of every row are always 1. 
// Every element at [i][j] (i -> row, j -> col) is the sum of the two elements directly above it: triangle[i-1][j-1] + triangle[i-1][j].
// triangle[i-1][j-1] -> diagonally left, triangle[i-1][j] -> directly above 

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> triangle(numRows);

    for(int i = 0; i < numRows; i++) {
        triangle[i].resize(i+1, 1); // row i has (i + 1) elements, initialized with 1

        for(int j = 1; j < i; j++) { // fill inner elements from index 1 to i - 1
            triangle[i][j] = triangle[i-1][j-1] + triangle[i-1][j];
        }
    }
    return triangle;
}

int main() {
    int numRows = 5;

    vector<vector<int>> ans = generate(numRows);

    for(int i = 0; i < numRows; i++) {
        for(int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}

// TC = O(numRows ^ 2)
// SC = O(1)