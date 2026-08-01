// LeetCode 217
// using sorting

// Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

/*
Input: nums = [1,2,3,1]
Output: true
Explanation: The element 1 occurs at the indices 0 and 3.
*/

// LOGIC:
// sort the array first. Any duplicate elements will be adjacent.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool containsDuplicate(vector<int>& nums) {
}

int main() {
    vector<int> nums = {1, 2, 3, 1};

    containsDuplicate(nums) ? cout << "True" : cout << "False";

    return 0;
}

// TC = O(n log n)
// SC = O(1)