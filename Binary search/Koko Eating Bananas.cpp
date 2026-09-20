// LeetCode 875

// Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours. 
// Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. 
// If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.
// Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.
// Return the minimum integer k such that she can eat all the bananas within h hours.

// Input: piles = [30,11,23,4,20], h = 5
// Output: 30

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minEatingSpeed(vector<int>& piles, int h) {
    int low = 1; // min possible eating speed
    int high = *max_element(piles.begin(), piles.end()); // max possible eating speed

    int ans = high;

    while(low <= high) {
        int k = low + (high - low) / 2; // find middle eating speed

        long long hours = 0; // calculate no. of hours req at speed k // calculate exactly how many hours Koko needs

        for(int bananas: piles) {
            hours += (bananas + k - 1) / k;  // is equivalent to: ceil((double)bananas / k)
        }

        if(hours <= h) { // if Koko can finish within h hours
            ans = k; // k is a possible ans

            high = k - 1; // try a smaller speed (as we need to find the min speed)
        }

        else low = k + 1; // speed is too slow, increase it
    }
    return ans;
}

int main() {
    vector<int> piles = {30, 11, 23, 4, 20};

    int h = 5;

    cout << minEatingSpeed(piles, h);

    return 0;
}

// TC = O(log n)
// SC = O(1)