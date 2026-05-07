// LeetCode 3
// using variable sliding window

// Given a string s, find the length of the longest substring without duplicate characters.

// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int lengthOfLongestSubstring(string s) {
        
}

int main() {
    string s = "abcabcbb";

    cout << "Longest Substring without duplicates: " << lengthOfLongestSubstring(s);
    return 0;
}