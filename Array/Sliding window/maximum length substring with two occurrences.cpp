// LeetCode 3090
// using sliding window + hash map

// Given a string s, return the maximum length of a substring such that it contains at most two occurrences of each character.

/*
Input: s = "bcbbbcba"
Output: 4
Explanation:
The following substring "bcba" has a length of 4 and contains at most two occurrences of each character: "bcbbbcba".
*/

#include <iostream>
#include <unordered_map>
using namespace std;

int maximumLengthSubstring(string s) {
}

int main() {
    string s = "bcbbbcba";

    cout << maximumLengthSubstring(s);

    return 0;
}

// TC = O(n)
// SC = O(k) , where k is the no. of distinct characters