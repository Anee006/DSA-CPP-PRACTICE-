// LeetCode 48

// You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
// You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. 

/*
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]

Explanation:
Original:
[ 1, 2, 3 ]
[ 4, 5, 6 ]
[ 7, 8, 9 ]

Transpose (swap matrix[i][j] with matrix[j][i])
[ 1, 4, 7 ]
[ 2, 5, 8 ]
[ 3, 6, 9 ]

Reverse each row
[ 7, 4, 1 ]
[ 8, 5, 2 ]
[ 9, 6, 3 ]
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void rotate(vector<vector<int>>& matrix) {
}

int main() {
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    rotate(matrix);

    for(int i = 0; i < matrix.size(); i++) {
        for(int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}