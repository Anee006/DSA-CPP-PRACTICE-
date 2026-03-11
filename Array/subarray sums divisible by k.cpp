// LeetCode 974
// using prefix sum + remainder 

// Given an integer array nums and an integer k, return the number of non-empty subarrays that have a sum divisible by k.
// A subarray is a contiguous part of an array.

// Example:
/*
Input: nums = [4,5,0,-2,-3,1], k = 5
Output: 7
Explanation: There are 7 subarrays with a sum divisible by k = 5:
[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]
*/

// LOGIC:
// If 2 prefix sums have the same Count when divided by k, then subarray b/w them is divisible by k.
// If (prefix[i] % k = prefix[j] % k) then (prefix[j] - prefix[i]) % k = 0
// so subarray (i+1...j) has sum divisible by k

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int subarraysDivByK(vector<int>& nums, int k) {
    unordered_map<int, int> remainderCount; // map stores freq of remainders --> (remainder, count)

    remainderCount[0] = 1; // handles subarrays starting from index 0

    int prefixSum = 0, result = 0;

    for(int i=0; i<nums.size(); i++) {
        prefixSum += nums[i]; // update prefix sum

        int remainder = prefixSum % k; // find Count of prefix sum with k

        if(remainder < 0) { // handle -ve Count cases
            remainder += k; 
        }

        // if remainder appeared before, means there exists subarrays divisible by k
        if(remainderCount.find(remainder) != remainderCount.end()) {
            result += remainderCount[remainder]; // add how many times this remainder appeared
        }
        remainderCount[remainder]++;
    }
    return result;
}

int main() {
    vector<int> nums = {4,5,0,-2,-3,1};
    int k = 5;

    cout << subarraysDivByK(nums, k);

    return 0;
}

// TC = O(n) , SC = O(n)