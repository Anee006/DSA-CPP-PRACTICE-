// LeetCode 416
// uses concept of 0/1 Knapsack

// Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements 
// in both subsets is equal, or false otherwise.

/*
Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
*/

// LOGIC:
// Compute total sum. If odd -> not possible (cannot divide into 2 equal subsets)
// Target = sum / 2
// Use DP: Either take element OR don't take. If dp[target] == true -> possible

#include <iostream>
#include <vector>
using namespace std;

bool canPartition(vector<int>& nums) {
    int sum = 0;

    // find the total sum
    for(int x : nums) sum += x;

    // if sum is odd, cannot divide into 2 equal subsets
    if(sum % 2 != 0) return false;

    int target = sum/2;

    // create DP array --> dp[j] = can we make sum "j" using elements?
    vector<bool> dp(target + 1, false);

    dp[0] = true; // base case

    // 0/1 knapsack
    for(int i=0; i<nums.size(); i++) {
        // traverse backwards
        for(int j = target; j >= nums[i]; j--) {
            dp[j] = dp[j] || dp[j - nums[i]];
        }
    }
    return dp[target];
}

int main() {
    vector<int> nums = {1, 5, 11, 5};

    if(canPartition(nums)) cout << "True";
    else cout << "False";

    return 0;
}

// TC = O(n * target)
// SC = O(target)