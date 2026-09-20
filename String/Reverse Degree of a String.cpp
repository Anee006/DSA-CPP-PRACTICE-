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
}

int main() {
    string s ="abc";

    cout << reverseDegree(s);

    return 0;
}