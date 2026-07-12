// Leetcode 32

// Given a string containing just the characters '(' and ')', return the length of the longest valid parentheses substring.

// Input: s = ")()())"
// Output: 4
// Explanation: The longest valid parentheses substring is "()()"

// LOGIC:
// Store the indices of char in the stack (as we need to find the length)
// If '(' --> push its idx in stack
// If ')' --> pop one element. If stack becomes empty --> push the curr index
// Else, ans = i - stack.top()

#include <iostream>
#include <stack>
using namespace std;

int longestValidParentheses(string str) {
    stack<int> s;
    s.push(-1);

    int ans = 0;

    for(int i = 0; i < str.size(); i++) {
        if(str[i] == '(') s.push(i);

        else {
            s.pop();

            if(s.empty()) s.push(i);

            else ans = i - s.top(); // length of valid parentheses
        }
    }
    return ans;
}

int main() {
    string str = ")()())";

    cout << longestValidParentheses(str);

    return 0;
}

// TC = O(n)
// SC = O(n)