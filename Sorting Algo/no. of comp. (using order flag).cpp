// To print the total number of comparisons done in each of the sorting algorithm.
// (selection sort, bubble sort, insertion sort, quick sort and merge sort).
// using order flag --> "a" for ascending and "d" for descending

#include <iostream>
#include <vector>
using namespace std;

int bubbleSort(vector<int> arr, char order) {
    int comparisons = 0;
    int n = arr.size();

    for(int i=0; i<n-1; i++) {
        for(int j=0; j<n-i-1; j++) {
            comparisons++;

            if(order == 'a' ? arr[j] > arr[j+1] : arr[j] < arr[j+1]) {
                swap(arr[j] , arr[j+1]);
            }
        }
    }
    return comparisons;
}

int selectionSort(vector<int> arr, char order) {
    int comparisons = 0;
    int n = arr.size();

    for(int i=0; i<n-1; i++) {
        int minIdx = i;

        for(int j=i+1; j<n; j++) {
            comparisons++;

            if(order == 'a' ? arr[j] < arr[minIdx] : arr[j] > arr[minIdx]) {
                minIdx = j;
            }
            
        }
        swap(arr[i], arr[minIdx]);
    }
    return comparisons;
}

int insertionSort(vector<int> arr, char order) {
    int comparisons = 0;
    int n = arr.size();

    for(int i=1; i<n; i++) {
        int curr = arr[i];
        int prev = i-1;

        while(prev >= 0) {
            comparisons++;

            if(order == 'a' ? arr[prev] > curr : arr[prev] < curr) {
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

int partition(vector<int>& arr, int low, int high, char order) {
    int pivot = arr[high]; // choosing last el as pivot
    int i = low-1;

    for(int j = low; j<high; j++) {
        quickComparisons++;

        if(order == 'a' ? arr[j] < pivot : arr[j] > pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return i+1;
}

void quickSort(vector<int>& arr, int low, int high, char order) {
    if(low < high) {
        int pivot = partition(arr, low, high, order);
        quickSort(arr, low, pivot-1, order);
        quickSort(arr, pivot+1, high, order);
    }
}

int quickSortWrapper(vector<int> arr, char order) {
    quickComparisons = 0;
    quickSort(arr, 0, arr.size()-1, order);
    return quickComparisons;
}

int mergeComparisons; // to track no. of comparisons in merge sort

void merge(vector<int>& arr, int low, int mid, int high, char order) {
    vector<int> temp;
    int i=low, j = mid+1;

    while(i <= mid && j <= high) {
        mergeComparisons++;

        if(order == 'a' ? arr[i] <= arr[j] : arr[i] >= arr[j]) {
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

    for(int k = 0; k < temp.size(); k++) {
        arr[k + low] = temp[k];
    }
}

void mergeSort(vector<int>& arr, int low, int high, char order) {
    if(low < high) {
        int mid = low + (high-low)/2;

        mergeSort(arr, low, mid, order);
        mergeSort(arr, mid+1, high, order);
        merge(arr, low, mid, high, order);
    }
}

int mergeSortWrapper(vector<int> arr, char order) {
    mergeComparisons = 0;
    mergeSort(arr, 0, arr.size()-1, order);
    return mergeComparisons;
}

int main() {
    vector<int> arr = {10, -1, 1, 233, 100};

    // No. of comparisons when array is sorted in asc order:
    cout << "Selection Sort comparisons: " << selectionSort(arr, 'a') << endl;

    cout << "Bubble Sort comparisons: " << bubbleSort(arr, 'a') << endl;

    cout << "Insertion Sort comparisons: " << insertionSort(arr, 'a') << endl;

    cout << "Quick Sort comparisons: " << quickSortWrapper(arr, 'a') << endl;

    cout << "Merge Sort comparisons: " << mergeSortWrapper(arr, 'a') << endl;

    cout << "\n-----------------------------------------------------------\n";

    // No. of comparisons when array is sorted in desc order:
    cout << "Selection Sort comparisons: " << selectionSort(arr, 'd') << endl;

    cout << "Bubble Sort comparisons: " << bubbleSort(arr, 'd') << endl;

    cout << "Insertion Sort comparisons: " << insertionSort(arr, 'd') << endl;

    cout << "Quick Sort comparisons: " << quickSortWrapper(arr, 'd') << endl;

    cout << "Merge Sort comparisons: " << mergeSortWrapper(arr, 'd') << endl;

    return 0;
}