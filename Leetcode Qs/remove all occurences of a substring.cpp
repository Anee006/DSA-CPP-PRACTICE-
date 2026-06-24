// Leetcode 1910

// Given two strings 's' and 'part', perform the following operation on s until all occurrences of the substring part are removed:
// Find the leftmost occurrence of the substring part and remove it from s.
// Return s after removing all occurrences of part.
// A substring is a contiguous sequence of characters in a string.

/*
Input: s = "daabcbaabcbc", part = "abc"

Output: "dab"

Explanation: The following operations are done:
- s = "daabcbaabcbc", remove "abc" starting at index 2, so s = "dabaabcbc".
- s = "dabaabcbc", remove "abc" starting at index 4, so s = "dababc".
- s = "dababc", remove "abc" starting at index 3, so s = "dab".
Now s has no occurrences of "abc".
*/


// Functions that will be used in Q:
// str.find(substr) : This fn returns the starting position of the 1st occurence of substr, if it is found in the mainstring
// To check its validity use: str.find(substr) < str.length()

// str.erase( starting position from where u want to erase, length of substring you want to erase)
// so our starting pos will be: str.find(part) and length of substr is part.length() which we want to delete

#include <iostream>
#include <string>
using namespace std;

string removeOccurences(string s, string part) {
    while(s.length() > 0 && s.find(part) < s.length()) {
        s.erase(s.find(part), part.length()); // s.find(part) returns start pt of substr we need to erase, part.length() gives its len
    }
    return s;
}

int main() {
    string s = "daabcbaabcbc";
    string part = "abc";

    cout << removeOccurences(s,part) << endl;
    return 0;
}

// TC = O(n^2) , where n = length of string s