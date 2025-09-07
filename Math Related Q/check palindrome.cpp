//CHECK IF A NUMBER IS PALINDROME

#include <iostream>
using namespace std;

int reverse(int n) //to calculate reverse of n
{
    int reverseNum=0;

    while(n!=0)
    {
        int digit= n%10;
        reverseNum = (reverseNum*10) + digit;
        n= n/10;
    }
    return reverseNum;
}


bool isPalindrome(int n)
{
    if(n<0) return false; //as -ve number can never be a palindrome

    int rev= reverse(n);

    return (n==rev); //if both are equal it returns true i.e, is a palindrome, else returns false

}

int main()
{
    int n=353;
    cout<< isPalindrome(n) <<endl;

    return 0;
}