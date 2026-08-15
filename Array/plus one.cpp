// LeetCode 66

// You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. 
// The digits are ordered from most significant to least significant in left-to-right order. 
// Increment the large integer by one and return the resulting array of digits.

/*
Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123. Incrementing by one gives 123 + 1 = 124. Thus, the result should be [1,2,4].

Input: digits = [9, 9]
Output: [1,0, 0]
Explanation: The array represents the integer 99. Incrementing by one gives 99 + 1 = 100. Thus, the result should be [1,0, 0].
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> plusOne(vector<int>& digits) {
    // start from the right-most digit (just like how we do in normal addition)
    for(int i = digits.size() - 1; i >= 0; i--) {

        if(digits[i] < 9) { // if curr digit < 9 --> increment it by 1
            digits[i]++; // increment the last digit
            return digits;
        }

        digits[i] = 0; // if curr digit = 9, it becomes 0 and carry moves to left (just like in normal addition)
    }

    // if we reach here, every digit was 9 (eg: 99 will become 100)
    digits.insert(digits.begin(), 1); // insert 1 at beginning (to make 99 as 100)

    return digits;
}

int main() {
    vector<int> digits = {1, 2, 3};

    vector<int> ans = plusOne(digits);

    for(int x : digits) cout << x << " ";

    return 0;
}

// TC = O(9)
// SC = O(1)
