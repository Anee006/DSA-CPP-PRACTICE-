// #notes
//SPIRAL MATRIX Problem 
//TC: O(m*n)

//Given an m x n matrix, return all elements of the matrix in spiral order.
//Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
//Output: [1,2,3,6,9,8,7,4,5]

#include <iostream>
#include <vector>
using namespace std;

vector <int> spiralMatrix(vector <vector<int>> &matrix)
{
    int m= matrix.size(); //total no. of rows
    int n= matrix[0].size(); //total no. of cols
    int srow=0; //starting row
    int scol=0; //staring col
    int erow= m-1; //ending row
    int ecol= n-1; //ending col
    vector <int> ans; //for storing answer

    while(srow<=erow && scol<=ecol) //The reason for using && is that, which ever of "srow<=erow" or "scol<=ecol" is smaller, will be the controlling
                                    //factor
    {
        //to print top row/boundary
        for(int j=scol; j<=ecol; j++)
        {
            ans.push_back(matrix[srow][j]);
        }

        //for right boundary
        for(int i=srow+1; i<=erow; i++)
        {
            ans.push_back(matrix[i][ecol]);
        }

        //for bottom boundary
        for(int j=ecol-1; j>=scol; j--)
        {
            if(srow==erow) //if srow and erow are equal, then in case of odd sized matrix, to avoid duplicates, we break here.
            {
                break;  //the el would have already been printed by the top boundary so, we can break the bottom bdry here
            }
            ans.push_back(matrix[erow][j]); //if not an odd sized matrix, then only bottom row is printed separately
        }

        //for left boundary
        for(int i=erow-1; i>=srow+1; i--) 
        {
            if(scol==ecol) //if scol and ecol are equal, then in case of odd sized matrix, to avoid duplicates, we break here.
            {
                break;  //the el would have already been printed by the right boundary so, we can break the left bdry here
            }
            ans.push_back(matrix[i][scol]); //if not an odd sized matrix, then only left col is printed separately
        }

        srow++, scol++; erow--, ecol-- ; //updating them to go to the inner boundary and access its elements
    }
    return ans;
}

int main()
{
    vector <vector<int>> matrix={{1,2,3}, {4,5,6}, {7,8,9}};
    vector <int> ans= spiralMatrix(matrix);

    //to print the spiral matrix:
    for(auto val: ans)
    {
        cout<<val<<"\t";
    }
    cout<<endl;
    
    return 0;
    
}