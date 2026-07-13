// Leetcode 678

// Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.

// The following rules define a valid string:
// Any left parenthesis '(' must have a corresponding right parenthesis ')'.
// Any right parenthesis ')' must have a corresponding left parenthesis '('.
// Left parenthesis '(' must go before the corresponding right parenthesis ')'.
// '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".

/*
Input: s = "()"
Output: true

Input: s = "(*)"
Output: true

Input: s = "(*))"
Output: true
*/

// LOGIC:
// Three possibilities for "*" are:
// 1. It can become '(' --> which increases opens --> high++
// 2. ')' --> which decreases opens --> low--
// 3. nothing --> ""


#include <iostream>
#include <stack>
using namespace std;

bool checkValidString(string s) {
    int low = 0; // minimum possible open brackets
    int high = 0; // maximum possible open brackets

    for(char c : s) {
        if(c == '(') { // it creates one unmatched '(' --> open brackets increase
            low++;
            high++;
        }

        else if(c == ')') { // it closes one '(' --> open brackets decrease
            low--;
            high--;
        }

        else { // "*" case --> possible open brackets can be 0 or 1 --> low = 0, high = 1
            low--;
            high++;
        }

        if(high < 0) return false; // even if every previous * became '(', we still have too many ')'

        low = max(0, low); // negative unmatched brackets don't make sense
    }
    return low == 0;
}

int main() {
    string s = "(*)";

    if(checkValidString(s)) cout << "True";
    else cout << "False";

    return 0;
}

// TC = O(n) 
// SC = O(1)