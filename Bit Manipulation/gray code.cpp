// Leetcode 89

// An n-bit gray code sequence is a sequence of 2n integers where:
// Every integer is in the inclusive range [0, 2n - 1],
// The first integer is 0,
// An integer appears no more than once in the sequence,
// The binary representation of every pair of adjacent integers differs by exactly one bit, and
// The binary representation of the first and last integers differs by exactly one bit.
// Given an integer n, return any valid n-bit gray code sequence.

/*
Input: n = 2
Output: [0,1,3,2] OR [0,2,3,1]
Explanation:
The binary representation of [0,1,3,2] is [00,01,11,10].
- 00 and 01 differ by one bit
- 01 and 11 differ by one bit
- 11 and 10 differ by one bit
- 10 and 00 differ by one bit
*/

// LOGIC: 
// gray = i ^ (i >> 1)  

// Example: n = 2
// i	Binary	 i>>1	Gray = i^(i>>1)	    Binary
// 0	00	     00	    00	                  0
// 1	01	     00	    01	                  1
// 2	10	     01	    11	                  3
// 3	11	     01	    10	                  2

#include <iostream>
#include <vector>
using namespace std;

vector<int> grayCode(int n) {
    vector<int> ans;

    int total = 1 << n; // 2^n

    for(int i = 0; i < total; i++) {
        ans.push_back(i ^ (i >> 1)); // generates a seq where adjacent numbers differ by exactly one bit
    }

    return ans;
}

// TC = O(2^n)
// SC = O(2^n)