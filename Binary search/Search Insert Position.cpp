// LeetCode 35
// Using lower-bound binary search pattern

// Given a sorted array of distinct integers and a target value, return the index if the target is found. 
// If not, return the index where it would be if it were inserted in order. You must write an algorithm with O(log n) runtime complexity.

/*
Input: nums = [1,3,5,6], target = 5
Output: 2

Input: nums = [1,3,5,6], target = 2
Output: 1
*/

// LOGIC:
// Use binary search (as arr is sorted). Binary search can keep track of the position where target should be inserted
// Search for the first position where nums[i] >= target.
// When loop ends (left == right). This position is where the target should be inserted.

#include <iostream>
#include <vector>
using namespace std;

int searchInsert(vector<int>& nums, int target) {
}

int main() {
    vector<int> nums = {1, 3, 5, 6};
    int target = 5;

    cout << searchInsert(nums, target);

    return 0;
}