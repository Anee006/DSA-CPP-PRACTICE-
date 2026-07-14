// Leetcode 856

// Given a balanced parentheses string s, return the score of the string.

// The score of a balanced parentheses string is based on the following rule:
// "()" has score 1.
// AB has score A + B, where A and B are balanced parentheses strings.
// (A) has score 2 * A, where A is a balanced parentheses string.
 
/*
Input: s = "()"
Output: 1

Input: s = "(())"
Output: 2
Explanation: 2 * 1 = 2

Input: s = "()()"
Output: 2
Explanation: 1 + 1 = 2
*/

// LOGIC:
// use stack to maintain scores --> top of stack stores score of current level
// '(' --> means we are entering a new level 
// ')' --> means we are closing that level

// STEPS:
// if '(' is encountered --> start new level --> push 0 as we haven't computed anything yet
// if ')' --> pop current level --> current = s.top() --> 2 cases can arise
// case 1: current level is empty i.e we just closed () --> score = 1
// case 2: current level already has score. Eg: (AB) --> current score = (A + B) so, new score = 2 * (A + B)
// add this score to previous level

#include <iostream>
#include <stack>
using namespace std;

int scoreOfParentheses(string str) {
    stack<int> s; // stores score
    s.push(0); // start new level

    for(char c : str) {
        if(c == '(') s.push(0);

        else {
            int current = s.top();
            s.pop();

            int score;

            if(current == 0) score = 1;

            else score = 2 * current;

            s.top() += score; // because adjacent balanced strings add --> AB = A + B
        }
    }
    return s.top();
}

int main(){
    string str = "(())";

    cout << scoreOfParentheses(str);

    return 0;
}

// TC = O(n) , where n = length of string
// SC = O(n)