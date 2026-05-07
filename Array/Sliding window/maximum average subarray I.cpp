// LeetCode 643
// Using Fixed Sliding Window (size = k)

// You are given an integer array nums consisting of n elements, and an integer k.
// Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value.

// Input: nums = [1,12,-5,-6,50,3], k = 4
// Output: 12.75000
// Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75

#include <iostream>
#include <vector>
using namespace std;

double findMaxAverage(vector<int>& nums, int k) {
    double windowSum = 0;

    // find sum of 1st window of size k
    for(int i=0; i<k; i++) {
        windowSum += nums[i];
    }

    double maxSum = windowSum;

    // slide the window
    for(int i = k; i < nums.size(); i++) {

        windowSum += nums[i] - nums[i-k]; // add next el & remove prev el
        maxSum = max(maxSum, windowSum);
    }
    return maxSum/k; // to find max avg
}

int main() {
    vector<int> nums = {1,12,-5,-6,50,3};
    int k = 4;

    cout << "Maximum average is: " << findMaxAverage(nums, k);
    return 0;
}

// TC = O(n), SC = O(1)