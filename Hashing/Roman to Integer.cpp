// LeetCode 13

/*
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000

For example, 2 is written as II in Roman numeral, just two ones added together. 
12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.
Roman numerals are usually written largest to smallest from left to right.
However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five 
we subtract it making four. There are six instances where subtraction is used:
I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer.
*/

/*
Input: s = "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
*/

// LOGIC:
// Normally values are added (XII = 10 + 1 + 1 = 12).
// When a smaller val comes before a larger val -> E.g: IV is 5 - 1 = 4 and not 1 + 5 = 6.
// Store the value of every Roman symbol in a hash map.
// Traverse the string from left to right. For each character:
// If there is a next character and its value is larger, subtract the current value. Otherwise, add the current value.

#include <iostream>
#include <unordered_map>
using namespace std;

int romanToInt(string s) {
    unordered_map<char, int> m = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };

    int ans = 0;

    for(int i = 0; i < s.size(); i++) {
        if(i+1 < s.size() && m[s[i]] < m[s[i+1]]) { // if curr val is smaller than next val, subtract curr val
            ans -= m[s[i]];
        }

        else ans += m[s[i]];
    }
    return ans;
}

int main() {
    string s = "MCMXCIV";

    cout << romanToInt(s);

    return 0;
}

// TC = O(n)
// SC = O(1) (hashmap contains only 7 entries)