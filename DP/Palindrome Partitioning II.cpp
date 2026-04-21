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

}

int main() {
    string s = "aab";

    cout << "Min cuts required is: " << minCut(s);
    return 0;
}

// TC = O(n^2)
