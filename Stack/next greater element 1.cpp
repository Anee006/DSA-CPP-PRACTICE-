//NEXT GREATER ELEMENT I:
//using stack

//logic is similar to that of the to find "next greater element" Q.

//The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.
//You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.

//For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. 
//If there is no next greater element, then the answer for this query is -1.

//Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.

//NOTE: All integers in nums1 and nums2 are unique. All the integers of nums1 also appear in nums2.

//Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
//Output: [-1,3,-1]
/* 
Explanation: The next greater element for each value of nums1 is as follows:
- 4 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
- 1 is underlined in nums2 = [1,3,4,2]. The next greater element is 3.
- 2 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
*/


//STEPS:
//first, find the next greater el for all the elements of nums2 in a single go.
//now search for the next greater el of nums1 elements in the next greater el of nums2 that we had already stored.
//create an unordered_map. the elements(i.e, nums2[i] ) are stored as key and their corresponding next greater el is stored as the value.
//for the nums2 array = [1,3,4,2]:
//for key = 1, value = 3 (as next greater el of 1 is 3)
//for key = 3, value = 4 (as next greater el of 3 is 4)
//for key = 4, value = -1 (as next greater el of 4 is -1)
//for key = 2, value = -1 (as next greater el of 2 is -1)


#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>

using namespace std;

vector <int> nextGreaterElement(vector <int>& nums1, vector <int>& nums2)
{
    unordered_map <int,int> m; //to create pair of nums2[i] and its next greater el
    stack <int> s; //to find the next greater el

    //reverse loop to calculate next greater el for each of nums2 element:
    for(int i = nums2.size()-1; i>=0; i--)
    {
        while(s.size() > 0 && s.top() <= nums2[i])
        {
            s.pop();
        }

        if(s.empty())
        {
            m[nums2[i]] = -1; //storing val in the map
        }

        else
        {
            m[nums2[i]] = s.top(); //s.top() is the next greater el
        }

        s.push(nums2[i]);
    }

    vector <int> ans;
    for(int i =0; i< nums1.size(); i++)
    {
        ans.push_back(m[nums1[i]]); //m[nums1[i]] gives the val of next greater el for the current el of nums1
    }

    return ans;
}

int main()
{
    vector <int> nums1 = {4,1,2};
    vector <int> nums2 = {1,3,4,2};

    vector <int> ans = nextGreaterElement(nums1, nums2);

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