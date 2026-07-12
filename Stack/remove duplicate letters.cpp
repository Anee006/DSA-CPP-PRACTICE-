// Leetcode 316

// Given a string s, remove duplicate letters so that every letter appears once and only once. 
// You must make sure your result is the smallest in lexicographical order among all possible results.
// s consists of lowercase English letters.

// Input: s = "cbacdcbc"
// Output: "acdb"

// LOGIC:
// count freq of each char
// traverse the string. Decrease remaining freq of the char
// if already visited --> continue
// while (stack is not empty) && (curr < stack.top()) && (stack.top() appears later) --> remove the top, then push curr char

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

string removeDuplicateLetters(string s) {
    vector<int> freq(26, 0);

    for(char c : s) freq[c - 'a']++;

    vector<bool> vis(26, false);
    stack<char> st;

    for(char c : s) {
        freq[c - 'a']--;

        if(vis[c - 'a']) continue;

        while(!st.empty() && c < st.top() && freq[st.top() - 'a'] > 0) {
            vis[st.top() - 'a'] = false;
            st.pop();
        }

        st.push(c);
        vis[c - 'a'] = true;
    }

    string ans = "";

    while(!st.empty()) {
        ans += st.top();
        st.pop();
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

int main() {
    string s = "cbacdcbc";

    string ans = removeDuplicateLetters(s);

    cout << ans;
}

// TC = O(n) , where n = be the length of the string
// SC = O(1)