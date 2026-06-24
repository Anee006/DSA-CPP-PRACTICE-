// Leetcode 151

// Given an input string s, reverse the order of the words.

// Input: s = "the sky is blue"
// Output: "blue is sky the"

// Note that s may contain leading or trailing spaces or multiple spaces between two words. 
// The returned string should only have a single space separating the words. Do not include any extra spaces.


// STEPS:
// 1. reverse the complete string. this will ensure that the words are reversed (ignore for now that the letters are also reversed)
// 2. reverse the individual words again, to get the letters in the correct order

#include <iostream>
#include <string>
#include <algorithm> 
using namespace std;

string reverseWords(string s) {
    int n = s.length(); 
    string ans = "";

    reverse(s.begin(), s.end()); // to reverse all the letters of the string
   
    for(int i=0; i<n; i++) {
        string word = "";

        // to identify a single word in a string. a word is anything that doesn't have space in it.
        while(i < n && s[i] != ' ') {
            word += s[i];
            i++;
        }

        reverse(word.begin(), word.end()); // to reverse an individual word

        // only add word to the ans if it is a valid word. won't add extra spaces into the ans
        if(word.length() > 0) ans += " " + word; // adding a space as we need to have a single space b/w all the words

        // as we are adding space in the beginning, we need to remove this space in the beginning after we got our ans
    }
    return ans.substr(1); // means it returns ans from the 1st index, hence the extra space in beginning is removed
}

int main()
{
    string s = "the sky is blue";

    cout << reverseWords(s) << endl;

    return 0;
}

// TC = O(n)