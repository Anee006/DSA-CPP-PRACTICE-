// LeetCode 300

// Given an integer array nums, return the length of the longest strictly increasing subsequence.

/*
Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int LIS(vector<int>& nums) {
    int n = nums.size();

    vector<int> dp(n, 1); // all values in dp array initialized with 1

    for(int i=1; i<n; i++) {
        for(int j=0; j<i; j++) {
            if(nums[i] > nums[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    return *max_element(dp.begin(), dp.end());
}

int main() {
    vector<int> nums = {10,9,2,5,3,7,101,18};

    cout << "Length of LIS: " << LIS(nums);
    return 0;
}

// TC = O(n^2), SC = O(n)