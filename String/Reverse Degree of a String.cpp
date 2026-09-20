// LeetCode 3498

// Given a string s, calculate its reverse degree. The reverse degree is calculated as follows:
// For each character, multiply its position in the reversed alphabet ('a' = 26, 'b' = 25, ..., 'z' = 1) with its position in the string (1-indexed).
// Sum these products for all characters in the string. Return the reverse degree of s.

/*
Input: s = "abc"
Output: 148
Explanation:
Letter	Index_in_Reversed_Alphabet	Index_in_String	  Product
'a'	    26	                        1	              26
'b'	    25	                        2	              50
'c'	    24	                        3	              72
The reversed degree is 26 + 50 + 72 = 148.
*/

#include <iostream>
using namespace std;

int reverseDegree(string s) {
    int sum = 0;

    for(int i = 0; i < s.length(); i++) {
        int revPos = 'z' - s[i] + 1; // calc position of char in reversed alphabet

        int currPos = i + 1; // position of char in string (1-based index, hence added +1)

        sum += currPos * revPos;
    }
    return sum;
}

int main() {
    string s ="abc";

    cout << reverseDegree(s);

    return 0;
}

// TC = O(n)
// SC = O(1)