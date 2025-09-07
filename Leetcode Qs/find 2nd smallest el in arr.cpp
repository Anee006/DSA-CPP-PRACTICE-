#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector <int> arr = {32, 54, -6, -15};
    int n = arr.size();

    sort(arr.rbegin(), arr.rend()); //sorts in descending order

    for(int val : arr)
    {
        cout << val << " ";
    }

    cout << "\n2nd smallest element is : " << arr[n-2] <<endl;

    return 0;

    
}