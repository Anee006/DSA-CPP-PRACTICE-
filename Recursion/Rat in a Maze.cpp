//RAT IN A MAZE:
//Using recursion

//Tip: Use recursion when we want to explore all the possible paths/ solutions of a Q, like in Sudoku solver or n Queens problem.

//we have a maze: [[1,0,0,0], [1,1,0,1], [1,1,0,0], [0,1,1,1]]
//if we are starting from first cell i.e 1 at the top left (i.e, (0,0) cell) and going till the last cell that is 1 bottom right (i.e, (n-1, n-1) cell).
//what are the number of possible ways in which we can reach the end?

//conditions: 1. from a cell we can either go one up(U), one down(D), one left(L) or one right(R)
//2. We cannot  go on cell containing zero.
//3. we can visit each cell only once.
//4. we can not go out of the boundary of the maze

//so there are only two paths possible which satsify all the given conditions: DRDDRR and DDRDRR

//A cell has r rows and n columnns.
//Condition for U is: (r-1,c)
//Condition for D is: (r+1,c)
//Condition for L is: (r,c-1)
//Condition for R is: (r,c+1)

//NOTE:
//If the 1st cell in the maze i.e, (0,0) cell or the last cell in the maze i.e, (n-1, n-1) was 0, then no solution would have existed for this Q,
//bcoz, acc to the conditions, we can't go on a cell with 0.


//NOTE: 
//If we land on a cell having 0 in it, means that the cell is already visited, i.e, we cannot visit that cell.
//If we land on a cell having 1 in it, means we have reached a free space, i.e, it is an unvisted cell for now.

#include <iostream>
#include <vector>
using namespace std;

void helper(vector <vector<int>> &maze, int r, int c, string path, vector <string> &ans)
{
    int n=maze.size(); //size of given maze

    if(r<0 ||c <0|| r>=n || c>=n || maze[r][c]==0 || maze[r][c]== -1) // the first four conditions impose the boundary conditions. 
    {                                                                //the second last condition means we cannot go on cell having zero in it   
        return;                                                      ////the last condition imposes that we do not need to visit a cell again
    }

    if(r==n-1 && c==n-1) //means we have reached the last cell of maze and found our ans
    {
        ans.push_back(path);
        return;
    }


    maze [r][c]= -1; //means visited the cell //means visited = true //means the cell need not be visited again as it has already been visited.

    helper(maze, r+1, c, path+ "D", ans); //for down
    helper(maze, r-1, c, path+ "U", ans); //for up
    helper(maze, r, c-1, path+ "L", ans); //for left
    helper(maze, r, c+1, path+ "R", ans); //for right

    maze [r][c]= 1; //unvisited the cell //This is backtracking step --> so that we can revisit a cell and find other solutions.

    //backtracking always happens after recursive call
}

vector <string> findPath(vector <vector<int>> &maze) //creating a 2D vector for the maze
{
    vector <string> ans;
    string path=""; 

    helper(maze,0,0,path,ans);

    return ans;

}

int main()
{
    vector <vector<int>> maze = {{1,0,0,0}, {1,1,0,1}, {1,1,0,0}, {0,1,1,1}};
    vector <string> ans = findPath (maze);
    for( string path: ans)
    {
        cout<<path<<endl;
    }

    return 0;

}

//TC = O(4 ^ (n*n)),
//as for a n*n matrix, total no. of cells = n*n and for each cell we can take total 4 choices of up,down,left or right.