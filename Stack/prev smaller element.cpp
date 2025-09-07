//PREVIOUS SMALLER ELEMENT
//similar to "next greater element" Q

//For a given array, [3,1,0,8,6], we need to store the prev smaller element of each element of the array.

//for any arr[i], its prev smaller element is that value which is immediately smaller than it and is on its left side.

//prev smaller el for 3 = -1 (as no el exists on its left side)
//prev smaller el for 1 = -1 (as no smaller el exists on its left side)
//prev smaller el for 0 = -1 (as no smaller el exists on its left side)
//prev smaller el for 8 = 0  (as 0 is less than 8)
//prev smaller el for 6 = 0  (as 0 is less than 6)

//so the ans we have return is: [-1,-1,-1,0,0]

//LOGIC:
//create a stack to store the prev smaller el for the current el
//if stack is empty means no prev smaller el exists for that element
//if at the top of the stack, the val is greater than the current el (means if it is not smaller than the current el) then pop that value.

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector <int> prevSmallerElement(vector <int>& arr)
{
    vector <int> ans(arr.size(), 0);
    stack <int> s;

    for(int i = 0; i < arr.size(); i++)
    {
        //to remove elements that are greater than or equal to the current el ( as we only need those el which are smaller than current el)
        while(s.size() > 0 && s.top() >= arr[i])
        {
            s.pop();
        }
        if(s.empty()) //if stack becomes empty
        {
            ans[i] = -1;
        }
        else //means we have a valid prev el for the current el
        {
            ans[i] = s.top();
        }

        s.push(arr[i]);
    }
    return ans;
}

int main()
{
    vector <int> arr = {3,1,0,8,6};

    vector <int> ans = prevSmallerElement(arr);

    for(int val: ans)
    {
        cout<< val <<"\t";
    }
    cout<< endl;

    return 0;
}

//TC = O(n)
//SC = O(n)