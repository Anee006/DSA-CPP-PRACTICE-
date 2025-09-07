//THE CELEBRITY PROBLEM

//Given a 2D array of size n x n such that, arr[i][j] = 1, means ith person knows jth person.
//The task is to find the celebrity.

//A celebrity is a person who is known to all but does not know anyone. Return the idx of the celebrity, if there is no celebrity return -1.

//arr = [[0,1,0], [0,0,0], [0,1,0]]

//since everyone (here, "i") knows celebrity so, arr[i][celebrity] = 1, for all values of i. (acc. to the condition of Q).
//But celebrity does not know anyone so, arr[celebrity][i] = 0, for all values of i.

//for arr = [[0,1,0], [0,0,0], [0,1,0]]. 
//for idx = 0 (row wise), we have [0,1,0]. Since there exists "1" in this row, means it knows a celebrity. So, idx = 0 cannot be a celebrity.
//for idx = 1 (row wise), we have [0,0,0]. Since there exists only "0" in this row, means it knows none. So, idx = 1 is a celebrity.
//for idx = 2 (row wise), we have [0,1,0]. Since there exists "1" in this row, means it knows a celebrity. So, idx = 2 cannot be a celebrity.

//LOGIC:
//arr[i][j] can have only 2 values - 0 or 1.
//if arr[i][j] = 0, means ith person does not know jth person. since no one know jth person so, it can't be a celebrity. Hence eliminate j.
//if arr[i][j] = 1, means ith person knows jth person. Since celebrity does not know anyone so, eliminate "i". i can never be a celebrity.

//start analysing the above conditions in pairs. Like first analyse taking idx = 0 and idx = 1 as a pair.
//so now arr[i][j] becomes arr[0][1]. Since in the given array, arr[0][1] = 1, so eliminate idx = 0.

//now we only have idx = 1 and idx = 2 left as a pair.
//so now arr[i][j] becomes arr[1][2]. Since in the given array, arr[1][2] = 0, means "1" does not know "2". so eliminate idx = 2, as it can 
//never be a celebrity.

//now we only have a single index left which is idx = 1, which may or may not be a celebrity.
//when we are left with only a single idx check these two conditions:
//1. arr[i][celebrity] = 1,  for all i
//2. arr[celebrity][i] = 0, for all i

//TO PICK PAIRS OF i AND j USE STACK:
//insert all values in stack from 0 to n-1.
//start popping pair of values, one by one.
//then push that value which can become the celebrity, out of the pair which we had popped earlier.
//repeat till we have only a single el left in stack.

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int getCelebrity(vector<vector<int>>& arr)
{
    int n = arr.size();
    stack<int> s;

    for(int i=0; i<n; i++)
    {
        s.push(i); //to push all index values into the stack
    }
    
    while(s.size() > 1) //min two elements should be there in stack for this loop to run
    {
        int i = s.top(); //ith value
        s.pop();

        int j = s.top(); //jth value
        s.pop();

        //deciding which idx to eliminate
        if(arr[i][j] == 0)
        {
            s.push(i); //to eliminate j, we are pushing i
        }
        else
        {
            s.push(j); //to eliminate i, we are pushing j 
        }
    }

    //at the end of the loop we know that size of stack will be either 1 or lesser than 1. So we can find celebrity
    int celebrity = s.top();

    for(int i=0; i<n; i++)
    {
        //check for these conditions: arr[i][celebrity] = 1, arr[celebrity][i] = 0.
        if( (i != celebrity) && (arr[i][celebrity] == 0 || arr[celebrity][i] == 1)) //need to also include (i != celebrity)
        {
            return -1; //means is not a celebrity
        }
    }
    return celebrity; //means is a celebrity, so returns its idx
}

int main()
{
    vector<vector<int>> arr = {{0,1,0}, {0,0,0}, {0,1,0}};

    cout << "Celebrity is: " << getCelebrity(arr) << endl;

    return 0;
}

//TC = O(n)
//SC = O(n)