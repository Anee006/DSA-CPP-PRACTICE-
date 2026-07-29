// LeetCode 49

// Given an array of strings strs, group the anagrams together. You can return the answer in any order.

/*
Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
Explanation:
There is no string in strs that can be rearranged to form "bat".
The strings "nat" and "tan" are anagrams as they can be rearranged to form each other.
The strings "ate", "eat", and "tea" are anagrams as they can be rearranged to form each other.
*/
 
// LOGIC:
// Find a unique identifier (key) for every anagram group
// Eg: eat, tea, ate are all anagrams bcoz when we sort them we get: aet
// Use a hashmap: unordered_map<string, vector<string>> 
// where Key = sorted string , Value = all original strings having that sorted form (these are anagrams)
// Traverse every string in the input. Make a copy of the current string. Sort the copied string.
// Use the sorted string as the key and insert the original string into the corresponding vector.
// Traverse the map and collect all vectors into the answer. Return the answer.

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> m; // {sorted str, list of anagrams}

    for(string s : strs) {
        string key = s; // create a copy
        sort(key.begin(), key.end()); // sort the copy

        m[key].push_back(s); // store original string under sorted key
    }

    vector<vector<string>> ans;

    for(auto it : m) ans.push_back(it.second);

    return ans;
}

int main() {
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};

    vector<vector<string>> ans = groupAnagrams(strs);

    for(auto group: ans) {
        for(auto word: group) cout << word << " ";
        cout << endl;
    }

    return 0;
}

// TC = O(n * klogk)
// SC = O(n * k)