// #notes
//N QUEENS 
//Using recursion

//The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
//Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.
//Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space.

//Input: n = 4
//Output: [[".Q..","...Q","Q...","..Q."], ["..Q.","Q...","...Q",".Q.."]]
//Explanation: There exist two distinct solutions to the 4-queens puzzle

#include <iostream>
#include <vector>
#include <string>
using namespace std;

//to check if we can place queen at a particular position
bool isSafe(vector<string>& board, int row, int col, int n)  //TC of isSafe() fn is: O(n)
{
    //to check horizontally:
    for(int j=0; j<n; j++)
    {
        if(board[row][j] == 'Q') //means a queen is already placed there
        {
            return false;
        }
    }

    //to check vertically:
    for(int i=0; i<n; i++)
    {
        if(board[i][col] == 'Q')
        {
            return false;
        }
    }

    //for checking left diagonal:
    for(int i=row, j=col; i>=0 && j>=0; i--, j--)
    {
        if(board[i][j] == 'Q')
        {
            return false;
        }
    }

    //for checking right diagonal:
    for(int i=row, j=col; i>=0 && j<n; i--, j++)
    {
        if(board[i][j] == 'Q')
        {
            return false;
        }
    }

    return true; //will be returned only if it is safe to place queen in all the four places

}

//recursive fn to place "n" queens in n rows
void nQueens(vector<string>& board, int row, int n, vector<vector<string>>& ans)
{
    //base case:
    if(row == n) //means we have placed all n queens in n rows
    {
        ans.push_back({board}); //making a vector and then pushing back
        return;
    }
    for(int j=0; j<n; j++)
    {
        if(isSafe(board, row, j , n)) //means it is safe to place queen here
        {
            board[row][j] = 'Q'; //placed queen at the pos
            nQueens(board, row+1, n , ans); //to place the next queen in next row

            board[row][j] = '.'; //backtracking step 
            //when the queen moves to next col for the next arrangement, we need to fill prev pos with '.' to indicate empty space
        }
    }
}

vector<vector<string>> solveNQueens(int n)
{
    //initialising board with '.' in the beginning
    vector<string> board(n, string(n, '.')); //creating a vector with "n" strings, and initialising each string of size n with '.'

    vector<vector<string>> ans;

    nQueens(board, 0, n, ans);
    return ans;
}

int main()
{
    vector<vector<string>> ans = solveNQueens(4); //value of n = 4

    // Print the result
    cout << "[";
    for (int i = 0; i < ans.size(); i++) 
    {
        cout << "[";
        for (int j = 0; j < ans[i].size(); j++) 
        {
            cout << "\"" << ans[i][j] << "\"";
            if (j < ans[i].size() - 1) 
                cout << ",";
        }
        cout << "]";
        if (i < ans.size() - 1) 
            cout << ", ";
    }
    cout << "]\n";
    return 0;
}