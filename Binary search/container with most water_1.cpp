// LeetCode 11
// using Brute Force approach: We find out all possible containers and find the amt of water each container can store. Then we find the max amt.
// TC: O(n^2). "Gives TLE".

// NOTE: Use 2 pointer approach for optimized TC

// We have been given the height of n lines, height= {1,8,6,2,5,4,8,3,7}. 
// Imagine these lines as a container now. 
// Return the max amount (area) of water container can store.

// to make a container we need two lines. One acts as the left boundary of the container and the other acts as the right boundary.

#include <iostream>
#include <vector>
using namespace std;

int maxArea(vector<int>& height) {
    int maxWater = 0; 
    int n = height.size(); 

    for(int i=0; i<n; i++) // for fixing the left boundary of the container
    {
        for(int j = i+1; j<n; j++) // for fixing the right bdry of the container. Starting from i+1 as to make a container we need two diff lines
        {
            int width = j-i; // width of the container
            int ht = min(height[i], height[j]); // height of the container will be the one with the min height out of the two.
            int area = width * ht; // area of the current container
            maxWater = max(maxWater, area); // Max of the two will be the ans
        }
   }
   return maxWater;
}

int main() {
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    cout << "Max water that can be stored is: " << maxArea(height) << endl;

    return 0;
}