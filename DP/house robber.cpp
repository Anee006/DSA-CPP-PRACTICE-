// Leetcode 198

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

int rob(vector<int>& nums) {
        
}

int main() {
    vector<int> nums = {2, 7, 9, 3, 1};

    cout << rob(nums);

    return 0;
}

