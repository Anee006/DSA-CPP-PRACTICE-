// to check if a no. is even or odd using bit manipulation

// LOGIC:
// check the last bit of the number: 
// - even nums end with 0 in binary 
// - odd nums end with 1 in binary

#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number: ";
    cin >> n;

    if(n & 1) cout << n << " is odd"; // if last bit is 1 --> odd no.

    else cout << n << " is even";

    return 0;
}

// TC = O(1) , SC = O(1)