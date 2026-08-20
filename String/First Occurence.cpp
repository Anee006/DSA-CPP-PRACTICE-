// geeksforgeeks

// Using sliding window (brute force approach)

// Given two strings txt and pat, return the 0-based index of the first occurrence of the substring pat in txt. If pat is not found, return -1.

/*
Input: txt = "GeeksForGeeks", pat = "For"
Output: 5
Explanation: "For" is present as substring in "GeeksForGeeks" from index 5 (0 based indexing).
*/

// LOGIC:
// slide a window of size "m" (size of pat) over "n" (size of txt) and compare char one by one.

#include <iostream>
using namespace std;

int firstOccurence(string& txt, string& pat) {

}

int main() {
    string txt = "GeeksForGeeks";
    string pat = "For";
    
    cout << firstOccurence(txt, pat);

    return 0;
}


