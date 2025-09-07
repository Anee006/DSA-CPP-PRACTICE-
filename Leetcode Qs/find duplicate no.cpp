// #notes
//FIND DUPLICATE NUMBER 
//Using slow-fast pointer approach- Is used for cycle detection in linked list.
//TC= O(1) ans SC= O(1).

//Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
//There is only one repeated number in nums, return this repeated number.
//You must solve the problem without modifying the array nums and using only constant extra space.

//Input: nums = [3,1,3,4,2]
//Output: 3
//Here, n=4, so size = n+1 = 5. Here the duplicate el is 3.

//We can solve this Q using unordered_set but, the TC will be O(n) and the SC will also be O(n). Since we need O(1) SC, can't use this.

#include <iostream>
#include <vector>
using namespace std;

int findDuplicate(vector <int>& arr)
{
    //initialising both slow and fast with arr[0] so, initially both are pointing at same location
    int slow= arr[0];
    int fast= arr[0];

    do //using do-while loop here, as we can't check condition in the beginning, since both are at same location
    {
        slow= arr[slow]; //increasing slow ptr by +1
        fast = arr[arr[fast]]; //increasing fast ptr by +2
    }while(slow!=fast);

    slow= arr[0]; //re-initialise slow to the beginning

    while(slow != fast)
    {
        slow = arr[slow]; //increasing both slow and fast pointers by +1
        fast = arr[fast];
    }

    return slow; //can also return fast here, as both are poiting to the duplicate value now
}

int main()
{
    vector <int> arr= {3,1,3,4,2};
    cout<< findDuplicate(arr) <<endl;
    return 0;
}