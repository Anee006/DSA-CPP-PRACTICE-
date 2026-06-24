// LeetCode 215

// Given an integer array nums and an integer k, return the kth largest element in the array.
// Note that it is the kth largest element in the sorted order, not the kth distinct element.

// Input: nums = [3,2,1,5,6,4], k = 2
// Output: 5
// Explanation: 
// nums in sorted order = [1, 2, 3, 4, 5, 6]
// 1st largest el = 6
// 2nd largest el = 5 --> ANS

// LOGIC:
// use min heap of size k to solve without using sorting.
// keep the largest k elements seen so far in a min-heap.
// if heap size exceeds k --> remove the smallest el from the heap.
// in the end, the el at root of the heap is the kth largest el.

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for(int num : nums) {
        minHeap.push(num);

        if(minHeap.size() > k ) minHeap.pop();
    }
    
    return minHeap.top();
}

int main() {
    vector<int> nums = {3,2,1,5,6,4};
    int k = 2;

    cout << findKthLargest(nums, k);

    return 0;
}

// TC = O(n * log(k)) where, n = no. of elements and k = req kth largest element
// SC = O(k)