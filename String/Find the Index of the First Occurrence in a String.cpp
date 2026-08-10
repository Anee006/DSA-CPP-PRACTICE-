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
    int n = haystack.size();
    int m = needle.size();

    if(m == 0) return 0; // empty needle is considered to be at idx 0

    if(m > n) return -1; // needle cannot fit inside haystack

    // "i" represents where search is starting in "haystack". "j" represents which char of "needle" is being currently checked
    for(int i = 0; i <= n-m; i++) { // try every possible starting position
        int j = 0;

        while(j < m && haystack[i+j] == needle[j]) j++; // compare characters

        if(j == m) return i; // entire needle matched
    }
    return -1;
}

int main() {
    string haystack = "sadbutsad";
    string needle = "sad";

    cout << strStr(haystack, needle);

    return 0;
}

// TC = O(n x m) , where n = length of haystack, m = length of needle
// SC = O(1)