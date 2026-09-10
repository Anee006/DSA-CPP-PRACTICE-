// LeetCode 220

// You are given an integer array nums and two integers indexDiff and valueDiff.
// Find a pair of indices (i, j) such that:
// i != j,
// abs(i - j) <= indexDiff.
// abs(nums[i] - nums[j]) <= valueDiff, and
// Return true if such pair exists or false otherwise.

/*
Input: nums = [1,2,3,1], indexDiff = 3, valueDiff = 0
Output: true
Explanation: We can choose (i, j) = (0, 3).
We satisfy the three conditions:
i != j --> 0 != 3
abs(i - j) <= indexDiff --> abs(0 - 3) <= 3
abs(nums[i] - nums[j]) <= valueDiff --> abs(1 - 1) <= 0
*/

#include <iostream>
#include <set>
#include <vector>
using namespace std;

bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
}

int main() {
    vector<int> nums = {1, 2, 3, 1};
    int indexDiff = 3, valueDiff = 0;

    containsNearbyAlmostDuplicate(nums, indexDiff, valueDiff) ? cout << "True" : cout << "False";

    return 0;
}

 