// LeetCode 724
// using prefix sum

// Given an array of integers nums, calculate the pivot index of this array.
// pivot idx is the idx where the sum of all the numbers strictly to the left of the idx is equal to the sum of all the numbers 
// strictly to the index's right. If the index is on the left edge of the array, then the left sum is 0 because there are no 
// elements to the left. This also applies to the right edge of the array.
// Return the leftmost pivot index. If no such index exists, return -1.

// Input: nums = [1,7,3,6,5,6]
// Output: 3
// Explanation: The pivot index is 3.
// Left sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11
// Right sum = nums[4] + nums[5] = 5 + 6 = 11

// LOGIC:
// find total sum of array
// leftSum = sum before current idx, rightSum = totalSum - leftSum - currentElement
// if both are equal --> return index.

#include <iostream>
#include <vector>
using namespace std;

int pivotIndex(vector<int>& nums) {
    int totalSum = 0;

    // find total sum of arr
    for(int num : nums) totalSum += num;

    int leftSum = 0;

    for(int i = 0; i < nums.size(); i++) {
        int rightSum = totalSum - leftSum - nums[i];

        if(leftSum == rightSum) return i; // found pivot idx

        leftSum += nums[i]; // update left sum
    }
    return -1; // no pivot idx exists
}

int main() {
    vector<int> nums = {1,7,3,6,5,6};

    cout << "Pivot index: " << pivotIndex(nums);
    return 0;
}

// TC = O(n) , SC = O(1)