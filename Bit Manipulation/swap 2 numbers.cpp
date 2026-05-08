// to swap 2 numbers using bit manipulation

#include <iostream>
using namespace std;

int main() {
    int a, b;
    cout << "Enter 2 numbers: ";
    cin >> a >> b;

    // swap numbers using XOR
    a ^= b;
    b ^= a;
    a ^= b;

    cout << "\nAfter swapping, numbers are: " << a << " " << b;
    
    return 0;
}