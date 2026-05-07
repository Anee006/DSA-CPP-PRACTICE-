// LeetCode 1456
// Using fixed sliding window

// Given a string s and an integer k, return the maximum number of vowel letters in any substring of s with length k.
// Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.
// s consists of lowercase English letters.

// Input: s = "abciiidef", k = 3
// Output: 3
// Explanation: The substring "iii" contains 3 vowel letters.

#include <iostream>
#include <string>
using namespace std;

// to check if char is a vowel
bool isVowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int maxVowels(string s, int k) {
    int count = 0;

    // count vowels in 1st window
    for(int i=0; i<k; i++) {
        if(isVowel(s[i])) count++;
    }

    int maxCount = count;

    // sliding window
    for(int i = k; i < s.length(); i++) {
        // remove left char
        if(isVowel(s[i-k])) count--;

        // add right char
        if(isVowel(s[i])) count++;

        maxCount = max(maxCount, count);
    }
    return maxCount;
}

int main() {
    string s = "abciiidef";
    int k = 3;

    cout << "Max no. of vowels: " << maxVowels(s, k);
    return 0;
}

// TC = O(n), SC = O(1)