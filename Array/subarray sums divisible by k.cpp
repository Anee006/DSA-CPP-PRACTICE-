// LeetCode 974

// Given an integer array nums and an integer k, return the number of non-empty subarrays that have a sum divisible by k.
// A subarray is a contiguous part of an array.

// Example:
/*
Input: nums = [4,5,0,-2,-3,1], k = 5
Output: 7
Explanation: There are 7 subarrays with a sum divisible by k = 5:
[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]
*/

#include <iostream>
#include <vector>
using namespace std;

int subarraysDivByK(vector<int>& nums, int k) {
        
}

int main() {
    vector<int> nums = {4,5,0,-2,-3,1};
    int k = 5;

    cout << subarraysDivByK(nums, k);

    return 0;
}