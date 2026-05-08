// Is used to find prime numbers in a range (1 to n)

#include <iostream>
#include <vector>
using namespace std;

vector<int> sieve(int n) {
    vector<bool> isPrime(n + 1, true); // create boolean arr

    for(int i = 2; i*i <= n; i++) {
        if(isPrime[i]) {

            // mark as false
            for(int j = i * i; j <= n; j += i) isPrime[j] = false;
        }
    }

    vector<int> res;

    for(int i = 2; i <= n; i++) {
        if(isPrime[i]) {
            res.push_back(i); // add prime no. to the list
        }
    }
    return res;
}

int main() {
    int n = 11;

    vector<int> res = sieve(n);
    for(int el : res) cout << el << " "; // prints prime numbers from 1 to 11

    return 0;
}