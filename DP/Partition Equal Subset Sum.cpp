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
// Compute total sum. If odd -> not possible
// Target = sum / 2
// Use DP: Either take element OR don't take. If dp[target] == true -> possible

#include <iostream>
#include <vector>
using namespace std;

bool canPartition(vector<int>& nums) {

}

int main() {
    vector<int> nums = {1, 5, 11, 5};

    if(canPartition(nums)) cout << "Can be partitioned into 2 subsets with equal sum.";
    else cout << "Cannot be partitioned";

    return 0;
}


// TC = O(n * target)
// SC = O(target)