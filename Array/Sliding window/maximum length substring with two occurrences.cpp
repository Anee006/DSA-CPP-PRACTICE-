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
    unordered_map<char, int> freq; // {char, freq of char}
    
    int left = 0, maxLen = 0;

    for(int right = 0; right < s.size(); right++) {
        freq[s[right]]++; // increase count of char at idx right

        while(freq[s[right]] > 2) { // if a char occurs more than twice, shrink it from left
            freq[s[left]]--; // decrease the freq
            left++; // shrink window from left
        }

        maxLen = max(maxLen, right - left + 1); // (right - left + 1) is window length
    }
    return maxLen;
}

int main() {
    string s = "bcbbbcba";

    cout << maximumLengthSubstring(s);
    return 0;
}

// TC = O(n)
// SC = O(k) , where k is the no. of distinct characters