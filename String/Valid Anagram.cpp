// LeetCode 242

// Given two strings s and t, return true if t is an anagram of s, and false otherwise.

/*
Input: s = "anagram", t = "nagaram"
Output: true
Explanation:
Both strings have identical frequencies
Character	Count
a	        3
n	        1
g	        1
r	        1
m	        1


Input: s = "rat", t = "car"
Output: false
Explanation:
Character 't' is missing, and 'c' is extra
"rat" -> r = 1, a = 1, t = 1
"car" -> c = 1, a = 1, r = 1
*/

// LOGIC:
// Two strings are anagrams if they contain exactly the same characters with the same frequencies.
// If the length of both strings are different, they can never be an anagram.
// Create a freq array of size 26 (as only lowercase letters are there).
// Traverse first string and increment frequency of each character.
// Traverse second string and decrement frequency of each character.
// Check every element of freq array. If, any value is not 0, return false. Else, return true.

#include <iostream>
#include <vector>
using namespace std;

bool isAnagram(string s, string t) {
    if(s.size() != t.size()) return false;

    vector<int> freq(26, 0); // each idx repr a letter. 'a' has idx = 0, 'b' has idx = 1 .... 'z' has idx = 25

    for(char ch : s) freq[ch - 'a']++; // count char of 1st str
    for(char ch : t) freq[ch - 'a']--; // remove char from 2nd str

    for(int count : freq) {
        if(count != 0) return false;
    }

    return true;
}

int main() {
    string s = "anagram";
    string t = "nagaram";

    isAnagram(s, t) ? cout << "True" : cout << "False";

    return 0;
}

// TC = O(n)
// SC = O(1)
