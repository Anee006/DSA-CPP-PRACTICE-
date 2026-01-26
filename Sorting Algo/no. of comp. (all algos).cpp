// To print the total number of comparisons done in each of the sorting algorithm.
// (selection sort, bubble sort, insertion sort, quick sort and merge sort).

#include <iostream>
#include <vector>
using namespace std;

int bubbleSort(vector<int> arr) {
    int comparisons = 0;
    int n = arr.size();

    for(int i=0; i<n-1; i++) {
        for(int j=0; j<n-i-1; j++) {
            comparisons++;
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
    return comparisons;
}

int selectionSort(vector<int> arr) {
    int comparisons = 0;
    int n = arr.size();

    for(int i=0; i<n-1; i++) {
        int minIdx = i;

        for(int j=i+1; j<n; j++) {
            comparisons++;
            if(arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        swap(arr[i], arr[minIdx]);
    }
    return comparisons;
}

int insertionSort(vector<int> arr) {
    int comparisons = 0;
    int n = arr.size();

    for(int i=1; i<n; i++) {
        int curr = arr[i];
        int prev = i-1;

        while(prev >= 0) {
            comparisons++;
            if(arr[prev] > curr) {
                arr[prev+1] = arr[prev];
                prev--;
            }
            else break;
        }
        arr[prev+1] = curr;
    }
    return comparisons;
}

int quickComparisons; // to track no. of comparisons in quick sort

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // choosing last el as pivot
    int i = low-1;

    for(int j = low; j<high; j++) {
        quickComparisons++;
        if(arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return i+1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if(low < high) {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot-1);
        quickSort(arr, pivot+1, high);
    }
}

int quickSortWrapper(vector<int> arr) {
    quickComparisons = 0;
    quickSort(arr, 0, arr.size()-1);
    return quickComparisons;
}

int mergeComparisons; // to track no. of comparisons in merge sort

void merge(vector<int>& arr, int low, int mid, int high) {
    vector<int> temp;
    int i=low, j = mid+1;

    while(i <= mid && j <= high) {
        mergeComparisons++;

        if(arr[i] <= arr[j]) {
            temp.push_back(arr[i++]);
        }
        else {
            temp.push_back(arr[j++]);
        }
    }

    while(i <= mid) {
        temp.push_back(arr[i++]);
    }
    while(j <= high) {
        temp.push_back(arr[j++]);
    }

    for(int idx = 0; idx < temp.size(); idx++) {
        arr[idx + low] = temp[idx];
    }
}

void mergeSort(vector<int>& arr, int low, int high) {
    if(low < high) {
        int mid = low + (high-low)/2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }
}

int mergeSortWrapper(vector<int> arr) {
    mergeComparisons = 0;
    mergeSort(arr, 0, arr.size()-1);
    return mergeComparisons;
}

int main() {
    vector<int> arr = {10, -1, 1, 233, 100};

    // No. of comparisons when array is unsorted:
    cout << "Selection Sort comparisons: " << selectionSort(arr) << endl;

    cout << "Bubble Sort comparisons: " << bubbleSort(arr) << endl;

    cout << "Insertion Sort comparisons: " << insertionSort(arr) << endl;

    cout << "Quick Sort comparisons: " << quickSortWrapper(arr) << endl;

    cout << "Merge Sort comparisons: " << mergeSortWrapper(arr) << endl;

    // to sort the array:
    quickSort(arr, 0, arr.size()-1);

    cout << "\nNo. of comparisons for sorted array: [ ";
    for(int i : arr) cout << i << " ";
    cout << "]\n";

    cout << "Selection Sort comparisons: " << selectionSort(arr) << endl;

    cout << "Bubble Sort comparisons: " << bubbleSort(arr) << endl;

    cout << "Insertion Sort comparisons: " << insertionSort(arr) << endl;

    cout << "Quick Sort comparisons: " << quickSortWrapper(arr) << endl;

    cout << "Merge Sort comparisons: " << mergeSortWrapper(arr) << endl;

    return 0;
}