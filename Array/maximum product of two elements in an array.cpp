// LeetCode 1464

// Given the array of integers nums, you will choose two different indices i and j of that array. 
// Return the maximum value of (nums[i]-1)*(nums[j]-1).

/*
Input: nums = [3,4,5,2]
Output: 12 
Explanation: If you choose the indices i=1 and j=2 (indexed from 0), you will get the maximum value, that is, 
(nums[1]-1)*(nums[2]-1) = (4-1)*(5-1) = 3*4 = 12. 
*/

// LOGIC:
// find the largest element: max1 and 2nd largest element max2.
// return (max1 - 1) * (max2 - 1)

#include <iostream>
#include <vector>
using namespace std;

int maxProduct(vector<int>& nums) {
    int max1 = 0, max2 = 0;

    for(int num : nums) {
        if(num > max1) {
            max2 = max1;
            max1 = num;
        }

        else if(num > max2) max2 = num;
    }

    return (max1 - 1) * (max2 - 1);
}

int main() {
    vector<int> nums = {3, 4, 5, 2};

    cout << maxProduct(nums);

    return 0;
}

// TC = O(n)
// SC = O(1)