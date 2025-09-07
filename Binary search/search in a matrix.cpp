//SEARCH IN A 2D MATRIX
//(using binary search)

//For the given 3x4 matrix: {{1,3,5,7}, {10,11,16,20}, {23,30,34,60}} and target=34.
//Return true if target is in matrix or false otherwise.
//Here, each row is sorted in ascending order.
//Also, The first int of each row is > than last int of prev row.

//This means that the el inside matrix are in sorted manner (as the value only keeps on increasing)

//Here mxn= 3x4 (is the size of matrix)

//TC: O(log(m*n))

//LOGIC:
//Check the first and last value of each row to see if the req target will lie in that row or not.
//Here, target=34, so in row 1, 1st val=1 and last val=7. as data is in asc order so 34 will never lie in this row.
//In row 2, 1st val=10 and last val=20. Again, 34 will not lie in this row.
//in row 3, 1st val=23 and last val=60. So 34 lies in this row.
//There will be a unique (single) row in which the target exists. target cannot occur in another row acc. to the condition given in q.

//To perform the above steps, using binary search.
//for a single row, apply BS from st=0 to end= m-1 (m = no. of rows)
//Find mid= st +(end-st)/2.
//for the given matrix, mid=1. So two case are possible- either mid row can be target row or mid row cannot be target row.
//matrix[mid][0] <= target <= matrix[mid][n-1]. (n = no. of cols).
//But if, target is not in mid row, then check if we need to go one row up or one row down to search.

//if target > matrix[mid][n-1], then st=mid+1. Means we need to go one row down to search.

//if target < matrix[mid][0], then end= mid-1.  Means we need to go one row up to search.

//Now to apply BS to the target row:
//st= matrix[mid][0] and end= matrix[mid][n-1].

#include <iostream>
#include <vector>
using namespace std;

bool searchInRow( vector <vector<int>> &matrix, int target, int row)
{
    int n= matrix[0].size(); //to find no. of cols (as we need to search a row so we only need no. of cols)

    int st=0, end= n-1;

    while(st<=end)
    {
        int mid= st+ (end-st)/2;

        if(target == matrix[row][mid])
        {
            //here "row" is the row which we had found using searchMatrix fn and "mid" is the col

            return true;
        }
        else if(target >matrix[row][mid])
        {
            st= mid+1; //to search in right side
        }
        else
        {
            end= mid-1; //to search in left side
        }
    }
    return false; //if target does not exist in matrix
}

bool searchMatrix(vector <vector<int>> &matrix, int target)
{
    //Apply BS on total no. of rows
    int m= matrix.size(); //to find no. of rows
    int n=matrix[0].size(); //to find no. of cols

    int startRow=0, endRow= m-1;

    while(startRow <= endRow)
    {
        int midRow = startRow + (endRow-startRow)/2;

        if(target >= matrix[midRow][0] && target <= matrix[midRow][n-1])
        {
            //means we have found the target row -> apply BS on this row
            return searchInRow(matrix, target, midRow);

        }
        else if(target >= matrix[midRow][n-1])
        {
            //means we have to go one row down (i.e to the right side)
            startRow = midRow+1;
        }
        else
        {
            //means we have to go one row up (i.e to the left side)
            endRow = midRow -1;
        }
    }
    return false;
}

int main()
{
    vector <vector <int>> matrix= {{1,3,5,7}, {10,11,16,20}, {23,30,34,60}};
    
    cout << searchMatrix(matrix, 34) <<endl; //target=34

    return 0;
}

