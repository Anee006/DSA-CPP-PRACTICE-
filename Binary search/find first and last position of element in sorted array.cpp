// LeetCode 34

// Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
// If target is not found in the array, return [-1, -1].

/*
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
*/

// LOGIC:
// Find the first occurrence of target. Find the last occurrence of target.
// To find 1st occurrence: when nums[mid] == target -> ans = mid -> right = mid - 1 (continue searching left)
// To find last occurrence: when nums[mid] == target -> ans = mid -> left = mid + 1 (continue searching right)
// To get a slightly more optimized version, instead of using binary search twice, can use a boolean variable "findFirst".
// If findFirst == true --> means we are finding 1st occurrence else, we are finding last occurrence.

#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int>& nums, int target, bool findFirst) {
    int left = 0, right = nums.size() - 1;
    int ans = -1;

    while(left <= right) {
        int mid = left + (right - left)/2;

        if(nums[mid] == target) {
            ans = mid; // found the target

            if(findFirst) right = mid - 1; // finding 1st occurrence --> continue going left

            else left = mid + 1; // finding last occurrence --> continue going right
        }

        else if(nums[mid] < target) left = mid + 1; // move right

        else right = mid - 1; // move left
    }
    return ans;
}

vector<int> searchRange(vector<int>& nums, int target) {
    return {binarySearch(nums, target, true), binarySearch(nums, target, false)};
}

int main() {
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;

    vector<int> ans = searchRange(nums, target);

    for(int val : ans) cout << val << "  ";

    return 0;
}

// TC = O(log n)
// SC = O(1)