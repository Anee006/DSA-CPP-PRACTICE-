// LeetCode 347

// Given an integer array nums and an integer k, return the k most frequent elements. You may return the ans in any order.

// Input: nums = [1,1,1,2,2,3], k = 2
// Output: [1,2]

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
        
}

int main() {
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;

    vector<int> res = topKFrequent(nums, k);

    for(int val : res) cout << val << " ";

    return 0;
}