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


#include <iostream>
#include <vector>
using namespace std;

vector<string> generateParentheses(int n) {

}

int main() {

    vector<string> ans = generateParentheses(1);
    for(string val : ans) cout << val << endl;

    ans = generateParentheses(3);
    for(string val : ans) cout << val << endl;

    return 0;
}