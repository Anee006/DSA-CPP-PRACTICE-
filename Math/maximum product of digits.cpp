// Leetcode 3536

// You are given a positive integer n. Return the maximum product of any two digits in n.
// Note: You may use the same digit twice if it appears more than once in n.

/*
Input: n = 22
Output: 4
Explanation:
The digits of n are [2, 2]. The possible products of any two digits are: 2 * 2 = 4. The maximum product is 4.

Input: n = 124
Output: 8
Explanation:
The digits of n are [1, 2, 4]. The possible products of any two digits are: 1 * 2 = 2, 1 * 4 = 4, 2 * 4 = 8.
The maximum product is 8.
*/

// LOGIC:
// Find the largest and second largest digits and return their product.
// If the largest digit appears more than once, both max1 and max2 will become that digit, 
// allowing the same digit value to be used twice (from different occurrences).

#include <iostream>
using namespace std;

int maxProduct(int n) {
    int max1 = -1, max2 = -1;

    while(n > 0) {
        int digit = n % 10; // extract each (last) digit from n 

        if(digit >= max1) {
            max2 = max1; // if the largest digit appears more than once, both max1 and max2 will become that digit
            max1 = digit; // this is the largest digit
        }

        else if(digit > max2) max2 = digit; // this is the 2nd largest digit

        n /= 10; // remove the last digit using
    }
    return max1 * max2;
}

int main() {
    int n = 124;

    cout << maxProduct(n);

    return 0;
}

// TC = O(d) , where d = no. of digits in 'n'
// SC = O(1)