// LeetCode 136

// Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

// Example:
// Input: nums = [4,1,2,1,2]
// Output: 4

// LOGIC:
// use BITWISE XOR operator
// Rules of BITWISE XOR:
// 0^0 = 0  //same, so cancels
// 1^1 = 0  //same, so cancels
// 0^1 = 1
// 1^0 = 1

// Given array: [4,1,2,1,2]
// Binary form of 2 is 10.
// so, 2^2 i.e, 10^10 = 0  (0^0 = 0 and  1^1 = 0)
// So, for a number "n",
// n^n = 0  and  n^0 = n


#include <iostream>
#include <vector>
using namespace std;

int singleNumber(vector<int>& nums) {
    int ans = 0;

    for(int val: nums) {
        ans ^= val;
    }
    return ans;
}

int main() {

    vector <int> nums= {4,1,2,1,2};
    cout << singleNumber(nums) << endl;

    return 0;
}

// TC = O(n)
// SC = O(1)