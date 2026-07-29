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

#include <iostream>
using namespace std;

bool isAnagram(string s, string t) {
}

int main() {
    string s = "anagram";
    string t = "nagaram";

    isAnagram(s, t) ? cout << "True" : cout << "False";

    return 0;
}

// TC = O(n)
// SC = O(1)
