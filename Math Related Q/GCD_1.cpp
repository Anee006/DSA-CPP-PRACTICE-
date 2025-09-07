//To find the GCD or HCF of two numbers
//(without Euclid's algo )

#include <iostream>
using namespace std;

int GCD(int a, int b)
{
    int gcd=1; //as 1 is divisble by any no. so if we fail to find any common divisor then 1 wil become the gcd

    //base case
    if(a==0)    //if any one of the two number becomes 0, then the other no. becomes the gcd
    {
        gcd=b;
    }
    if(b==0)
    {
        gcd=a;
    }

    if(a==b)
    {
        gcd=a; //or we can also write: gcd=b, as both are same
    }

    for(int i=1; i<= min(a,b); i++)
    {
        if(a%i ==0 && b%i ==0) //means if a number is divisble by both it can become the gcd
        {
            gcd=i;
        }
    }
    return gcd;
}

int main()
{
    int a=20, b=28;

    cout<<"GCD = "<< GCD(a,b) <<endl;

    return 0;
}