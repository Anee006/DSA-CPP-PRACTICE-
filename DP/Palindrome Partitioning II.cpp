// LeetCode 132
// uses same concept of split at 'k' & minimizing cuts as that of Matrix Chain Multiplication.

// NOTE: we use optimized version of MCM here, instead of dp[i][j], we reduce to dp[i].

// Given a string s, partition s such that every substring of the partition is a palindrome.
// Return the minimum cuts needed for a palindrome partitioning of s. (s consists of lowercase English letters only)

/*
Input: s = "aab"
Output: 1
Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.
*/

#include <iostream>
#include <vector>
using namespace std;

int minCut(string s) {
    int n = s.length();

    // isPal[i][j] = true if substr s[i..j] is palindrome
    vector<vector<bool>> isPal(n, vector<bool>(n, false));

    // every single char is a palindrome
    for(int i=0; i<n; i++) {
        isPal[i][i] = true;
    }

    // check substrings of length >= 2
    for(int len = 2; len <= n; len++) { // len --> length of substring
        for(int i = 0; i <= n-len; i++) {
            int j = i + len - 1; // ending idx of substring

            // if 1st and last char match
            if(s[i] == s[j]) {
                
                // Case 1: length = 2 (eg: "aa")
                if(len == 2) isPal[i][j] = true;

                // Case 2 : length > 2  --> check inner substring
                else isPal[i][j] = isPal[i + 1][j - 1];
            }
        }
    }

    // DP array: dp[i] = min cuts needed for substr s[0..i]
    vector<int> dp(n, 0);

    // iterate over all ending positions
    for(int i=0; i<n; i++) {
        
        // if whole substr s[0..i] is a palindrome then no cut is needed
        if(isPal[0][i]) dp[i] = 0;

        else {
            dp[i] = INT_MAX;

            // try all possible partitions at k
            for(int k=0; k<i; k++) {
                
                // check is right part s[k+1..i] is palindrome
                if(isPal[k+1][i]) {
                    // If yes then, dp[k] --> cuts needed for the left part + 1 for current cut
                    dp[i] = min(dp[i], dp[k] + 1);
                }
            }
        }
    }

    return dp[n-1];  // min cuts required for full string
}

int main() {
    string s = "aab";

    cout << "Min cuts: " << minCut(s);
    return 0;
}

// TC = O(n^2)
