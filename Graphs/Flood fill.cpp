// #newnotes
// FLOOD FILL (LeetCode 733)
// using DFS of graphs

// You are given an image represented by an m x n grid of integers "image", where image[i][j] represents the pixel value of the image. 
// You are also given three integers sr, sc, and color. Your task is to perform a flood fill on the image starting from the pixel image[sr][sc]

// To perform a flood fill:
/*
- Begin with the starting pixel and change its color to "color".
- Perform the same process for each pixel that is directly adjacent (pixels that share a side with the original pixel, either horizontally or vertically) and shares the same color as the starting pixel.
- Keep repeating this process by checking neighboring pixels of the updated pixels and modifying their color if it matches the original color of the starting pixel.
- The process stops when there are no more adjacent pixels of the original color to update.
*/

// Return the modified image after performing the flood fill.


// Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2
// Output: [[2,2,2],[2,2,0],[2,0,1]]


// LOGIC:
// imagine each cell of image as a node of a graph.
// change color of starting cell and perform DFS.

#include <iostream>
#include <vector>
using namespace std;

// to change color of starting node and its neighbor using DFS
void DFS(vector<vector<int>>& image, int i, int j, int newColor, int orgColor) // sr = i and sc = j here
{

    // base case:
    // (image[i][j] == newColor) --> if cell color is already changed with new color then do not visit that cell again. This is to avoid getting stuck in a loop.
    // (image[i][j] != orgColor) --> if cell color does not match the color of the starting cell i.e, original color, then do not change its color.
    if(i < 0 || j < 0 || i >= image.size() || j >=image[0].size() || image[i][j] == newColor || image[i][j] != orgColor)
    {
        return;
    }
    
    image[i][j] = newColor; // change color of starting node to new color

    // call neighbors of "start" node
    DFS(image, i-1, j, newColor, orgColor); // for top neighbor
    DFS(image, i, j+1, newColor, orgColor); // right
    DFS(image, i+1, j, newColor, orgColor); // bottom
    DFS(image, i, j-1, newColor, orgColor); // left

}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color)
{
    DFS(image, sr, sc, color, image[sr][sc]); // color --> newColor and (image[sr][sc]) --> original color of starting node

    return image;
}

int main()
{
    int sr = 1; // starting row
    int sc = 1; // starting column
    int color = 2;

    vector<vector<int>> image = {
        {1,1,1},
        {1,1,0},
        {1,0,1}
    };

    vector<vector<int>> ans = floodFill(image, sr, sc, color);

    cout << "Updated image:\n";

    for(int i=0; i<image.size(); i++) // for rows
    {
        for(int j=0; j<image[0].size(); j++) // for cols
        {
            cout << image[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}