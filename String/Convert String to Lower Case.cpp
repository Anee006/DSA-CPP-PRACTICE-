// geeksforgeeks

// Given a string s. The task is to convert string characters to lowercase.

/*
Input: s = "ABCddE"
Output: "abcdde"
Explanation: A, B, C and E are converted to a, b, c and e thus all uppercase characters of the string converted to lowercase letter.
*/

#include <iostream>
using namespace std;

string toLower(string& s) {
    for(char& c : s) { // pass by reference so that original string is modified
        c = tolower(c); // inbuilt fn to convert str to lower case
    }

    return s; // modified string
}

int main() {
    string s = "ABCddE";

    cout << toLower(s);

    return 0;
}

// TC = O(n) , where n = s.length()
// SC = O(1)