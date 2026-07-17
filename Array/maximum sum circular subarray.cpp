// Leetcode 918

// Given a circular integer array nums of length n, return the maximum possible sum of a non-empty subarray of nums.
// A circular array means the end of the array connects to the beginning of the array. Formally, the next element of nums[i] is nums[(i + 1) % n] 
// and the previous element of nums[i] is nums[(i - 1 + n) % n].
// Formally, for a subarray nums[i], nums[i + 1], ..., nums[j], there does not exist i <= k1, k2 <= j with k1 % n == k2 % n.

/*
Input: nums = [1,-2,3,-2]
Output: 3
Explanation: Subarray [3] has maximum sum 3.

Input: nums = [5,-3,5]
Output: 10
Explanation: Subarray [5,5] has maximum sum 5 + 5 = 10.
*/

// LOGIC:
// Max circular sum = Total sum - Min circular sum
// For finding Max circular sum --> use Kadane's algo
// For finding Min circular sum --> use Kadane's algo, but instead of maximizing, do minimizing
// E.g: nums = [5,-3,5] --> Total = 5-3+5 = 7 --> Max subarray = 7 , Min subarray = -3 --> circular ans = 7 -(-3) = 10
// So, final ans = max(Max subarray, circular ans) = max(7, 10) = 10
// If max < 0 means all numbers are -ve --> return max

#include <iostream>
#include <vector>
using namespace std;

int maxSubarraySumCircular(vector<int>& nums) {
}

int main() {
    vector<int> nums = {1, -2, 3, -2};

    return 0;
}


// TC = O(n)
// SC = O(1)