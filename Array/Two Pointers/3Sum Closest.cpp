// LeetCode 16

// You are given an integer array nums of length n and an integer target.
// Find three integers at distinct indices in nums such that the sum is closest to target.
// Return the sum of the three integers.

// Input: nums = [-1,2,1,-4], target = 1
// Output: 2
// Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int n = nums.size();

    int closest = nums[0] + nums[1] + nums[2]; // set initial closest sum

    // i --> represents the 1st no. we need to find. Fix i and find other 2 numbers using 2 pointer approach
    for(int i = 0; i < n-2; i++) {
        int left = i + 1; // left ptr
        int right = n - 1; // right ptr

        while(left < right) {
            int sum = nums[i] + nums[left] + nums[right]; // find current sum

            if(abs(sum - target) < abs(closest - target)) closest = sum; // update closest sum

            if(sum == target) return sum;

            if(sum < target) left++; // find a larger sum

            else right--; // find smaller sum
        }
    }

    return closest;
}

int main() {
    vector<int> nums = {-1, 2, 1, -4};
    int target = 1;

    cout << threeSumClosest(nums, target);

    return 0;
}

// TC = O(n^2)
// SC = O(1)