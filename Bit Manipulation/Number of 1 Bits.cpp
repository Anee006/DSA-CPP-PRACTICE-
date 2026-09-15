// LeetCode 191

// Given a positive integer n, write a function that returns the number of set bits in its binary representation (also known as the Hamming weight).

/*
Input: n = 11
Output: 3
Explanation:
The input binary string 1011 has a total of three set bits.

Working:
n = 11 = 1011 
n - 1 = 10 = 1010
1011 & 1010 = 1010 i.e 10
count = 1

n = 10 = 1010,  n-1 = 9 = 1001
1010 & 1001 = 1000 i.e 8
count = 2

n = 8 = 1000, n-1 = 7 = 0111
1000 & 0111 = 0
count = 3 

So, there are 3 set bits in 11.
*/

#include <iostream>
using namespace std;

int hammingWeight(int n) {
    int count = 0;

    while(n != 0) {
        n = n & (n-1);
        count++;
    }

    return count;
}

int main() {
    int n = 11;

    cout << hammingWeight(n);

    return 0;
}

// TC = O(k) , where k = no. of set bits in "n"
// SC = O(1)