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
    int left = 0;
    int right = nums.size();

    while(left < right) {
        int mid = left + (right-left) / 2;

        if(nums[mid] < target) left = mid + 1; // target must be in right half

        else right = mid; // nums[mid] could be the ans
    }
    return left; // left represents the 1st position where the value is greater than or equal to target
}

int main() {
    vector<int> nums = {1, 3, 5, 6};
    int target = 2;

    cout << searchInsert(nums, target);

    return 0;
}

// TC = O(log n) , where n = no. of elements
// SC = O(1)