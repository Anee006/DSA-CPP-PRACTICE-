// LeetCode 1456
// Using fixed sliding window

// Given a string s and an integer k, return the maximum number of vowel letters in any substring of s with length k.
// Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.

// Input: s = "abciiidef", k = 3
// Output: 3
// Explanation: The substring "iii" contains 3 vowel letters.

#include <iostream>
#include <string>
using namespace std;

int maxVowels(string s, int k) {
        
}

int main() {
    string s = "abciiidef";
    int k = 3;

    cout << "Max no. of vowels: " << maxVowels(s, k);
    return 0;
}

// TC = O(n), SC = O(1)