// #newnotes
// Leetcode 198
// 1D Dynamic Programming

// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping 
// you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent 
// houses were broken into on the same night.
// Given an integer array nums representing the amount of money of each house, return the max amount of money you can rob tonight without alerting the police.

/*
Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.
*/

#include <iostream>
#include <vector>
using namespace std;

// Using tabulation + memory optimization
int rob(vector<int>& nums) {
    int n = nums.size();

    if(n == 1) return nums[0]; // if only 1 house is there, rob that house

    int prev1 = nums[0]; // dp[0]
    int prev2 = max(nums[0], nums[1]); // dp[1] // if 2 houses are there, rob one that has max money

    int result = prev2;

    for(int i = 2; i < n; i++) {
        result = max(prev2, prev1 + nums[i]);

        prev1 = prev2;
        prev2 = result;
    }

    return result;
}

int main() {
    vector<int> nums = {2, 7, 9, 3, 1};

    cout << rob(nums);

    return 0;
}

// TC = O(n)
// SC = O(1)
