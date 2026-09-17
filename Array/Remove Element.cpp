// LeetCode 27
// using 1 pointer method

// Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The order of the elements may be changed. 
// Then return the number of elements in nums which are not equal to val.
// Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the following things:
// Change the array nums such that the first k elements of nums contain the elements which are not equal to val. 
// The remaining elements of nums are not important as well as the size of nums. Return k.

/*
Input: nums = [3,2,2,3], val = 3
Output: 2, nums = [2,2,_,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 2.
It does not matter what you leave beyond the returned k (hence they are underscores).
*/

#include <iostream>
#include <vector>
using namespace std;

int removeElement(vector<int>& nums, int val) {
    int k = 0; // keeps track of where to put the next element that is not equal to val

    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] != val) {
            nums[k] = nums[i];
            k++;
        }
    }
    return k;
}

int main() {
    vector<int> nums = {3, 2, 2, 3};
    int val = 3;

    int k = removeElement(nums, val);

    cout << "k = " << k << endl;

    cout << "\nFirst " << k << " elements of array are: ";

    for(int i = 0; i < k; i++) cout << nums[i] << " ";

    return 0;
}

// TC = O(n)
// SC = O(1)