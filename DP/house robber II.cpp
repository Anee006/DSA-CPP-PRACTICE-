// #newnotes
// Leetcode 213
// Using Tabulation + Memory optimization

// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses 
// at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have 
// a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.
// Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

/*
Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4
*/

#include <iostream>
#include <vector>
using namespace std;

// House Robber - I logic
int helper(vector<int>& nums, int st, int end) {
    int n = nums.size();

    if(n == 1) return nums[0];

    int prev1 = nums[st];
    int prev2 = max(nums[st], nums[st+1]);

    int result = prev2;

    // i -> tracks nums array , j -> tracks dp array
    for(int i = st + 2, j = 2; i <= end; i++, j++) {
        result = max(prev2, prev1 + nums[i]);
        prev1 = prev2;
        prev2 = result;
    }

    return result;
}

int rob(vector<int>& nums) {
    int n = nums.size();

    if(n == 1) return nums[0];
    if(n == 2) return max(nums[0], nums[1]);

    return max(helper(nums, 0, n-2), helper(nums, 1, n-1));
}

int main() {
    vector<int> nums = {1, 2, 3, 1};

    cout << rob(nums);

    return 0;
}

// TC = O(n)
// SC = O(1)