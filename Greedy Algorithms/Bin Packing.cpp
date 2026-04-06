// Bin packing using First Fit

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> items = {4, 8, 1, 4, 2, 1};
    int capacity = 10;

    vector<int> bins;

    for(int item : items) {
        bool placed = false;

        for(int bin : bins) {
            if(bin + item <= capacity) {
                bin += item;
                placed = true;
                break;
            }
        }

        if(!placed) {
            bins.push_back(item);
        }
    }

    cout << "Bins used: " << bins.size() << endl;

    return 0;
}

// TC = O(n^2)