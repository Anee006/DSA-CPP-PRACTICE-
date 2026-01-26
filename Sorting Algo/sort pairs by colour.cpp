// we are given n pairs of items as input, where the first item is a number and the second item is one of three colours (red, blue, or yellow). 
// Further assume that the items are sorted by number.
// Give a O(n) algorithm to sort the items by colour (all reds before all blues before all yellows) such that the numbers for identical colours stay sorted.

// Input: (1, blue), (3, red), (4, blue), (6, yellow), (9, red)
// Output: (3, red), (9, red), (1, blue), (4, blue), (6, yellow)

#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Item {
    int number;
    string color;
};

vector<Item> colorSort(vector<Item>& items) {
    vector<Item> reds, blues, yellows;

    for(auto i: items) {
        if(i.color == "red") {
            reds.push_back(i);
        } else if(i.color == "blue") {
            blues.push_back(i);
        } else if(i.color == "yellow") {
            yellows.push_back(i);
        }
    }

    // concatenate the 3 lists:
    vector<Item> sortedItems;
    sortedItems.insert(sortedItems.end(), reds.begin(), reds.end());
    sortedItems.insert(sortedItems.end(), blues.begin(), blues.end());
    sortedItems.insert(sortedItems.end(), yellows.begin(), yellows.end());

    return sortedItems;
}
// O(n) time and stable

int main() {
    vector<Item> items = {{1, "blue"}, {3, "red"}, {4, "blue"}, {6, "yellow"}, {9, "red"}};

    vector<Item> res = colorSort(items);

    for(auto item: res) {
        cout << "(" << item.number << ", " << item.color << ") ";
    }

    return 0;
}


