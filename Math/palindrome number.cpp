// Leetcode 9

// Given an integer x, return true if x is a palindrome, and false otherwise.

/*
Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.

Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
*/

#include <iostream>
using namespace std;

int reverse(int n) {
    int reverseNum = 0;

    while(n != 0) {
        int digit = n % 10;
        reverseNum = (reverseNum*10) + digit;
        n = n/10;
    }
    return reverseNum;
}

bool isPalindrome(int n) {
    if(n < 0) return false; // as -ve number can never be a palindrome

    int rev = reverse(n);

    return (n == rev); // if both are equal it returns true i.e, is a palindrome, else returns false

}

int main() {
    int n = 353;
    cout << isPalindrome(n) << endl;

    return 0;
}

// TC = O(d) = O(log n) , where d = no. of digits in 'n'