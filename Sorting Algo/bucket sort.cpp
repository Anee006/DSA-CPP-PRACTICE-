#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void bucketSort(vector<double>& arr)
{
    int n = arr.size();
    vector <vector<double>> buckets(n); //creating buckets of size n

    for(int i=0; i<n; i++)
    {
        int index = n * arr[i]; //the index where the element will be placed is given by (n* val of element)
        if(index == n) index = n-1; //for checking out of range values. Our range is [0,1)

        buckets[index].push_back(arr[i]); //pushing the element in the bucket at its correct index
    }

    for(int i=0; i<n; i++)
    {
        sort(buckets[i].begin(), buckets[i].end()); //to sort the bucket
    }

    int k = 0;
    for(int i=0; i<n; i++)
    {
        for(double val: buckets[i])
        {
            arr[k++] = val;
        }
    }
}

int main()
{
    vector<double> arr = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};

    bucketSort(arr);

    cout << "After sorting: " << endl;
    for(double val: arr)
    {
        cout << val << "\t";
    }
    cout << endl;

    return 0;
}