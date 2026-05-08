// to print the binary number for a decimal number

// DRY RUN OF CODE:
// n = 5
// 5 > 0 --> while loop runs
// 5 % 2 = 1  so, binary = '1' + "" (converts 1 to char)
// binary = "1"
// 5 / 2 = 2.5 = 2
// n = 2
// 2 > 0 --> while loop runs
// 2 % 2 = 0  so, binary = '0' + "1" --> "01"
// 2 / 2 = 1
// n = 1
// 1 > 0 --> while loop runs
// 1 % 2 = 1  so, binary = '1' + "01" --> "101"
// n = 1 / 2 = 0 --> EXIT WHILE LOOP

#include <iostream>
using namespace std;

void printBinary(int n) {
    string binary = "";

    while(n > 0) {
        binary = char((n % 2) + '0') + binary;
        n /= 2;
    }
    cout << "Binary repr: " << binary << endl;
}

int main() {
    int n = 5;
    printBinary(n); // prints 101
    return 0;
}

// TC = O(k ^ 2) , where k = no. of bits