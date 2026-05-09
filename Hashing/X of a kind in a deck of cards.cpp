// LeetCode 914

// You are given an integer array deck where deck[i] represents the number written on the ith card.
// Partition the cards into one or more groups such that:
// Each group has exactly x cards where x > 1, and All the cards in one group have the same integer written on them.
// Return true if such partition is possible, or false otherwise.

// Input: deck = [1,2,3,4,4,3,2,1]
// Output: true
// Explanation: Possible partition [1,1],[2,2],[3,3],[4,4].

// LOGIC:
// Count frequency of each card.
// Compute GCD of all frequencies.
// If final GCD > 1 --> possible. Else --> not possible.

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

bool hasGroupsSizeX(vector<int>& deck) {
    unordered_map<int, int> m;
    
    for(int card : deck) {
        m[card]++; // find freq of each card
    }

    int g = 0;

    // find gcd of all freq
    for(auto it : m) {
        g = __gcd(g, it.second);
    }
    
    return (g > 1); // valid only if gcd > 1
}

int main() {
    vector<int> deck = {1,2,3,4,4,3,2,1};
    
    if(hasGroupsSizeX(deck)) cout << "True";
    else cout << "False";

    return 0;
}

// TC:
// Counting frequencies: O(n) , n = number om = distinct card valuesf cards
// GCD over frequencies: O(mlogn) , m = distinct card values
// overall TC = O(n) 

// SC = O(m)