// Generate Parentheses (LeetCode 22)

// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

/*
Example 1:
Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]

Example 2:
Input: n = 1
Output: ["()"]
*/

// LOGIC:
// We maintain: 
// open -> number of '(' used
// close -> number of ')' used

// Conditions:
// We can add '(' if open < N
// We can add ')' if close < open


#include <iostream>
#include <vector>
using namespace std;

void generate(int n, int open, int close, string curr, vector<string>& ans) {
    if(curr.length() == 2*n) {  // means we have generated all valid pairs of ()
        ans.push_back(curr);
        return;
    }

    if(open < n) {
        generate(n, open+1, close, curr + "(", ans); // add "("
    }
    
    if(close < open) {
        generate(n, open, close+1, curr + ")", ans); // add ")"
    }
}

vector<string> generateParentheses(int n) {
    vector<string> ans;

    generate(n, 0, 0, "", ans);

    return ans;
}

int main() {

    vector<string> ans = generateParentheses(1);
    for(string val : ans) cout << val << endl;

    cout << "\n\n";

    ans = generateParentheses(3);
    for(string val : ans) cout << val << endl;

    return 0;
}

// TC = O(2^n)
