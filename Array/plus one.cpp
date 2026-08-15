// LeetCode 66

// You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. 
// The digits are ordered from most significant to least significant in left-to-right order. 
// Increment the large integer by one and return the resulting array of digits.

/*
Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123. Incrementing by one gives 123 + 1 = 124. Thus, the result should be [1,2,4].

Input: digits = [9]
Output: [1,0]
Explanation: The array represents the integer 9. Incrementing by one gives 9 + 1 = 10. Thus, the result should be [1,0].
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> plusOne(vector<int>& digits) {
}

int main() {
    vector<int> digits = {1, 2, 3};

    vector<int> ans = plusOne(digits);

    for(int x : digits) cout << x << " ";

    return 0;
}

