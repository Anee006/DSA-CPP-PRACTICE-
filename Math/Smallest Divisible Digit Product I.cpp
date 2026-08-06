// LeetCode 3345

// You are given two integers n and t. Return the smallest number greater than or equal to n such that the product 
// of its digits is divisible by t.

/*
Input: n = 15, t = 3
Output: 16
Explanation:
The digit product of 16 is 6, which is divisible by 3, making it the smallest number greater than or equal to 15 
that satisfies the condition.
*/

// LOGIC:
// start with num == n. Compute product of digits. If (product % t == 0) return num. Otherwise, increment n.

#include <iostream>
using namespace std;

int smallestNumber(int n, int t) {
}

int main() {
    int n = 15, t = 3;

    cout << smallestNumber(n, t);

    return 0;
}

// TC = O((x − n + 1) × k) , where k = no. of digits


 