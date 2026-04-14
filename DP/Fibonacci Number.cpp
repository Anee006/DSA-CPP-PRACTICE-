// LeetCode 509

// F(0) = 0, F(1) = 1
// F(n) = F(n - 1) + F(n - 2), for n > 1.
// Given n, calculate F(n).

// NOTE: The recursive approach takes O(2^n) TC. So, we use Memoization instead (Top down DP)

#include <iostream>
#include <vector>
using namespace std;

int fib(int n) {

}

int main() {
    int n = 4;
    
    cout << "Fib(" << n << ") = " << fib(n);

    return 0;
}

// TC = O(n), SC = O(n)

