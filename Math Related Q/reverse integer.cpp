// LeetCode 7

// Given a signed 32-bit integer x, return x with its digits reversed. 
// If reversing x causes the value to go outside the signed 32-bit integer range, then return 0.

#include <iostream>
using namespace std;

int reverse(int n) {
    int reverseNum = 0; 

    while(n != 0) {
        int digit = n % 10; // to get the digits of n

        //to check if our reversed num is out of range or not, acc to the given condition
        if(reverseNum > INT_MAX/10 || reverseNum < INT_MIN/10) return 0;

        // reverse the num 
        reverseNum = (reverseNum * 10) + digit; // due to this step reverseNum can go out of range, hence we put if condition before this
        
        n = n/10; // updation 
    }
    return reverseNum;
}

int main() {
    int n = 4537;
    cout << reverse(n) << endl;
    return 0;
}

// TC = O(log n)