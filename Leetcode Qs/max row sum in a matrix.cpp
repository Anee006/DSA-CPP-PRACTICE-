//MAXIMUM ROW SUM

//If we have a 2d matrix: {{1,2,3}, {4,5,6}, {7,8,9}}.
//Sum of elements of 1st row= 1+2+3 = 6
//Sum of elements of 2nd row= 4+5+6 = 15
//Sum of elements of 3rd row= 7+8+9 = 24
//max of the 3 sums is 24, so the ANS IS 24.

#include <iostream>
using namespace std;

int maxRowSum(int matrix[3][3], int rows, int cols)
{
    int MaxRowSum= INT_MIN;

    for(int i=0; i<rows; i++)
    {
        int rowSum=0;
        for(int j=0; j<cols; j++)
        {
            rowSum += matrix[i][j]; //to calc sum of each row (i.e, of the i'th row)
        }

        MaxRowSum= max(MaxRowSum, rowSum); //the max of the two will be stored, which will be the ans
    }
    return MaxRowSum; //req max sum
}


int main()
{
    int matrix[3][3]= {{1,2,3}, {4,5,6}, {7,8,9}};
    int rows=3;
    int cols=3;

    cout<< maxRowSum(matrix,rows,cols)<<endl;

    return 0;
}