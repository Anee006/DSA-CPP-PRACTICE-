// Leetcode 1291
// Using Enumeration(Brute Force approach) --> most optimal

// An integer has sequential digits if and only if each digit in the number is one more than the previous digit.
// Return a sorted list of all the integers in the range [low, high] inclusive that have sequential digits.

// Input: low = 1000, high = 13000
// Output: [1234,2345,3456,4567,5678,6789,12345]

// NOTE: Use Enumeration as there are only 36 possible sequential-digit numbers in total, so generating all of them and filtering by range is optimal
// (2 digit --> 8 nums, 3 digit --> 7 nums, 4 digit --> 6 nums... 9 digit --> 1 num) => 8 + 7 + 6 + 5 + 4 + 3 + 2 + 1 = 36

// LOGIC:
// Every sequential number is a substring of "123456789"
// For given e.g, low = 1000, high = 13000. So, 1000 -> 4 digits , 13000 -> 5 digits
// For every length, generate every substring
// All 4-digit numbers: 1234, 2345, 3456, 4567, 5678, 6789
// All 5-digit numbers: 12345, 23456, 34567, 45678, 56789
// Check the range and keep the valid ones

#include<iostream>
#include<vector>
using namespace std;

vector<int> sequentialDigits(int low, int high) {
    string digits = "123456789";
    vector<int> ans;

    int minLen = to_string(low).size(); // number of digits in low
    int maxLen = to_string(high).size(); // number of digits in high

    for(int len = minLen; len <= maxLen; len++) {
        for(int i = 0; i + len <= 9; i++) {
            int num = stoi(digits.substr(i, len)); // string to int --> convert substring into int

            if(num >= low && num <= high) ans.push_back(num);
        }
    }
    return ans;
}

int main() {
    int low = 1000, high = 13000;

    vector<int> ans = sequentialDigits(low, high);

    for(int i : ans) cout << i << " , ";

    return 0;
}

// TC = O(1) , as we generate only 36 numbers
// SC = O(1) , ignoring the output vector