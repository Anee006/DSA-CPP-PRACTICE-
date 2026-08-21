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
}

int main() {
    string s = "ABCddE";

    cout << toLower(s);

    return 0;
}

// TC = O(n) , where n = s.length()
// SC = O(1)