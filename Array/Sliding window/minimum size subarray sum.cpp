// LeetCode 209

// Given an array of positive integers nums and a positive integer target, return the minimal length of a subarray whose sum is greater than or 
// equal to target. If there is no such subarray, return 0 instead.

/*
Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.
*/

// LOGIC:
// Expand window (r++)
// Shrink while sum >= X
// Track minimum length

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int target = 7;
    vector<int> nums = {2,3,1,2,4,3};

    return 0;
}

// TC = O(n)