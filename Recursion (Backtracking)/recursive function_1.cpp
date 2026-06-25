// recursive fn to find factorial of n

#include <iostream>
using namespace std;

int factorial (int);

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Factorial of " << n << " is: " << factorial(n) << endl;
    return 0;
}

// factorial is the recursive function.
// process of a function calling itself repeatedly till base condition is reached is called recursion.
int factorial (int x) {                          
    if(x == 1 || x == 0) return 1; // base condition

    return x * factorial(x-1);
}