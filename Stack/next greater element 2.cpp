//NEXT GREATER ELEMENT II
//using stack

//Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), return the next greater 
//number for every element in nums.
//If it doesn't exist, return -1 for this number.

//Input: nums = [1,2,1]
//Output: [2,-1,2]
/*Explanation: The first 1's next greater number is 2; 
The number 2 can't find next greater number. 
The second 1's next greater number needs to search circularly, which is also 2. */

//Input: nums = [1,2,3,4,3]
//Output: [2,3,4,-1,4]

//LOGIC:
//for an element we need to check on its right as well as left to find the next greater element.
//instead of traversing each element circularly, we will copy the same array element again.
//For example, for the array = [1,2,3,4,3], size = n
//we will make this into: [1,2,3,4,3,1,2,3,4,3], size = 2*n. We basically copied the elements again.
//the advantage of this is that now, we can check for next greater element in a single go only.

//STEPS:
//start traversing the new array of size = 2n, in backward order. 
//create a stack to store next greater el. If at any pt. the top element in stack becomes smaller than the current element,
//pop that value from the stack.

//for each element we will check its next greater element twice.
//when we will check for the first time, imagine that we are only checking in the right side of the element.
//when we will check the second time, imagine that we are checking in the left side of the element.
//the next greater element we will get in the second time will be the final value of next greater el for that element.

//in the og array = [1,2,3,4,3] we have index as: 0,1,2,3,4
//but in the new array of size 2n = [1,2,3,4,3,1,2,3,4,3] we have indices as:0,1,2,3,4,5,6,7,8,9

//to map the idx in new array with the correct idx of the og array, use: idx = i % n, where n is size of og array
//example: in the new array for idx = 9 which stores value = 3, 
//idx = 9 % 5 (as size of og array is 5). so idx = 4, means that it maps to the value with index = 4 in the og array.

//NOTE: WE WILL NOT ACTUALLY CREATE A NEW VECTOR OF SIZE = 2*n. 
//FOR VALUES HAVING idx > n (i.e, size of array), WE WILL CALCULATE IT USING: (idx = i % n)
//IN THE LOOP INSTEAD OF CHECKING FOR i, CHECK FOR i % n.

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector <int> nextGreaterElement(vector<int>& nums)
{
    int n = nums.size();
    vector <int> ans(n, -1); // size = n and initialised with -1
    stack <int> s;

    //NOTE: we do not know if i > n or not so instead of writing i, we will write i%n everywhere
    for(int i = 2*n -1; i>=0; i--) //running a backward loop taking size of array as 2*n
    {
        //to pop elements from stack which are smaller than the current el
        while(s.size() > 0 && nums[s.top()] <= nums[i%n])
        {
            s.pop();
        }

        ans[i%n] = s.empty() ? -1 : nums[s.top()]; 
        //if stack is empty means no next greater el exists, so store -1, else store the value of the next greater el

        s.push(i%n);
    }
    return ans;
}

int main()
{
    vector <int> nums = {1,2,3,4,3};
    vector<int> ans = nextGreaterElement(nums);

    for(int val: ans)
    {
        cout << val << "\t" << endl;
    }

    return 0;
}

//TC = O(2*n) = O(n)
//SC = O(n)