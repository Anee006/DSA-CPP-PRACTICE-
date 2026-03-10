// LeetCode 350

// Given two integer arrays nums1 and nums2, return an array of their intersection. 
// Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.


// Input: nums1 = [1,2,2,1], nums2 = [2,2]
// Output: [2,2]

// LOGIC:
// as we need Intersection with duplicates -> use map (frequency)

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> freq; // stores el and its freq
    vector<int> result;

    for(int num : nums1) {
        freq[num]++; // finding freq of each el in arr1
    }

    for(int num : nums2) {
        if(freq[num] > 0) {
            result.push_back(num);
            freq[num]--;
        }
    }
    return result;
}

int main() {

    vector<int> nums1 = {1,2,2,1};
    vector<int> nums2 = {2,2};

    vector<int> result = intersect(nums1, nums2);

    for(int val : result) cout << val << " ";

    return 0;
}

// TC = O(n + m) --> both arrays traversed once
// SC = O(n)