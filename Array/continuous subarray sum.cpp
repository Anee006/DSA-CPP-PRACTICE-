// LeetCode 523
// using prefix sum + remainder 
// (same logic as subarray sums divisible by k)

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
    unordered_map<int, int> m; // stores (remainder, first idx where this remainder appeared)

    m[0] = -1; // helps detect subarrays starting from index 0.

    int prefixSum = 0;

    for(int i=0; i<nums.size(); i++) {
        prefixSum += nums[i];

        int remainder = prefixSum % k;

        // if remainder is -ve, convert it to +ve
        if(remainder < 0) {
            remainder += k;
        }

        // if remainder has appeared before
        if(m.find(remainder) != m.end()) {
            
            // check is subarray length is >= 2
            if(i - m[remainder] >= 2) {
                return true;
            }
            
            else {
                // store the 1st occurrence of the remainder
                m[remainder] = i;
            }
        }
    }
    return false; // if no valid subarray found
}

int main() {
    vector<int> nums = {23,2,6,4,7};
    int k = 6;

    if(checkSubarraySum(nums, k)) cout << "True";

    else cout << "False";

    return 0;
}

// TC = O(n) , SC = O(n)