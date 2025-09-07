//VALID PALINDROME Problem

//A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, 
//it reads the same forward and backward. Alphanumeric characters include letters and numbers.

//Given a string s="Ac3?e3c&a", return true if it is a palindrome, or false otherwise.

//TC of code= O(n)

#include <iostream>
#include <string>
using namespace std;

bool isAlphaNum(char ch) //to check is a char is alphanumeric or not
{
    if( (ch>='0' && ch <='9') || (tolower(ch) >= 'a' && tolower(ch) <= 'z')) //converted both uppercase and lowercase to lowercase and then checking
        return true;

    return false; //else case
}
//NOTE: can also use isalnum() here instead of creating this fn, which is a built-in fn to check if a char is alphanumeric 

bool isPalindrome(string s)
{
    int st=0;
    int end= s.length()-1;

    while(st<end)
    {
        if(!isAlphaNum( s[st]))  //checking for start case
        {
            st++; //move pointer forward
            continue; //as we want to check it continuously
        }

        if( !isAlphaNum( s[end]))  //checking for end case
        {
            end--;
            continue;
        }

        if(tolower(s[st]) != tolower(s[end]))
        {
            return false;
        }

        st++; end--; //else case
    }
    return true; //means is a valid palindrome
}

int main()
{
    string s="Ac3?e3c&a";
    
    cout<<isPalindrome(s)<<endl;
    return 0;
}