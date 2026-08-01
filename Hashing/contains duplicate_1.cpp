// LeetCode 217
// using hash set

// Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

/*
Input: nums = [1,2,3,1]
Output: true
Explanation: The element 1 occurs at the indices 0 and 3.
*/

// LOGIC:
// if curr no. is already in the set -> found the duplicate -> return true. Otherwise, insert it into set.
// If loop is finished without finding any duplicates, return false

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool containsDuplicate(vector<int>& nums) {
}

int main() {
    vector<int> nums = {1, 2, 3, 1};

    containsDuplicate(nums) ? cout << "True" : cout << "False";

    return 0;
}

// TC = O(n)
// SC = O(n)