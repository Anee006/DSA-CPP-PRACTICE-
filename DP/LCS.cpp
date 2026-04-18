// Longest Common Subsequence (LeetCode 1143)

// Given two strings text1 and text2, return the length of their longest common subsequence. 
// If there is no common subsequence, return 0.
// For example, "ace" is a subsequence of "abcde".

/* 
Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.
*/

// LOGIC:
// We define a 2D table: dp[i][j] = length of LCS of text1[0...i-1] and text2[0...j-1]

// RECURRENCE:
// If characters match: dp[i][j] = dp[i-1][j-1] + 1
// If they don’t: dp[i][j] = max(dp[i-1][j], dp[i][j-1])

#include <iostream>
#include <vector>
using namespace std;

int longestCommonSubsequence(string text1, string text2) {
    int n = text1.length();
    int m = text2.length();

    // Create 2D DP table (fill 1st row and 1st col by 0)
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    // Fill the table
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {

            // if characters match:
            if(text1[i-1] == text2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            }

            // if they don't match
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[n][m]; // last cell in the table is the length of LCS
}

int main() {
    string text1 = "abcde";
    string text2 = "ace";
    
    int result = longestCommonSubsequence(text1, text2);
    cout << "Length of LCS: " << result << endl;

    return 0;
}

// TC = O(n * m)
// SC = O(n * m)