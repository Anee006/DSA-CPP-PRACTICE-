//REVERSE INTEGER

//Given a signed 32-bit integer x, return x with its digits reversed. 
//If reversing x causes the value to go outside the signed 32-bit integer range, then return 0.

#include <iostream>
using namespace std;

//TC= O(log n)

int reverse(int n)
{
    int reverseNum=0; //to store the reversed num

    while(n!=0)
    {
        int digit= n%10; //to get the digits of n

        if(reverseNum > INT_MAX/10 || reverseNum<INT_MIN/10) //to check if our reversed num is out of range or not, acc to the given condition
        {
            return 0;
        }

        reverseNum = (reverseNum * 10) + digit; //to reverse num //This is the step due to which reverseNum can go out of range, hence we put if condition before this
        
        n=n/10; //updation 
    }
    return reverseNum;
}

int main()
{
    int n=4537;
    cout << reverse(n) <<endl;
    return 0;
}
