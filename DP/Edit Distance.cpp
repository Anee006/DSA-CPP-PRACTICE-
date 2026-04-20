// LeetCode 72
// string Editing problem

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
using namespace std;

int minDistance(string word1, string word2) {

}

int main() {
    string word1 = "horse", word2 = "ros";

    cout << "Edit Distance: " << minDistance(word1, word2);
    return 0;
}

// TC: O(n + m), SC: O(m)