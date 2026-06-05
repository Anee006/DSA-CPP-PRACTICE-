// #newnotes
// LeetCode 128

// Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
// the consecutive numbers can be in any order.

// Input: nums = [100,4,200,1,3,2]
// Output: 4
// Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

// LOGIC:
// insert all numbers into a hash set (unordered_set).
// for each num, check if it is a start of a sequence. A num is a start, if (num-1) is not present.
// if it is a start, count how long the seq continues (num+1, num+2, ...)
// keep track of the max length found.

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int longestConsecutive(vector<int>& nums) {
    unordered_set<int> s(nums.begin(), nums.end());

    int longest = 0;

    for(int num : s) {

        // check if this is start of the seq
        if(s.find(num-1) == s.end()) {
            int currNum = num;
            int currLen = 1;

            // check how long the seq continues
            while(s.find(currNum + 1) != s.end()) {
                currNum++;
                currLen++;
            }

            longest = max(longest, currLen);
        }
    }
    return longest;
}

int main() {
    vector<int> nums = {100,4,200,1,3,2};

    cout << longestConsecutive(nums);

    return 0;
}

// TC = O(n)
// SC = O(n)  --> hash set stores all unique elements