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

#include <iostream>
using namespace std;

// expand around given center and return palindromic length
int expand(string& s, int left, int right) {
    while(left >= 0 && right < s.size() && s[left] == s[right]) {
        left--;
        right++;
    }

    return right - left - 1; // actual palindromic length (left and right have already moved one step outside the palindrome)
}

string longestPalindrome(string s) {
    if(s.empty()) return "";

    int start = 0, end = 0;

    for(int i = 0; i < s.size(); i++) {
        int len1 = expand(s, i , i); // odd-length palindrome
        int len2 = expand(s, i , i+1); // even-length palindrome

        int len = max(len1, len2);

        if(len > end - start + 1) { // update ans if longer palindrome is found
            start = i - (len - 1)/2;
            end = i + len/2;
        }
    }
    return s.substr(start, end - start + 1); // return substring from start to end
}

int main() {
    string s = "babad";

    cout << longestPalindrome(s);

    return 0;
}

// TC = O(n^2) , where there are n possible centers
// SC = O(1)