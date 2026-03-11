// LeetCode 476

// The complement of an integer is the integer you get when you flip all the 0's to 1's and all the 1's to 0's in its binary representation.

// Given an integer num, return its complement.

// Example:
/*
Input: num = 5
Output: 2
Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So output is 2.
*/

#include <iostream>
#include <vector>
using namespace std;

int findComplement(int n) {
    if(n == 0) return 1; // edge case

    // Create a mask with all bits = 1. For n = 5(101), mask will be 111
    int mask = 1;

    // Keep shifting mask left until it becomes greater than n --> helps identify how many bits are in n
    while (mask <= n)
    {
        mask = mask << 1; // shift left (i.e multiply by 2)
    }
    // now mask = 1000 (for n = 5)

    mask = mask - 1; // now mask = 111 (same no. of bits as n)

    // XOR n with mask to flip the bits
    int complement = n ^ mask;

    return complement;
}

int main() {
    int n = 5;

    cout << findComplement(n);

    return 0;
}

// TC = O(log n), SC = O(1)