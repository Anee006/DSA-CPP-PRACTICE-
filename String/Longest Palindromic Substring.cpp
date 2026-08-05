// LeetCode 5

// Given a string s, return the longest palindromic substring in s.

// Input: s = "babad"
// Output: "bab"
// Explanation: "aba" is also a valid answer.

// LOGIC:
// Using Expand Around Center approach
// palindrome grows around its center. If we know the center, we can keep expanding, while the char match.
// for odd-length palindrome, center is at (i, i). For even length-palindrome, center is at (i, i+1).
// for odd-length palindrome: left = right = i. For even-length palindrome: left = i, right = i+1.
// take the longer of the two lengths. If it is longer than curr ans, update "start" and "end".
// return substring from start to end

#include <iostream>
using namespace std;

string longestPalindrome(string s) {
}

int main() {
    string s = "babad";

    cout << longestPalindrome(s);

    return 0;
}