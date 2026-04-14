// LeetCode 509

// F(0) = 0, F(1) = 1
// F(n) = F(n - 1) + F(n - 2), for n > 1.
// Given n, calculate F(n).

// NOTE: The recursive approach takes O(2^n) TC. So, we use Memoization instead (Top down DP)

#include <iostream>
#include <vector>
using namespace std;

int fib(int n) {
    // base case
    if(n == 0) return 0;

    vector<int> dp(n+1);

    dp[0] = 0;
    dp[1] = 1;

    for(int i = 2; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];    
}

int main() {
    int n = 4;
    
    cout << "Fib(" << n << ") = " << fib(n);

    return 0;
}

// TC = O(n), SC = O(n)

