// Leetcode 402

// Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.

/*
Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
*/

// LOGIC:
// Build the no. from left to right.
// Eg: If we have 14 and next digit is 3, the smaller out of 143 and 13 is 13. So we should remove 4.
// Whenever the current digit is smaller than the previous digit, remove the previous digit (if still can)
// If nothing gets popped because digits are increasing, remove from the end.
// Eg: 1,2,3,4,5 and k = 2. So smallest no. that can be made = 123

// STEPS:
// For every digit, while: (stack is not empty) && (k > 0) && (top > current digit) --> Pop. Then push the current digit
// If k remains --> pop from the end
// build the ans. Remove leading zeros if any
// If answer becomes empty, return 0

#include <iostream>
#include <stack>
using namespace std;

string removeKdigits(string num, int k) {
        
}

int main() {
    string num = "1432219";
    int k = 3;

    cout << removeKdigits(num, k);

    return 0;
}