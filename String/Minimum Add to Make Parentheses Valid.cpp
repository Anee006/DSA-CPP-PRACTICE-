// LeetCode 921

// A parentheses string is valid if and only if:
// It is the empty string, It can be written as AB (A concatenated with B), where A and B are valid strings, or It can be written as (A), 
// where A is a valid string. You are given a parentheses string s. In one move, you can insert a parenthesis at any position of the string.
// Return the minimum number of moves required to make s valid.

/*
Input: s = "()))"
Output: 2
Explanation:
( -> balance = 1
) -> balance = 0
) -> no '(' available → insertions = 1
) -> no '(' available → insertions = 2
So the answer is: 2
*/

// LOGIC:
// Count unmatched closing parentheses and unmatched opening parentheses.
// balance -> number of unmatched '(' currently available.
// insertions -> number of parentheses we need to insert.
// For every character: If it is '(' -> balance++;
// If it is ')' : If there is an unmatched '(', match it -> balance--. Otherwise, this ')' needs an inserted '(' -> insertions++
// Finally, if balance is still greater than 0, those unmatched '(' each need a ')' -> insertions += balance

#include <iostream>
using namespace std;

int minAddToMakeValid(string s) {
    int balance = 0, insertions = 0;

    for(char ch : s) {
        if(ch == '(') balance++;

        else { // ch == ')'
            if(balance > 0) balance--;

            else insertions++;  // there is no matching '(' for ')'
        }
    }
    insertions += balance; // remaining '(' need ')'

    return insertions;
}
 
int main() {
    string s = "()))";

    cout << minAddToMakeValid(s);

    return 0;
}

// TC = O(n)
// SC = O(1)