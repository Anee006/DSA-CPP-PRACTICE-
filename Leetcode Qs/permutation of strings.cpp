//PERMUTATION IN STRING

//Using "Sliding Window Based" approach: means we try to search the ans by taking a window, which we keep on updating

//Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.
//In other words, return true if one of s1's permutations is the substring of s2.

//given: s1 = "ab", s2 = "eidbaooo"
//Output: true
//Explanation: s2 contains one permutation of s1 ("ba").

//NOTE: it is also given that- s1 and s2 consist of lowercase English letters.
//so to count the frequency of each char in s1, we can take an int array "frequency" of size 26.

//IF, in s1 we had lowercase, uppercase, digits, special symbols etc. then to store the frequency we would've used: unordered map <char,int>.

//to find index of a char in the int array "frequency": s1[i]-'a' ----> This gives the idx at which the freq of char of s1 are stored in array.

//To create the window: we'll create window of size s1.length() and compare the window frequency with the original "frequnecy".
//If both match return true else return false.

#include <iostream>
#include <string>
using namespace std;

bool isFreqSame(int freq1[], int freq2[])
{
    for(int i=0; i<26; i++)
    {
        if(freq1[i] != freq2[i])
            return false;
    }
    return true;
}

bool checkInclusion(string s1, string s2)
{
    int frequency[26] ={0}; //to store the freq of char of s1

    for(int i=0; i<s1.length(); i++)
    {
        int idx= s1[i]-'a'; //to get the idx of char of s1
        frequency[idx]++; //storing it in the freq array
    }

    int windowSize= s1.length(); //length of the window which we'll be searching

    for(int i=0; i<s2.length(); i++)
    {
        int windowIdx=0; //for the idx of window
        int idx=i;  //for the idx of the original array
        int windowFreq[26]= {0}; //to store window freq

        while(windowIdx < windowSize && idx < s2.length()) //our window in this case should be of size 2 only and not more than that
        {
            windowFreq[ s2[idx] -'a']++; //logic to store this is similar to that of storing char of s1 in frequency array
            windowIdx++;
            idx++;
        }

        if(isFreqSame(frequency, windowFreq)) //if freq of both is same means that the char occurs same amt of times in both hence, true
            return true;
    }
    return false;
}

//TC of fn checkInclusion() is O(n^2).

int main()
{
    string s1="ab";
    string s2= "eidbaooo";

    cout << checkInclusion(s1,s2) <<endl;
    return 0;
}

