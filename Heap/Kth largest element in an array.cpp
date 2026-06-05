// LeetCode 215

// Given an integer array nums and an integer k, return the kth largest element in the array.
// Note that it is the kth largest element in the sorted order, not the kth distinct element.

// Input: nums = [3,2,1,5,6,4], k = 2
// Output: 5
// Explanation: 
// nums in sorted order = [1, 2, 3, 4, 5, 6]
// 1st largest el = 6
// 2nd largest el = 5 --> ANS

#include <iostream>
#include <vector>
using namespace std;

int findKthLargest(vector<int>& nums, int k) {
        
}

int main() {
    vector<int> nums = {3,2,1,5,6,4};
    int k = 2;

    cout << findKthLargest(nums, k);

    return 0;
}