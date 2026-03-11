// LeetCode 523

// Given an integer array nums and an integer k, return true if nums has a good subarray or false otherwise.
// A good subarray is a subarray where: its length is at least two, and the sum of the elements of the subarray is a multiple of k.

// Note that:
// A subarray is a contiguous part of the array.
// An integer x is a multiple of k if there exists an integer n such that x = n * k. 0 is always a multiple of k.

// Example:
/* 
Input: nums = [23,2,6,4,7], k = 6
Output: true
Explanation: [23, 2, 6, 4, 7] is an continuous subarray of size 5 whose elements sum up to 42.
42 is a multiple of 6 because 42 = 7 * 6 and 7 is an integer.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool checkSubarraySum(vector<int>& nums, int k) {
        
}

int main() {
    vector<int> nums = {23,2,6,4,7};
    int k = 6;

    if(checkSubarraySum(nums, k)) cout << "True";

    else cout << "False";

    return 0;
}