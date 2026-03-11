// Longest Sum with subarray Sum N. (LeetCode 325)
// using hashing (prefix sum + hashmap)

// Find the length of the longest subarray whose sum equals k.

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int maxSubarrayLength(vector<int>& nums, int k) {
    unordered_map<int, int> m; // to store prefix sum, first idx where it appears
    int prefix = 0, ans = 0;

    // Prefix sum = 0 occurs at index -1 (before the array starts) --> helps detect subarrays that start from index 0.
    m[0] = -1;

    for(int i=0; i<nums.size(); i++) {
        prefix += nums[i]; // finding prefix sum

        // Check if a valid subarray exists:
        if(m.find(prefix - k) != m.end()) {
            ans = max(ans, i - m[prefix - k]); // update max length (Subarray length: current index - previous index)
        }

        // Store prefix sum if it is new
        if(m.find(prefix) == m.end()) {
            m[prefix] = i;
        }
    }
    return ans;
}

int main() {
    vector<int> nums = {1, -1, 5, -2, 3};
    int k = 3;

    cout << maxSubarrayLength(nums, k);

    return 0;
}