// LeetCode 3870

// You are given an integer n.
// Return the total number of commas used when writing all integers from [1, n] (inclusive) in standard number formatting.
// In standard formatting:
// A comma is inserted after every three digits from the right. Numbers with fewer than 4 digits contain no commas.

// Input: n = 1002
// Output: 3
// Explanation: The numbers "1,000", "1,001", and "1,002" each contain one comma, giving a total of 3

// LOGIC:
// Numbers < 4 digits have 0 commas. Numbers with 4-6 dig have 1 comma, Nums with 7-9 dig have 2 commas and so on.
// A new comma is added after every 3 digits. So 1st comma is need for 1000 and next comma will be needed after a factor of 1000.
// So (power = 1000) will be 1st num for which we need comma and so nums from power to (1000* power - 1) will have commas. Count these.

#include <iostream>
using namespace std;

int countCommas(int n) {
    int total = 0; // stores final comma count
    int power = 1000;
    int commas = 1; // stores no. of commas used for a range (eg: from 4-6)

    while (power <= n) {
        int end = 1000 * power - 1;

        if(end > n) end = n;

        int count = end - power + 1; // gives the count of nums in the range 

        total += count * commas; // total commas needed for that range

        power *= 1000; // commas added after a factor of 1000 (i.e 3 digits)

        commas++; // no. of commas inc by +1 for next range
    }

    return total;
}

int main() {
    int n = 1002;

    cout << countCommas(n);

    return 0;
}

// TC = O(loh n)
// SC = O(1)