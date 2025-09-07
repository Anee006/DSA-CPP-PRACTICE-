//PAIR SUM using OPTIMIZED APPROACH
//For the given array ={2,7,11,15}, return the pair with the target sum of 9.
//The array is sorted in ascending order

#include <iostream>
#include <vector>
using namespace std;

//using two pointer approach
//we will take two pointers i and j. i points at the first element i.e, the smallest element
//j points at the end element i.e, the largest element
//adding i and j we get the sum of the smallest and the largest.

//we will compare it with the target sum. we can get either of the three cases:
//1. The sum is > target
//2. The sum is < target
//3. The sum is = target

//If case 1. happens, we will decrease j by 1 i.e, j-- , as we don't want the sum to be greater than target and the greater of the two
//elements i.e, j is the one increasing the sum so we  do j--

//If case 2. happens we will increase i by 1 i.e, i++ , as sum is less than target

//If case 3, happens, we simply return the ans

#include <iostream>
#include <vector>
using namespace std;

vector <int> pairSum( vector <int> nums, int target)
{
    vector <int> ans;
    int n= nums.size();
    int i=0;    //points to first element
    int j=n-1;  //points to last element

    while(i<j)
    {
        int sum= nums[i] + nums[j];

        if(sum>target)
            j--;
        else if (sum<target)
            i++;
        else
        {
           ans.push_back(i);
           ans.push_back(j);
           return ans; 
        }
    }
    return ans;
}

int main()
{
    vector <int> nums= {2,7,11,15};
    int target=18;

    vector <int> ans= pairSum(nums,target);

    cout<<ans[0]<<" , "<<ans[1]<<endl;

    return 0;
}