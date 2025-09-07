//calculate total money that will be accumulated if you start with rs. 1 and double it everyday, for n number of days; using recursion.
#include <iostream>
using namespace std;

int money(int);
int main()
{
    int days;
    cout<<"Enter number of days for which you need to calculate the money: ";
    cin>>days;
    cout<<"After "<<days <<" days, you will have Rs. "<<money(days)<<endl;

    return 0;
}

int money(int n)
{
    if(n==1) //on 1st day, we will only have 1 rs.
    {
        return 1;
    }
    return money(n-1)*2;  //money on day n = money on the previous day *2.
}