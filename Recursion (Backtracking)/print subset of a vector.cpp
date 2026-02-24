//to print subsets of an array/vector

#include <iostream>
#include <vector>
using namespace std;

void printSubset(vector<int>& arr, vector<int>& ans, int i)
{
    //base case:
    if(i == arr.size()) //means we have no more element left in the arr to add, so print the ans
    {
        for(int val: ans)
        {
            cout<<val<<" ";
        }
        cout<<endl;
        return;
    }

    //each element has two choices- either it can include in the ans or exclude

    //for include
    ans.push_back(arr[i]);
    printSubset(arr, ans, i+1);

    ans.pop_back(); //backtracking step //used to remove the last el which we had included just now
    
    //for exclude
    printSubset(arr, ans, i+1);

}

int main()
{
    vector <int> arr= {1,2,3};
    vector <int> ans; //to store ans

    printSubset(arr,ans,0);

    return 0;
}

//NOTE: the null subset i.e, {} is depicted by blank line in the output

//TC = total no. of calls * work in each call
//TC = 2^n * n * O(1)                      (for array of size n, no. of subsets = 2^n, to reach 2^n subsets, the work done will be n)
//TC = O(2^n * n)