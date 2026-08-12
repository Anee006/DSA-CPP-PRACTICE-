// LeetCode 2958
// Using hash map + sliding window

// You are given an integer array nums and an integer k.
// The frequency of an element x is the number of times it occurs in an array.
// An array is called good if the frequency of each element in this array is less than or equal to k.
// Return the length of the longest good subarray of nums.

/*
Input: nums = [1,2,3,1,2,3,1,2], k = 2
Output: 6
Explanation: The longest possible good subarray is [1,2,3,1,2,3] since the values 1, 2, and 3 occur at most twice in this subarray. 
Note that the subarrays [2,3,1,2,3,1] and [3,1,2,3,1,2] are also good.
*/

// LOGIC:
// left -> stores start of the current window, right -> expands the window. freq[x] -> number of times x occurs in the current window.
// Whenever adding nums[right] makes its frequency greater than k, the window becomes invalid. 
// Move left forward until the frequency becomes valid again.

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int maxSubarrayLength(vector<int>& nums, int k) {
    int ans = 0, left = 0;

    unordered_map<int, int> freq;

    for(int right = 0; right < nums.size(); right++) {
        freq[nums[right]]++;

        while(freq[nums[right]] > k)  { // shrink window if freq exceeds k (move left forward)
            freq[nums[left]]--;
            left++;
        }

        ans = max(ans, right - left + 1); // (right - left + 1) means current window is good
    }
    return ans;
}

int main() {
    vector<int> nums = {1, 2, 3, 1, 2, 3, 1, 2};
    int k = 2;

    cout << maxSubarrayLength(nums, k);

    return 0;
}

// TC = O(n)
// SC = O(n)