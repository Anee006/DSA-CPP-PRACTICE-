//To find the GCD or HCF of two numbers
//(with Euclid's algo )

#include <iostream>
using namespace std;

int EuclidAlgo(int a, int b)
{
    while(a >0 && b >0)
    {
        if(a>b)
        {
            a= a%b; //using Optimised Euclid's approach
        }
        else
        {
            b = b%a;
        }
    }

    if(a==0) return b; //if one of the two number becomes 0 then the other no. is the gcd

    return a; //means if b==0, then a will be the ans
}
int main()
{
    int a=6, b=12;

    cout<<"GCD = "<< EuclidAlgo(a,b) <<endl;

    return 0;
}