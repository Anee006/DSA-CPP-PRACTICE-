// to check if a no. is a power of 2 (like 2, 4, 8 etc are powers of 2) using & operator

#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter num: ";
    cin >> n;

    if((n & (n-1)) == 0) cout << "IS a power of 2";
    else cout << "NOT a power of 2";

    return 0;
}