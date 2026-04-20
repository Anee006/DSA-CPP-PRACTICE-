// LeetCode 72
// String Editing problem

// Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.
// You have the following three operations permitted on a word:
// Insert a character
// Delete a character
// Replace a character

/*
Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minDistance(string word1, string word2) {
    int m = word1.size(), n = word2.size();

    vector<vector<int>> dp(m+1, vector<int>(n+1));

    for(int i = 0; i <= m; i++) dp[i][0] = i;
    for(int j = 0; j <= n; j++) dp[0][j] = j;

    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(word1[i-1] == word2[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            }
            else {
                dp[i][j] = 1 + min({dp[i-1][j], // delete
                                dp[i][j-1],     // insert
                                dp[i-1][j-1]}); // replace
            }
        }
    }
    return dp[m][n];
}

int main() {
    string word1 = "horse", word2 = "ros";

    cout << "Edit Distance: " << minDistance(word1, word2);
    return 0;
}

// TC: O(m * n), SC: O(m * n)