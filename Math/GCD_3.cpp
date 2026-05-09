//GCD using recursion

#include <iostream>
using namespace std;

int gcd(int a, int b) //Here, we assume that "a>b" always
{
    //base case
    if(b==0) return a; //not checking if (a==0) as we had assumed that a>b

    return gcd(b, a%b); //the first value needs to be greater, and since a%b is less than b, hence b is written first
}

int main()
{
    int a=12, b=10;

    cout<<"GCD = "<< gcd(a,b) <<endl;

    return 0;
}