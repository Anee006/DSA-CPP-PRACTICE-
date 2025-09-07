//Given an array of integers called "nums". In it, every element appears twice except for one. Find that single one.
// let, nums= [4,1,2,1,2]

#include <iostream>
#include <vector>
using namespace std;

//Need to use BITWISE XOR operator for this.
//Rules of BITWISE XOR:
// 0^0 = 0  //same, so cancels
// 1^1 = 0  //same, so cancels
// 0^1 = 1
// 1^0 = 1

// BITWISE XOR operator ke paas agar same value hoti hai toh wo usse cancel kardeta hai i.e, zero kar deta hai.

//Given array: [4,1,2,1,2]
//Binary form of 2 is 10.
//so, 2^2 i.e, 10^10 = 0  (0^0 = 0 and  1^1 = 0)

//So, for a number "n",
//n^n =0  and  n^0=n

class solution
{
    public:
        int singleNumber(vector <int> &nums)  //as we want the changes done to be reflected everywhere so we are using pass by ref here
        {
            int ans=0;

            for(int val: nums)
            {
                ans= ans^val;
            }
            return ans;
        }
};

int main()
{

    vector <int> nums= {4,1,2,1,2};

    solution obj;
    cout<<"Required ans is: "<< obj.singleNumber(nums) <<endl;


    return 0;
}