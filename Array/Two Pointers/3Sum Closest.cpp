// LeetCode 16

// You are given an integer array nums of length n and an integer target.
// Find three integers at distinct indices in nums such that the sum is closest to target.
// Return the sum of the three integers.

// Input: nums = [-1,2,1,-4], target = 1
// Output: 2
// Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

#include <iostream>
#include <vector>
using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
}

int main() {
    vector<int> nums = {-1, 2, 1, -4};
    int target = 1;

    cout << threeSumClosest(nums, target);

    return 0;
}

// TC = O(n^2)
// SC = O(1)