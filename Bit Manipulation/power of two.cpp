// LeetCode 231

// Given an integer n, return true if it is a power of two. Otherwise, return false.
// 1, 2, 4, 8 etc are powers of 2.

#include <iostream>
using namespace std;

bool isPowerOfTwo(int n) {
    return ((n & (n-1)) == 0); // if True --> n is a power of 2 
}

int main() {
    int n = 2;

    cout << isPowerOfTwo(n);
    return 0;
}

// TC = O(1) , SC = O(1)