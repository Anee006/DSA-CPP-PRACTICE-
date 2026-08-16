// LeetCode 43

// Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.
// Note: You must not use any built-in BigInteger library or convert the inputs to integer directly. (can't use stoi() or to_string()).

// Input: num1 = "123", num2 = "456"
// Output: "56088"

// LOGIC:
// We can't directly convert strings to int bcoz they may contain numbers much larger than "int" or "long long" can handle.
// Multiply individual digits because each character represents one digit.
// int n1 = num1[i] - '0' --> If, num1[i] == '7' then, '7' - '0' = 7
// String number -> Take individual digits -> Multiply digits -> Store in result array -> Handle carry -> Convert result array to string

#include <iostream>
#include <vector>
using namespace std;

string multiply(string num1, string num2) {
}

int main() {
    string num1 = "123", num2 = "456";

    cout << multiply(num1, num2);

    return 0;
}