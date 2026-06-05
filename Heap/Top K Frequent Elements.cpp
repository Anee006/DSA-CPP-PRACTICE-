// LeetCode 347

// Given an integer array nums and an integer k, return the k most frequent elements. You may return the ans in any order.

// Input: nums = [1,1,1,2,2,3], k = 2
// Output: [1,2]

// LOGIC:
// count freq of each element using hash map.
// use a max heap to keep elements ordered by freq.
// extract top k el.

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> freq;

    for(int num : nums) freq[num]++;  // count freq

    priority_queue<pair<int, int>> pq; // max heap to store {freq, num}

    // store el in max heap
    for(auto i : freq) {
        pq.push({i.second, i.first});
    }

    // extract top k el
    vector<int> res;

    for(int i=0; i<k; i++) {
        res.push_back(pq.top().second);
        pq.pop();
    }

    return res;
}

int main() {
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;

    vector<int> res = topKFrequent(nums, k);

    for(int val : res) cout << val << " ";

    return 0;
}

// TC = O(n + m log m) , m = number of distinct elements
// SC = O(m)