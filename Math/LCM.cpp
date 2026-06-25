// LCM of a and b

#include <iostream>
using namespace std;

int GCD(int a, int b) {
    while(a > 0 && b > 0) {
        if(a > b) a = a % b;
        
        else b = b % a;
    }

    if(a == 0) return b;
    return a;
}
// TC = O(log(min(a, b)))

int LCM(int a, int b) {
    int gcd = GCD(a,b);
    
    return (a * b) / gcd; // formula to find lcm
}
// TC = O(log(min(a, b)))

int main() {
    int a = 20, b = 28;

    cout << "GCD = " << GCD(a,b) << endl;
    cout << "LCM = " << LCM(a,b) << endl;

    return 0;
}

// can also use builtin fn to find LCM:
/*
int a=20, b=28;
cout << lcm(a,b);
*/