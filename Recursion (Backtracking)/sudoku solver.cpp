// #notes
//SUDOKU SOLVER 
//Using recursion

//Write a program to solve a Sudoku puzzle by filling the empty cells.
//A sudoku solution must satisfy all of the following rules:

//1. Each of the digits 1-9 must occur exactly once in each row.
//2. Each of the digits 1-9 must occur exactly once in each column.
//3. Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
//The '.' character indicates empty cells.

//Input: board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],
//["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],
//[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]


//Output: [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],
//["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],
//["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]

#include <iostream>
#include <vector>
using namespace std;

//fn to check if is safe to place digit at a particular position
bool isSafe(vector<vector<char>>& board, int row, int col, char digit)
{
    //to check horizontally
    for(int j=0; j<9; j++)
    {
        if(board[row][j] == digit)
            return false;  //means digit already exists in that row
    }

    //to check vertically
    for(int i=0; i<9; i++)
    {
        if(board[i][col] == digit)
            return false;  //means digit already exists in that row
    }

    //to check the nine, 3x3 sub grids that we have
    int srow= (row/3) * 3; //to calculate starting row of grid
    int scol= (col/3) * 3; //to calculate starting column of grid

    for(int i=srow; i <= srow+2; i++) //TC of this for loop is: O(9) which is const TC. Bcoz only works on the 3*3 grid.
    {
        for(int j=scol; j <= scol+2; j++)
        {
            if(board[i][j] == digit) //means dig already exists in the grid
                return false;
        }
    }
    return true; //is returned only if it passes all the three rules. 
}

//helper fn to solve sudoku
bool sudokuSolver(vector<vector<char>>& board, int row, int col)
{
    if(row ==9)
    {
        return true; //means the sudoku is solved and our placement of digits is correct
    }

    int nextRow = row;
    int nextCol = col+1; //on moving in the same row, horizontally: the row remains same but col inc by 1
    if(nextCol == 9)
    {
        nextRow = row+1;
        nextCol = 0;  //to go to the first cell of the next row

    }

    if(board[row][col] != '.') //means a digit already exists at that place
    {
        return sudokuSolver(board, nextRow, nextCol);
    }

    //if digit does not already exist: place digit at correct place
    for(char digit='1'; digit<='9'; digit++)
    {
        if(isSafe(board, row, col, digit)) //means it is safe to place digit at that place
        {
            board[row][col] = digit;
            if(sudokuSolver(board, nextRow, nextCol)) //if this fn returns true, we'll also return true
            {
                return true;
            }
            board[row][col] = '.'; //if the above case does not run i.e, if true is not returned then, we replace dig with empty space- '.'
        }
    }
    return false; //runs when we are unable to find any valid ans
}

void solveSudoku(vector<vector<char>>& board) //digits from 1-9 have been treated as char in this board
{
    sudokuSolver(board, 0, 0);
}

int main()
{
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    solveSudoku(board);

    //to display output:
    for (const auto& row : board) {
        cout << "[";
        for (size_t i = 0; i < row.size(); ++i) {
            cout << "\"" << row[i] << "\"";
            if (i < row.size() - 1) cout << ",";
        }
        cout << "],\n";
    }

    return 0;
}

//TC = O(9 ^ no. of empty cells)