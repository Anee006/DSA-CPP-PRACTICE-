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

// Initialize max1 = -1 and max2 = -1.
// while n > 0:
// Extract each digit from n using: digit = n % 10
// If digit >= max1
// max2 = max1 (if the largest digit appears more than once, both max1 and max2 will become that digit)
// max1 = digit (this is the largest digit)
// Else if digit > max2
// max2 = digit (this is the second largest digit)
// Remove the last digit using: n /= 10
// Return max1 * max2 (required max product).

#include <iostream>
using namespace std;

int maxProduct(int n) {

}

int main() {
    int n = 124;

    cout << maxProduct(n);

    return 0;
}

// TC = O(d) , where d = no. of digits in 'n'
// SC = O(1)