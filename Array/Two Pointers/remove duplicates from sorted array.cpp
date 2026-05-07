// LeetCode 26
// using 2 pointers (slow fast pointers)

// Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. 
// The relative order of the elements should be kept the same.
// Consider the number of unique elements in nums to be k​​​​​​​​​​​​​​. After removing duplicates, return the number of unique elements k.
// The first k elements of nums should contain the unique numbers in sorted order. The remaining elements beyond index k - 1 can be ignored.

// Input: nums = [1,1,2]
// Output: 2, nums = [1,2,_]

#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    // edge case: when array is empty
    if(nums.size() == 0) return 0;

    int slow = 0; // slow pointer --> it is the position to place unqiue el

    // fast pointer --> traverses the array
    for(int fast = 1; fast < nums.size(); fast++) {

        // if current el is different --> found a unique el
        if(nums[fast] != nums[slow]) {
            slow++;

            // place unique el at next position
            nums[slow] = nums[fast];
        }
    }
    return slow+1; // no. of unique elements
}

int main() {
    vector<int> nums = {1, 1, 2};
    int k = removeDuplicates(nums);

    cout << "Number of unique elements: " << k << endl;
    cout << "\nArray after removing duplicates:\n";

    for(int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }

    return 0;
}