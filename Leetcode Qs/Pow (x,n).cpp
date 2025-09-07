//to create pow(x,n) , which calculates x raised to power n  (x^n)

//We'll use BINARY EXPONENTIATION for this as its time complexity is less.
//If we use loop here i.e, if we run a loop n times and multiply x to itself, its time complexity is O(n), so it gives Time limit exceeded error.

//in binary exponentiation, we run a loop on the binary form of our power. so time complexity comes as O(log n).
//Steps:
//written separately in sheet

#include <iostream>
using namespace std;

double pow(double x, int n)
{
    //Corner cases (if cases):
    if(n==0)
        return 1.0; //anything raised to power 0 is 1

    if(x==0)
        return 0.0; //0 raised to any power is 0

    if(x==1)
        return 1.0; //1 raised to any power is also 1

    if(x== -1 && n%2==0)
        return 1.0; //if our base is -1 and power is even then ans is 1

    if(x== -1 && n%2==1)
        return -1.0; //if our base is -1 and power is odd then ans is -1
        

    //main logic:
    long binaryForm =n; 
    if(n<0) //if we have negative powers, we need to make it +ve, as in binary exponentiation we need only +ve powers
    {
        x= 1/x;

        binaryForm= -binaryForm; //so that is n was -ve, then it becomes +ve.

    }

    double ans=1;

    while(binaryForm>0)
    {
        if(binaryForm % 2==1) //to check if last digit of the binary form is 1
            ans *=x;
        x *=x; //taking x^2 here

        binaryForm /=2; //to get the 2nd last digit
    }

    return ans;
}
int main()
{
    cout<< pow(3,5);

    return 0;
}