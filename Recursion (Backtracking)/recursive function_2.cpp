// to create a recursive function to calculate sum of digits of a number
#include <iostream>
using namespace std;

int sum_of_digits(int);

int main() {
    int n;
    cout << "Enter a 3 digit number: ";
    cin >> n;
    cout << "Sum of digits is: " << sum_of_digits(n) << endl;
    return 0;
}

// number % 10 gives the last digit
// number / 10 gives the first two digits
// number % 10 gives the second digit
// number / 10 gives the first digit.
int sum_of_digits(int num) {
    if(num == 0) return 0;  // base case                                                                  
    
    return num % 10 + sum_of_digits(num / 10); 
}