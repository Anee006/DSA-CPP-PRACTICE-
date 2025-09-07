//PALINDROME PARTITIONING
//using recursion

//Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.
//s contains only lowercase English letters.

//Input: s = "aab"
//Output: [["a","a","b"],["aa","b"]]

//LOGIC:
//to partition the given string we can cut the string into parts. For a string of "n" size, we can apply "n-1" cuts to it.
//after cutting string into parts, check for left part, whether it is a palindrome or not. If that part is not a palindrome, then
//no point in further cutting the part so, move the cut forward for the next part and again check the same.
//If the part happens to be a palindrome, then further cut that part and check again.

//suppose we have a string "abaabcaba". We find that the first palindrome we get in this string is "aba". So include that in ans and check for 
//the remaining part of string i.e, "abcaba". We find that 'a' is also a palindrome so include that as well in ans. The remaining part is also a
//palindrome so our ans = [aba, a, b, c, aba]. We can also split last "aba" further like - [aba, a, b, c, a, b, a].

//for a string 's', we can find the part using, " part = s.substr(0,i+1) ". Where 0 is from where the part starts and i+1 is the size of the part.
//and " s.substr(i+1) " is the remaining part of the string (the right half), after the cut is made.

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

//to check if string is palindromic or not
bool isPalindrome(string s)
{
    string s2 = s; //is a copy of the original string
    reverse(s2.begin(), s2.end()); //reversed s2

    return s == s2; //if same returns true, else false
}

void getAllParts(string s, vector<string>& partitions, vector<vector<string>>& ans)
{
    //base case:
    if(s.size() == 0)  //means found all palindromic parts
    {
        ans.push_back(partitions);
    }

    //to make cuts in the string
    for(int i=0; i<s.size(); i++)
    {
        string part = s.substr(0, i+1); //to get left part of the cut made

        if(isPalindrome(part)) //means the part is a palindrome
        {
            partitions.push_back(part);
            getAllParts(s.substr(i+1), partitions, ans); //for the other half (i.e, right part) of the part
            partitions.pop_back(); //backtracking step: to store new parts in the ans
        }
    }
}

vector<vector<string>> partition(string s)
{
    vector<vector<string>> ans;
    vector <string> partitions;

    getAllParts(s, partitions, ans);

    return ans;
}

int main()
{
    string s = "aab";
    vector<vector<string>> ans = partition(s);

    //to display ans:
    cout << "[";
    for (size_t i = 0; i < ans.size(); i++) 
    {
        cout << "[";
        for (size_t j = 0; j < ans[i].size(); ++j) 
        {
            cout << "\"" << ans[i][j] << "\"";
            if (j < ans[i].size() - 1) 
                cout << ",";
        }
        cout << "]";
        if (i < ans.size() - 1) 
            cout << ", ";
    }
    cout << "]\n";

    return 0;
}

//TC = O(n * 2^n)