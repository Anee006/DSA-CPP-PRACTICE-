// Idea is to: minimize multiplication cost

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {5, 4, 6, 2, 7};
    /*
    Matrix dimensions are:
    A₁ = 5 × 4
    A₂ = 4 × 6
    A₃ = 6 × 2
    A4 = 2 x 7
    So we have 4 matrices.
    */
    int n = arr.size();

    vector<vector<int>> dp(n, vector<int>(n, 0));

    for(int len = 2; len < n; len++) {
        for(int i = 1; i < n - len + 1; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;

            for(int k = i; k < j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + arr[i-1] * arr[k] * arr[j]);
            }
        }
    }
    cout << "Min cost: " << dp[1][n-1];

    return 0;
}

// TC = O(n^3), SC = O(n^2)