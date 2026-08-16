// LeetCode 43

// Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.
// Note: You must not use any built-in BigInteger library or convert the inputs to integer directly. (can't use stoi() or to_string()).

// Input: num1 = "123", num2 = "456"
// Output: "56088"

// LOGIC:
// We can't directly convert strings to int bcoz they may contain numbers much larger than "int" or "long long" can handle.
// Multiply individual digits because each character represents one digit.
// int digit1 = num1[i] - '0' --> If, num1[i] == '7' then, '7' - '0' = 7
// String number -> Take individual digits -> Multiply digits -> Store in result array -> Handle carry -> Convert result array to string

#include <iostream>
#include <vector>
using namespace std;

string multiply(string num1, string num2) {
    if(num1 == "0" || num2 == "0") return "0"; // multiplying by 0 gives 0

    int n1 = num1.size(), n2 = num2.size();

    vector<int> res(n1 + n2, 0); // maximum possible length of ans is n1 + n2

    // multiply each digit from right-most (just like in normal multiplication)
    for(int i = n1 - 1; i >= 0; i--) {
        for(int j = n2 - 1; j >= 0; j--) {
            int digit1 = num1[i] - '0';
            int digit2 = num2[j] - '0';

            int prod = digit1 * digit2;

            int pos1 = i + j;
            int pos2 = i + j + 1;

            int sum = prod + res[pos2];

            res[pos2] = sum % 10; // stores current digit
            res[pos1] += sum / 10; // stores the carry
        }
    }

    string ans = "";

    for(int dig : res) { // convert vector<int> to string
        if(ans.empty() && dig == 0) continue; // skip leading 0s

        ans += char(dig + '0');
    }
    return ans;
}

int main() {
    string num1 = "123", num2 = "456";

    cout << multiply(num1, num2);

    return 0;
}

// TC = O(n × m) , where n = num1.length() , m = num2.length()
// SC = O(n + m)