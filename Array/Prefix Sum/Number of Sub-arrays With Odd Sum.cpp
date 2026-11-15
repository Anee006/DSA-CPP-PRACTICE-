// LeetCode 1524
// Using prefix sum parity

// Given an array of integers arr, return the number of subarrays with an odd sum. Since the answer can be very large, return it modulo 109 + 7.

/*
Input: arr = [1,3,5]
Output: 4
Explanation: All subarrays are [[1],[1,3],[1,3,5],[3],[3,5],[5]]. All sub-arrays sum are [1,4,9,3,8,5]. Odd sums are [1,9,3,5] so the answer is 4.
*/

// LOGIC:
// Maintain two counts: even = number of even prefix sums, odd = number of odd prefix sums.
// Calculate the running prefix sum. If the prefix sum is even, add odd to the answer. If the prefix sum is odd, add even to the answer.
// Update the corresponding count.

// WHY THIS APPROACH WORKS?
// The sum of a subarray is: SubarraySum = PrefixSum[j] - PrefixSum[i-1]
// For the subarray sum to be odd, one prefix sum must be even and the other must be odd.

#include <iostream>
#include <vector>
using namespace std;

int numOfSubarrays(vector<int>& arr) {
}

int main() {
    vector<int> arr = {1, 3, 5};

    cout << numOfSubarrays(arr);

    return 0;
}