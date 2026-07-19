// Leetcode 17

// Given a string containing digits from 2-9 inclusive, return all possible letter combinations (just like in a telephone) that the number 
// could represent. Return the answer in any order. Note that 1 does not map to any letters.

// Phone keypad mapping:
// 2 → abc
// 3 → def
// 4 → ghi
// 5 → jkl
// 6 → mno
// 7 → pqrs
// 8 → tuv
// 9 → wxyz

/*
Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

Explanation:
Digit 2 can be -> 'a', 'b', 'c'
Digit 3 can be -> 'd', 'e', 'f'
Possible combinations are -> "ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"
*/

// LOGIC:
// generate all possible combinations by trying every valid letter for each digit

#include <iostream>
#include <vector>
using namespace std;

vector<string> ans; // stores all final combinations

vector<string> mapping = { // mapping of digits to their corresponding letters on a phone keypad. Here index = digit
    "",     // 0
    "",     // 1
    "abc",  // 2 --> mapping[2] = "abc"
    "def",  // 3
    "ghi",  // 4
    "jkl",  // 5
    "mno",  // 6
    "pqrs", // 7
    "tuv",  // 8
    "wxyz"  // 9
};

void solve(int idx, string& digits, string& current) { // recursive fn
    if(idx == digits.size()) { // if processed each digit
        ans.push_back(current);
        return;
    }

    string letters = mapping[digits[idx] - '0']; // digits[idx] - '0' converts char to an int (so that there is a valid index)

    for(char ch : letters) { // try every possible letter for the current digit
        current.push_back(ch);

        solve(idx + 1, digits, current); // move to next digit

        current.pop_back(); // backtrack
    }
}

vector<string> letterCombinations(string digits) {
    if(digits.empty()) return {}; // there are no possible combinations

    string current;

    solve(0, digits, current);

    return ans;
}

int main() {
    string digits = "23";

    vector<string> combination = letterCombinations(digits);

    for(string val : combination) cout << val << " , ";

    return 0;
}

// TC = O(4^n * n) , where n = no. of digits (length of combination)
// Each digit has at most 4 letters (in case of 7 and 9). There can be up to 4^n combinations.

// SC = O(n) (due to recursion stack)