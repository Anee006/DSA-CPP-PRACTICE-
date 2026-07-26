// LeetCode 628

// Given an integer array nums, find three numbers whose product is maximum and return the maximum product.

/*
Input: nums = [1,2,3,4]
Output: 24
Explanation: 2 * 3 * 4 = 24

Input: [-10, -10, 5, 2]
Output : 500
Explanation: -10 * -10 * 5 = 500
*/

// LOGIC:
// First, sort the array
// To maximize product of 3 numbers there are only 2 possibilities:
// 1. Find product of largest 3 numbers -> nums[n-1] * nums[n-2] * nums[n-3]
// 2. Find product of smallest 2 (most -ve) numbers and the largest number (bcoz 2 -ve make +ve)
// i.e, nums[0] * nums[1] * nums[n-1]
// The max of these 2 will be the ans

#include <iostream>
#include <vector>
using namespace std;

int maximumProduct(vector<int>& nums) {
}

int main() {
    vector<int> nums = {1,2,3,4};

    cout << maximumProduct(nums);

    return 0;
}

// TC = O(n log n) (due to sorting)
// SC = O(1)