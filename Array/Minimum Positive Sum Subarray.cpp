// LeetCode 3364

// You are given an integer array nums and two integers l and r. Your task is to find the minimum sum of a subarray whose size is between l and r 
// (inclusive) and whose sum is greater than 0. Return the minimum sum of such a subarray. If no such subarray exists, return -1.

/*
Input: nums = [3, -2, 1, 4], l = 2, r = 3
Output: 1

Explanation:
The subarrays of length between l = 2 and r = 3 where the sum is greater than 0 are:
[3, -2] with a sum of 1
[1, 4] with a sum of 5
[3, -2, 1] with a sum of 2
[-2, 1, 4] with a sum of 3
Out of these, the subarray [3, -2] has a sum of 1, which is the smallest positive sum. Hence, the answer is 1.
*/

#include <iostream>
#include <vector>
using namespace std;

int minimumSumSubarray(vector<int>& nums, int l, int r) {
    int n = nums.size();
    int ans = INT_MAX;

    for(int i = 0; i < n; i++) { // select starting idx
        int sum = 0;

        for(int j = i; j < n; j++) { // extend subarray
            sum += nums[j];

            int len = j - i + 1;

            if(len >= l && len <= r && sum > 0) ans = min(ans, sum);

            if(len >= r) break;
        }
    }
    if(ans == INT_MAX) return -1;

    return ans;
}

int main() {
    vector<int> nums = {3, -2, 1, 4};
    int l = 2, r = 3;

    cout << minimumSumSubarray(nums, l, r);

    return 0;
}

// TC: O(n * r)
// SC: O(1)