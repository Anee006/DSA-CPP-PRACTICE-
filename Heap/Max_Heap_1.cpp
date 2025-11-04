//to create Max Heap
//(insertion and deletion)

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

        //to delete an el from heap
        void deleteNode()
        {
            if(size == 0)
            {
                cout << "Heap underflow, no element present to delete\n";
                return;
            }

            cout << arr[0] << " deleted from the heap\n"; //the element present at root (i.e, at 1st idx) is deleted always

            arr[0] = arr[size-1]; //replace the element at root with the right-most element of last level

            size--; //after deleting element, size decreases

            if(size == 0) return; //if no element is left in heap

            //to put the element at root at its correct position
            Heapify(0);

        }

        //used to put an element at its correct position
        void Heapify(int i) //i means the index
        {
            int largest = i;  //contains the largest val out of: parent, left and right
            int left = 2*i + 1;  //left child of i based on CBT indexing
            int right = 2*i + 2; //right child of i 

            if(left < size && arr[left] > arr[largest])
            {
                largest = left;
            }

            if(right < size && arr[right] > arr[largest])
            {
                largest = right;
            }

            if(largest != i) //means "i" i.e, the parent has been replaced by some other larger val
            {
                swap(arr[i], arr[largest]);
                Heapify(largest);  //to put it at its correct position
            }
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

    cout << "\n--------------------------------\n";

    H1.deleteNode();
    H1.print();

}