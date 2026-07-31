// LeetCode 3016

// You are given a string word containing lowercase English letters.
// Telephone keypads have keys mapped with distinct collections of lowercase English letters, which can be used to form words by pushing them. 
// For example, the key 2 is mapped with ["a","b","c"], we need to push the key one time to type "a", two times to type "b", and three times to type "c" .
// It is allowed to remap the keys numbered 2 to 9 to distinct collections of letters. The keys can be remapped to any amount of letters, 
// but each letter must be mapped to exactly one key. You need to find the minimum number of times the keys will be pushed to type the string word.
// Return the minimum number of pushes needed to type word after remapping the keys.

/*
Input: word = "xyzxyzxyzxyz"
Output: 12
Explanation: 
"x" -> one push on key 2
"y" -> one push on key 3
"z" -> one push on key 4
Total cost is 1 * 4 + 1 * 4 + 1 * 4 = 12
*/

// LOGIC:
// The letters are not distinct in "word". So, a letter can be repeated.
// The first letter assigned to a key costs 1 push, the second costs 2 pushes, and so on.
// Assign the most frequent letters in word to the smallest push counts.

// STEPS:
// Count the frequency of every character.
// Sort the frequencies in descending order.
// Assign: First 8 most frequent letters -> cost 1, Next 8 letters -> cost 2, Next 8 letters -> cost 3, Remaining letters -> cost 4
// Sum, frequency * assigned_cost.

#include <iostream>
#include <vector>
using namespace std;

int minimumPushes(string word) {
}

int main() {
    string word = "xyzxyzxyzxyz";

    cout << minimumPushes(word);

    return 0;
}

// TC = O(n) (as sorting only 26 lowercase letters in constant time)
// SC = O(1)