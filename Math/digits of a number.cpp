//Digits of a number
//TC in all three functions is: O(log n)

#include <iostream>
using namespace std;

//to print digits of a number
void printDigits(int n)
{
    while(n!=0)
    {
        int digit= n%10;
        cout<< digit <<endl; //digits will be printed in reverse order as first the last digit will be printed, then second last and so on..

        n= n/10; //to make the number smaller in each step
    }
}

//to print the number of digits in a number i.e, the count
int countofDigits(int n)
{
    int count=0;

    while (n!=0)
    {
        int digits= n%10;
        count ++;  //means ki ek digit mil gaya hai so update the count

        n=n/10;
    }
    return count;    
}

//to calculate sum of digits
int sumOfDigits(int n)
{
    int sum=0;
    while(n!=0)
    {
        int digits= n%10;

        sum += digits;

        n=n/10;
    }
    return sum;
}

int main()
{
    int n=3568;

    printDigits(n);

    cout<<endl <<"Count of digits: " <<countofDigits(n) <<endl;

    cout<<endl <<"Sum of digits: "<< sumOfDigits(n) <<endl;


    return 0;
}