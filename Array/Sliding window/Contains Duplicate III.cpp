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

// LOGIC:
// for indexDiff -> use sliding window
// for valueDiff -> use lower_bound() --> finds smallest val in set that is >= nums[i]
// At index i, window contains only: nums[i-indexDiff] ... nums[i-1] 
// So every element in window automatically satisfies: abs(i - j) <= indexDiff.
// nums[i] - valueDiff <= nums[j] <= nums[i] + valueDiff , which is exactly: abs(nums[i] - nums[j]) <= valueDiff

#include <iostream>
#include <set>
#include <vector>
using namespace std;

bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
    set<int> s;

    for(int i = 0; i < nums.size(); i++) {
        // remove elements that are outside indexDiff window
        if(i > indexDiff) s.erase(nums[i - indexDiff - 1]);

        // Find first number >= nums[i] - valueDiff
        auto it = s.lower_bound(nums[i] - valueDiff);

        // check if that num is <= nums[i] + valueDiff
        if(it != s.end() && *it <= nums[i] + valueDiff) return true;

        s.insert(nums[i]);
    }
    return false;
}

int main() {
    vector<int> nums = {1, 2, 3, 1};
    int indexDiff = 3, valueDiff = 0;

    containsNearbyAlmostDuplicate(nums, indexDiff, valueDiff) ? cout << "True" : cout << "False";

    return 0;
}

// TC = O(n log(indexDiff))
// SC = O(indexDiff)

 