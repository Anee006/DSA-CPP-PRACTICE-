// LeetCode 3014

// You are given a string word containing distinct lowercase English letters.
// Telephone keypads have keys mapped with distinct collections of lowercase English letters, which can be used to form words by 
// pushing them. For example, the key 2 is mapped with ["a","b","c"], we need to push the key one time to type "a", 
// two times to type "b", and three times to type "c" .
// It is allowed to remap the keys numbered 2 to 9 to distinct collections of letters. 
// The keys can be remapped to any amount of letters, but each letter must be mapped to exactly one key. 
// Return the minimum number of pushes needed to type word after remapping the keys.
// Note that 1, *, #, and 0 do not map to any letters.

// LOGIC:
// Since all letters in word are distinct, each letter is typed exactly once.
// Minimize the total push cost of assigning these letters to the 8 available keys (2–9).
// The 1st letter assigned to a key costs 1 push. The 2nd letter assigned to the same key costs 2 pushes. The 3rd letter costs 3 pushes, and so on.
// To minimize the total pushes: Put the first 8 letters in the first position of the 8 keys (cost = 1 each).
// The next 8 letters go in the second position (cost = 2 each). The next 8 letters go in the third position (cost = 3 each).

#include <iostream>
using namespace std;

int minimumPushes(string word) {
    int ans = 0;

    for(int i = 0; i < word.size(); i++) {
        ans += i/8 + 1;
    }
    return ans;
}

int main() {
    string word = "xycdefghij";

    cout << minimumPushes(word);

    return 0;
}

// TC = O(n)
// SC = O(1)