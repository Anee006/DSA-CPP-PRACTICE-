//DIAGONAL COLUMN SUM (with equal rows and cols i.e, it is a square matrix)
//So we can take "n" as the no. of rows and cols

//TC of code: O(n) , OPTIMISED

//If we have a 2d matrix: {{1,2,3}, {4,5,6}, {7,8,9}}.
//Sum of Primary diagonal = 1+5+9 = 15
//Sum of secondary diagonal = 3+5+7 =15
//Sum of both diagonals after subtracting common el (in this case: 5) = 15+15-5 = 25

//NOTE: we get a common el in case of square matrix with odd no. of rows/cols. 
//if n is even then we don't have common el, so can add both diagonals normally

//In the given matrix, cells of primary diagonal are: (0,0), (1,1), (2,2).
//So, for a primary diagonal (PD) in a matrix[i][j], i==j, is the condition.

//For the Secondary diagonal (SD), its cells are: (0,3), (1,2), (2,1).
//As the value of i increases, the value of j decreases.
//The SD starts from cell (0, n-1) where n is the length of row.
//Condition for SD is: j=(n-1)-i


#include <iostream>
using namespace std;

int diagonalSum(int matrix[][3], int n) //TC of code: O(n*n)
{
    int sum=0;

    for(int i=0 ; i<n ; i++)
    {
        sum += matrix[i][i]; //for PD: j=i

        if(i != n-1-i) //this is to ensure that the common value (in this case 5) is not added twice in the sum
        {
            sum+= matrix[i][n-1-i];
        }  
    }
    return sum;
}


int main()
{
    int matrix[3][3]= {{1,2,3}, {4,5,6}, {7,8,9}};
    int n=3;

    cout<< diagonalSum(matrix,n) <<endl;

    return 0;
}