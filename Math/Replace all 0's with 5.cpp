// geeksforgeeks

// You are given an integer n. You need to convert all zeroes of n to 5.

// Input: n = 1004
// Output: 1554
// Explanation: There are two zeroes in 1004 on replacing all zeroes with 5, the new number will be 1554.

#include <iostream>
using namespace std;

int convertFive(int n) {
    if(n == 0) return 5; // edge case --> if n = 0, replace it by 5
    
    int result = 0;
    int place = 1;

    while(n > 0) {
        int digit = n % 10;

        if(digit == 0) digit = 5;

        result = result + digit * place;

        place *= 10;

        n /= 10;
    }

    return result;
}

int main() {
    int n = 1004;

    cout << convertFive(n);

    return 0;
}

// TC = O(d) , where d = number of digits
// SC = O(1)