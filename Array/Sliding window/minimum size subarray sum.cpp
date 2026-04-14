// LeetCode 209
// using variable sized sliding window

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

int minSubArrayLen(int target, vector<int>& nums) {
    int n = nums.size();
    int l = 0, sum = 0, ans = n + 1;

    for(int r = 0; r < n; r++) {
        sum += nums[r];

        while(sum >= target) {
            ans = min(ans, r - l + 1);
            sum -= nums[l];
            l++;
        }
    }
    return (ans == nums.size() + 1) ? 0 : ans; // to handle case when no valid subarray exists
}

int main() {
    int target = 7;
    vector<int> nums = {2,3,1,2,4,3};

    cout << "Minimal length of subarray: " << minSubArrayLen(target, nums);
    
    return 0;
}

// TC = O(n)