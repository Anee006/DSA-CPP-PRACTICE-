// #newnotes
// LeetCode 119
// using Combinatorial Approach

// Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.
// In Pascal's triangle, each number is the sum of the two numbers directly above it.

/*
Input: rowIndex = 3
Output: [1,3,3,1]

Input: rowIndex = 0
Output: [1]

Input: rowIndex = 1
Output: [1,1]
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> getRow(int rowIndex) {
}

int main() {
    int rowIndex = 3;

    vector<int> ans = getRow(rowIndex);

    for(int val : ans) cout << val << " ";

    return 0;
}