//recursive fn to find factorial of n

#include <iostream>
using namespace std;

int factorial (int);

int main()
{
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    cout<<"Factorial of "<<n<<" is: "<<factorial(n)<<endl;
    return 0;
}

int factorial (int x)      //factorial is the recursive function.
{                          //process of a function calling itself repeatedly till base condition is reached is called recursion.

    if(x==1 || x==0) //base condition
    {
        return 1;
    }
    return x*factorial(x-1);
}