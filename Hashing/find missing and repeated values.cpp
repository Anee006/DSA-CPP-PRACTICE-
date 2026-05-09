//FIND MISSING AND REPEATED VALUES problem

//You are given a 0-indexed 2D integer matrix grid of size n * n with values in the range [1, n^2]. Each integer appears exactly once except 'a'
// which appears twice and 'b' which is missing. The task is to find the repeating and missing numbers a and b.

//Return a 0-indexed integer array ans of size 2 where ans[0] equals to a and ans[1] equals to b.

//Input: grid = [[9,1,7],[8,9,2],[3,4,6]] //Here n=3, so n^2=9
//Output: [9,5]
//Explanation: Number 9 is repeated and number 5 is missing so the answer is [9,5].

//LOGIC for repeating value:
//Traverse the vector and start storing each el in an unordered_set. If a val already exists in the set, it is the repeated value.

//LOGIC for missing value:
//We know arithmetic sum of all numbers from 1 to n = [n*(n+1)]/2
//So sum of numbers from 1 to n*n = [(n*n) * ((n*n) + 1)]/2.
//For the given vector, expected sum= 1+2+3+4+5+6+7+8+9 =45
//Now, we have done: "expected sum + a - b". i.e, in the expected sum we have added 'a' which is the repeated value and we have subtracted 'b'.
//This, "expected sum + a - b" gives us the actual sum of elements that are present in the grid rn.

//Sum of elements present in the grid = 9+1+7+8+9+2+3+4+6 = 49
//"expected sum + a - b" = 45 + 9 - 5 = 49

//So  from: "expectedSum + a - b = actualSum" we get,
// b = expectedSum - actualSum + a.

//So using the formula, for the given vector, b = 45 - 49 + 9 = 5.


#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> findMissingAndRepeatedValues(vector <vector<int>>& grid)
{
    vector <int> ans;
    unordered_set <int> s;
    int n= grid.size();
    int a,b;

    int expSum=0; //this is for the expected sum of numbers from 1 to n^2
    int actualSum=0; //this is for the actual sum of numbers present in the grid

    for(int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            actualSum += grid[i][j]; //for calc actual sum

            //for the repeated value:
            if(s.find(grid[i][j]) != s.end()) //if true, means val already exists in the set
            {
                a= grid[i][j];
                ans.push_back(a);
            }
            s.insert(grid[i][j]); //insert elements into set
        }
    }
    //calculating 'expSum', as we already found 'a' and 'actualSum'
    expSum = (n*n) * (n*n +1)/2;
    b= expSum + a - actualSum;
    ans.push_back(b);

    return ans;
}

int main()
{
    vector <vector <int>> grid= { {9,1,7}, {8,9,2}, {3,4,6} };

    vector <int> ans = findMissingAndRepeatedValues(grid);

    for(auto val: ans)
    {
        cout<<val<<" ";
    }
    cout<<endl;
    
    return 0;

}