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
    int n = txt.length();
    int m = pat.length();

    if(m == 0) return 0; // empty pattern is found at idx = 0

    if(m > n) return -1; // pattern longer than txt is invalid

    for(int i = 0; i < n-m; i++) {
        int j = 0; // slides over pat

        while(j < m && txt[i+j] == pat[j]) j++; // check char match

        if(j == m) return i; // if full pat is matched
    }

    return -1;
}

int main() {
    string txt = "GeeksForGeeks";
    string pat = "For";
    
    cout << firstOccurence(txt, pat);

    return 0;
}

// TC = O((N - M + 1) x M)
// SC = O(1)
