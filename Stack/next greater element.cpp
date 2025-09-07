//NEXT GREATER ELEMENT:
//using stack

//for an element say arr[i], next greater element is said to be the element which is immediately greater than i and occurs at its right side.

//for the given array: [6,8,0,1,3].
//The next greater element for 6 = 8
//The next greater element for 8 = -1, as no greater element than 8 exists on its right
//The next greater element for 0 = 1
//The next greater element for 1 = 3
//The next greater element for 3 = -1 , as no greater element exists for 3 on its right side

//NOTE: we will go backwards and then find the next greater element for each value. Eg, first we will calculate next greater element for 3, 
//then for 1 and in last we will calculate next greater element for 6.

//we know, for the last element (in this case it is: 3), the next greater element will always be -1.

//we use a stack to store elements that are greater than the current element and are on its right side.
//we are using stack because we need to store the elements in reverse order.
//for any element arr[i], we will search for the next greater element at its top.

//in the beginning, next greater el = -1.
//first we will store 3 in the stack, then for 1 will check the stack for its next greater element. since 3 > 1, so next greater el = 3.
//then check for 0 and so on..
//for an element if the top el is not the next greater element then we will pop that value and check for the val under it.
//if that is also not greater then pop that as well. keep on popping till you get the next greater el. If, the stack becomes empty it means that
//for that element no next greater el exists (so for it, next greater el = -1).

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
    vector <int> arr = {6,8,0,1,3};

    vector <int> ans(arr.size(), 0); //to store the next greater element for each value of "arr"
    stack <int> s;

    //to find the next greater el:
    
    //applying a reverse loop:
    for(int i = arr.size() - 1; i >= 0; i--)
    {
        //to pop elements that are at the top of the stack and that are smaller than the current element
        while(s.size() > 0 && s.top() <= arr[i]) //the element should be strictly greater than the current el. Hence we wrote "=" as well
        {
            s.pop();
        }

        if(s.empty())
        {
            ans[i] = -1; //the next greater el will be -1 whenever stack becomes empty
        }
        else //else, the next greater el will be the el at the top of the stack
        {
            ans[i] = s.top();
        }
        s.push(arr[i]); //to push the current el in the stack
    }

    //to print the "ans" vector:
    for(int val: ans)
    {
        cout << val << "\t";
    }
    cout << endl;

    return 0;
}

//TC = O(n)
//SC = O(n)