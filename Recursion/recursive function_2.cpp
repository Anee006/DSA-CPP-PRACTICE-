//to create a recursive function to calculate sum of digits of a number
#include <iostream>
using namespace std;

int sum_of_digits(int);
int main()
{
    int n;
    cout<<"Enter a 3 digit number: ";
    cin>>n;
    cout<<"Sum of digits is: "<< sum_of_digits(n)<<endl;
    return 0;
}

int sum_of_digits(int num)
{
    if(num==0) //base case                        //number % 10 gives the last digit
    {                                             //number / 10 gives the first two digits
        return 0;                                 //number % 10 gives the second digit
    }                                             //number / 10 gives the first digit.
    
    return num%10 + sum_of_digits(num/10); 
}