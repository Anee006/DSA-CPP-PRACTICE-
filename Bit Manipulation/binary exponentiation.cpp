// to find a^n using Binary Exponentiation

#include <iostream>
using namespace std;

int power(int a, int n) {
    int ans = 1;

    while(n > 0) {
        int last_bit = (n & 1);

        if(last_bit) ans *= a; // if current LSB is set(1)
        a *= a;

        n = n >> 1; // right shift
    }
    return ans;
}

int main() {
    int a = 3, n = 5;
    cout << power(a, n); // 3^5 = 243

    return 0;
}

// TC = O(log n) , SC = O(1)