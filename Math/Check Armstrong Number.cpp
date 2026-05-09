//Checking if a number is an Armstrong No. or not.
//Armstrong no. is a no which is equal to the sum of cube of its digits

#include <iostream>
using namespace std;

bool isArmstrong(int n)
{
    int copy= n; //creating a copy of the orginal number
    int sumOfCubes=0;

    while(n!=0)
    {
        int digit= n%10;
        sumOfCubes += (digit*digit *digit); //to calculate sum of cube of digits

        n=n/10;
    }
    return sumOfCubes==copy; //if sumofCubes==copy i.e, the original number 'n' then it returns true else returns false
}
int main()
{
    int n=153;

    if(isArmstrong(n))
        cout<<n <<" is an Armstrong number "<<endl;
    else
        cout<<n<<" is not an Armstrong number "<<endl;

    return 0;
}