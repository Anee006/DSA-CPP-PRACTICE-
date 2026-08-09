// LeetCode 14
// solved using horizontal scan

// Write a function to find the longest common prefix string amongst an array of strings.
// If there is no common prefix, return an empty string "".

/*
Input: strs = ["flower","flow","flight"]
Output: "fl"
Explanation: 
- prefix = "flower". Compare with "flow". "flower" is too long, so reduce it: "flowe" --> "flow"
- Now: prefix = "flow". Compare "flow" with "flight". Again reduce: "flo" --> "fl"
- Now "fl" is common to all strings. So, answer: "fl"
*/

// LOGIC:
// Use the first string in the array as prefix and keep reducing it until every other string starts with it.
// If array is empty, return empty string.
// Take first string as intial prefix. Set: prefix = strs[0]
// Then compare it with every other string.
// While the current string does not start with prefix, remove the last character from prefix.
// If prefix becomes empty, return "".

#include <iostream>
#include <vector>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    if(strs.empty()) return "";

    string prefix = strs[0]; // start with 1st string as the prefix

    // compare prefix with every other string
    for(int i = 1; i < strs.size(); i++) {
        // keep reducing prefix until it matches beginning of strs[i]
        // find() tells where prefix occurs in strs[i]
        while(strs[i].find(prefix) != 0) { // means "prefix is not currently a prefix of this string"
            prefix.pop_back();

            if(prefix.empty()) return ""; // no common prefix
        }
    }
    return prefix;
}

int main() {
    vector<string> strs = {"flower", "flow", "flight"};

    cout << longestCommonPrefix(strs);

    return 0;
}

// TC = O(N * M) where, where N = number of strings, M = length of the shortest string
// SC = O(M)