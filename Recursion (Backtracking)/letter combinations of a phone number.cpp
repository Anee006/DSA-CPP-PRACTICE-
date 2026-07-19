// Leetcode 17

// Given a string containing digits from 2-9 inclusive, return all possible letter combinations (just like in a telephone) that the number could represent. 
// Return the answer in any order. Note that 1 does not map to any letters.

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

vector<string> letterCombinations(string digits) {
}

int main() {
    string digits = "23";

    vector<string> combination = letterCombinations(digits);

    for(string val : combination) cout << val << " , ";

    return 0;
}