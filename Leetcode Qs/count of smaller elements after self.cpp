// Count of Smaller Numbers After Self (LeetCode 315)
// using Divide and Conquer Approach (uses modified Merge Sort)

// Given an integer array nums, return an integer array counts where counts[i] is the number of smaller elements to the right of nums[i].

/* 
Input: nums = [5,2,6,1]
Output: [2,1,1,0]
Explanation:
To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.

Example 2:
Input: nums = [-1]
Output: [0]
*/

// LOGIC:
// While merging: If an element from the left half is greater than an element from the right half, then all remaining elements in the right half are smaller.
// We count how many elements from the right side move before each left element.

#include <iostream>
#include <vector>
using namespace std;

vector<int> countSmaller(vector<int>& nums) {

}

int main() {
    vector<int> nums = {5, 2, 6, 1};

    vector<int> ans = countSmaller(nums);

    for(int val : ans) cout << val << " ";

    return 0;
}

// TC = O(n logn)