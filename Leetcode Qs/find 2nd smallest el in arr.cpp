#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector <int> arr = {32, 54, -6, -15};
    int n = arr.size();

    if(arr.size() < 2) {
        cout << "Array must contain atleast 2 elements\n";
        return 0;
    }

    int smallest = INT_MAX;
    int secSmallest = INT_MAX;

    for(int num : arr) {
        if(num < smallest) { // found a new smaller el
            secSmallest = smallest;
            smallest = num;
        }

        else if(num < secSmallest && num != smallest) { // found a new 2nd smallest el
            secSmallest = num;
        }

    }

    if(secSmallest == INT_MAX) cout << "Second smallest element does not exist\n";

    else cout << "2nd smallest element is: " << secSmallest << endl;

    return 0;    
}

// TC = O(n)
// SC = O(1)