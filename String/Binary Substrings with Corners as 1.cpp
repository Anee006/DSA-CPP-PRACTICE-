// geeksforgeeks

// Given a binary string s. You have to count the number of substrings that start and end with 1.

/*
Input: s = "01101"
Output: 3
Explanation: There are 3 substrings from the given string. They are "11", "101", "1101".
*/

// LOGIC:
// Using mathematical approach:
// If there are "m" total '1's in the string :Any pair of '1's (one starting and one ending) defines a unique valid substring.
// The number of ways to choose 2 distinct '1's is given by the combination formula: (m * (m-1)) / 2

#include <iostream>
using namespace std;

int binarySubstring(string& s) {
    long long count1 = 0;

    for(char c : s) {
        if(c == '1') count1++; // count total 1s in the str
    }

    return (count1 * (count1 - 1)) / 2; // number of substrings starting and ending with '1'
}

int main() {
    string s = "01101";
    
    cout << binarySubstring(s);

    return 0;
}

// TC = O(n)
// SC = O(1)