//radix sort

#include <iostream>
using namespace std;


//counting sort algo
void countingSort(int arr[], int n, int pos)
{
    int output[10]; //as we have only 10 elements in the given array.
    int count[10] = {0} ; //to store count from 0-9 for each element

    //count occurences of each digit, normally
    for(int i=0; i<n; i++)
    {
        count[(arr[i]/pos) % 10]++;
    }

    //convert the count to cumulative count (i.e add count of current element with the count of its prev element)
    for(int i=1; i<10; i++)
    {
        count[i] += count[i-1];
    }

    //build the output array: by traversing backwards
    for(int i = n-1; i>= 0; i--)
    {
        output[--count[(arr[i]/pos) % 10]] = arr[i];
    }

    //copy output back to original array
    for(int i=0; i<n; i++)
    {
        arr[i] = output[i];
    }

}

//to get the max element from the array
int getMax(int arr[], int n)
{
    int maxValue = arr[0];
    
    for(int i=0; i<n; i++)
    {
        if(arr[i] > maxValue)
        {
            maxValue = arr[i];
        }
    }
    return maxValue;
}

void radixSort(int arr[], int n)
{
    int maxValue = getMax(arr,n); //to get the maxValue present in the given array

    //sort for every digit (for digit at 1s place, digit at 10s place, digit at 100s place and so on)
    for(int pos = 1; maxValue/pos > 0; pos *= 10)
    {
        countingSort(arr,n,pos); //radix sort is internally a counting sort only
    }
}

void print(int arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
}

int main()
{
    int arr[] = {432, 8, 530, 90, 88, 231, 11, 45, 677, 199};
    int n = 10;

    cout << "orginal array:\n";
    print(arr,n);

    radixSort(arr,n);
    cout << "\nAfter sorting:\n";
    print(arr,n);

    return 0;
    
}