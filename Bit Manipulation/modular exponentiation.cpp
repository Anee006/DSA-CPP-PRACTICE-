// given three integers x, n, M, compute (x^n) % M

#include <iostream>
using namespace std;

int powMod(int x, int n, int M) {
    int res = 1;

    while(n >= 1) { // loop until exponent becomes 0

        // if n is odd, multiply result by current x & take modulo
        if(n & 1) {
            res = (res * x) % M;
            n--; // reduce exponent by 1 to make it even
        }

        // n is even, square the base & half the exponent
        else {
            x = (x * x) % M;
            n /= 2;
        }
    }
    return res;
}

int main() {
    int x = 3, n = 2, M = 4;
    cout << powMod(x, n, M); // returns (3^2)%4 --> 9 % 4 --> 1

    return 0;
}

// TC = O(log n) , SC = O(1)