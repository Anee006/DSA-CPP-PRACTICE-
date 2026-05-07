// LeetCode 3
// using variable sliding window

// Given a string s, find the length of the longest substring without duplicate characters.

// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.

// LOGIC:
// left --> start of current window
// right --> end of current window
// expand using right. If duplicate appears, move left just after the prev occurence of that char.

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> m; // stores last idx of characters
    
    int left = 0, maxLen = 0;

    for(int right = 0; right < s.length(); right++) {

        // if char already exists in the window
        if(m.find(s[right]) != m.end() && m[s[right]] >= left) {
            left = m[s[right]] + 1; // move left ptr
        }

        m[s[right]] = right; // update latest idx of char

        maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
}

int main() {
    string s = "abcabcbb";

    cout << "Longest Substring without duplicates: " << lengthOfLongestSubstring(s);
    return 0;
}

// TC = O(n) , SC = O(1)