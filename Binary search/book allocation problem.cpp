// #notes
//BOOK ALLOCATION PROBLEM 

//There are N books, each i'th book has A[i] number of pages.
//You have to allocate books to M number of students, so that the max no. of pgs allocated to a student is min.
//The following rules should be followed while allocating:
// -Each book should be allocated to a student.
// -Each student has to be allocated atleast one book.
// -Allotment should be in contiguous order.
//Calculate and return that min possible number.

//Given arr= {2,1,3,4}. N=4(i.e, 4 books). M=2 (2 students)

#include <iostream>
#include <vector>
using namespace std;

bool isValid(vector <int>& arr, int n, int m, int maxAllowedPages) //to check if our mid is valid
{
    int stu=1; //at first we have only 1 student
    int pages=0; //we have 0 pages to allocate

    for(int i=0;i<n;i++)
    {
        if(arr[i]>maxAllowedPages) //edge case
            return false;

        if(pages + arr[i] <=maxAllowedPages) 
        {
            pages += arr[i]; //means can add more pages
        }

        else
        {
            stu++; //means we need to bring a new student
            pages = arr[i];
        }
    }

    return stu > m ? false : true; //if stu is greater than m it returns false else returns true
}

int allocateBooks(vector <int>& arr, int n, int m)
{
    if(m>n) //means the number of students is more and no. of books is less, so impossible to allocate books to each stu
        return -1;


    //Calculate sum of all pages first to find the range we need to search in
    int sum=0;
    for(int i=0; i<n; i++)
    {
        sum +=arr[i];
    }

    int st=0, end=sum; //from st to end, we have our req range of possible answers
    int ans= -1; //for storing possible answers

    while(st<=end)
    {
        int mid= st+(end-st)/2;

        if(isValid(arr,n,m,mid)) //if returns true means ans is valid
        {
            ans=mid;
            end=mid-1; //we have to search in left whenever ans is valid, to find an even smaller ans than the current one
        }
            
        else 
            st= mid+1; //we have to search in right whenever ans in invalid

    }
    return ans; //the req min of the max no of pages allocated
}

int main()
{
    vector <int> arr= {2,1,3,4}; //2,1,3,4 represent the no. of pages
    int n=4; //we have 4 books
    int m=2; //we need to allocate it to 2 students

    cout<<allocateBooks(arr,n,m)<<endl;

    return 0;
}