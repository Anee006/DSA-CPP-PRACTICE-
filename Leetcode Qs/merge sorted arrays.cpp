//MERGE SORTED ARRAYS problem

//Given two integer arrays "A" and "B", sorted in non-decreasing (ascending) order, and two integers m and n, 
//representing the number of elements in A and B respectively.
//Merge A and B into a single array sorted in ascending order.

// The code should follow: T.C= O(m+n) and S.C=O(1)

//A={1,2,3,0,0,0}, m=3
//B={2,5,6}, n=3
//So, merged array A becomes, A={1,2,2,3,5,6}


//Logic:
//In the vector A, we have some extra space in the form of the 3 zeroes. So, we don't need to create extra space as such.
//We'll move backwards in vector A and start filling the zeroes with values from vector B.
//Means, we'll first fill the el. for last index which will be the largest el as, we have to arrange in asc order,
//then we'll fill the el. for the 2nd last index and so on..
//So, we'll compare the largest el. in both the el and the largest of these two will be filled in the last index pos.
//In this case, largest el. in A is 3 and largest el in B is 6, so larger of the two is 6.
//then, we'll compare 3 and 5. The larger of the two is 5 so, 5 will be at the 2nd last pos.
//then we'll compare 3 and 2. The larger of them is 3 so, 3 will be at the 3rd last pos.

//Steps:
//Take idx= m+n-1. idx points at the last el of vector A
//Take i=m-1 and j=n-1
//For given vectors, i points at value 3 in vector A and j points at value 6 in B
//After an el is stored in vector A, do j-- and idx--, so that next el can be filled
//When, j<0, means our B vector is transeferred to A completely.
//When i<0, means the el in vector B haven't been transferred yet, so A[idx]= B[j], do j-- and idx--

#include <iostream>
#include <vector>
using namespace std;

void mergeArrays(vector <int> &A, int m, vector<int> &B, int n)
{
    int idx= m+n-1;
    int i=m-1;
    int j=n-1;

    while(i>=0 && j>=0)
    {
        if(A[i]>=B[j])
        {
            A[idx]=A[i];  //instead of writing these three lines we can also write: A[idx--]=A[i--]
            idx--;
            i--;
        }

        else
        {
            A[idx]=B[j];  //instead of writing these three lines we can also write: A[idx--]=B[j--]
            idx--;
            j--;
        }
    }

    while(j>=0)
    {
        A[idx--]=B[j--]; //doing the same task we had done in the previous step
    }

}

int main()
{
    vector <int> A= {1,2,3,0,0,0};
    int  m=3;

    vector <int> B={2,5,6};
    int n=3;

    mergeArrays(A,m,B,n);

    cout<<"After merging:"<<endl;
    for(auto val:A)
    {
        cout<<val<<"\t";
    }
    cout<<endl;

    return 0;

}