// LeetCode 28

// Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

/*
Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.
*/

// LOGIC:
// Try every possible starting position in haystack.
// We only need to check starting positions from 0 to n-m, bcoz starting after n-m wouldn't leave enough characters for needle.
// For every possible starting index i: Compare needle[j] with haystack[i+j]. If all m characters match, return i.

#include <iostream>
using namespace std;

int strStr(string haystack, string needle) {
}

int main() {
    string haystack = "sadbutsad";
    string needle = "sad";

    cout << strStr(haystack, needle);

    return 0;
}