//to create Max Heap

#include <iostream>
using namespace std;

class MaxHeap
{
    private:
        int* arr;  //we build heap using array elements
        int size; //total elements in heap currently
        int total_size; //total size of array (or max size that can be of heap)

    public:
        MaxHeap(int n)
        {
            arr = new int[n];
            size = 0;
            total_size = n;
        }

        //to insert elements in the heap
        void insert(int val)
        {
            if(size == total_size)
            {
                cout << "Heap overflow, no more elements can be inserted into the heap\n";
                return;
            }

            arr[size] = val; //we insert values from end in the heap
            int i = size; //to track at which idx we have inserted the element
            size++; //to indicate that we have inserted an element. After inserting an element we increase the size.

            //to put the element at its correct position after inserting so that it remains a max heap.
            //So, compare it with its parent. (if parent is smaller then, swap)
            while(i > 0 && arr[(i-1)/2] < arr[i])  //arr[(i-1)/2] is used to find the parent
            {
                swap(arr[i], arr[(i-1)/2]);
                i = (i-1)/2; //updating index (idx is now at the position where parent was)
            }
            cout << arr[i] << " is inserted into the heap\n";
        }

        //to print the element in heap
        void print()
        {
            for(int i=0; i<size; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
};

int main()
{
    MaxHeap H1(8); //total size (or maz size of heap) is 6

    H1.insert(14);
    H1.insert(24);
    H1.insert(12);
    H1.insert(11);
    H1.insert(25);
    H1.insert(8);
    H1.insert(35);
    H1.insert(45);

    cout << "\n--------------------------------\n";
    H1.print();
}