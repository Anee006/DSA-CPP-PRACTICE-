//LCM of a and b

#include <iostream>
using namespace std;

int GCD(int a, int b) //for finding gcd
{
    while(a>0 && b>0)
    {
        if(a>b)
        {
            a= a%b;
        }
        else
        {
            b =b%a;
        }
    }
    if(a==0) return b;
    return a;
}

int LCM(int a, int b) //for finding lcm
{
    int gcd= GCD(a,b);
    
    return (a*b)/gcd; //formula to find lcm
}

int main()
{
    int a=20, b=28;

    cout<<"GCD = "<<GCD(a,b) <<endl;
    cout<<"LCM = "<<LCM(a,b) <<endl;

    return 0;
}