//TOWER OF HANOI PROBLEM :
//RULES: 1.only one disk can be transferred at a time
//       2. smaller disk should be at top of larger disk


#include <iostream>
#include <string>
using namespace std;

//numOfDisks: total num of disks to be transferred
//Source: Jaha se transfer kar rahe hai
//Helper: used as a helper tower
//Destination: jaha par disks transfer karne hai


void towerOfHanoi(int numOfDisks, string source, string helper, string destination)
{
    if(numOfDisks==1) //base case : when we have only 1 disk then transfer it from source to destination directly
    {
        cout<<"Transfer disk " <<numOfDisks <<" from "<< source<<" to "<<destination<<endl;
        return;
    }
    towerOfHanoi(numOfDisks-1, source, destination, helper); //we want to tranfer n-1 disks from source to helper. so our help becomes des and des becomes help.
    cout<<"Transfer disk " <<numOfDisks <<" from "<< source<<" to "<<destination<<endl;

    towerOfHanoi(numOfDisks-1, helper, source, destination); //we want to tranfer n-1 disks from helper to destination using source as a helper.
}

int main()
{
    int num; 

    num=1; //num of disks is 1 here
    cout<<"For 1 disk to be transferred..."<<endl;
    towerOfHanoi(num, "S", "H", "D"); //"S": source, "H": helper, "D": destination
    cout<<"-------------------------------------------"<<endl;
    cout<<endl;


    num=2; //num of disks is 2 here
    cout<<"For 2 disks to be transferred..."<<endl;
    towerOfHanoi(num, "S", "H", "D"); //"S": source, "H": helper, "D": destination
    cout<<"-------------------------------------------"<<endl;
    cout<<endl;

    num=3; //num of disks is 3 here
    cout<<"For 3 disks to be transferred..."<<endl;
    towerOfHanoi(num, "S", "H", "D"); //"S": source, "H": helper, "D": destination
    cout<<"-------------------------------------------"<<endl;
    cout<<endl;

    return 0;
}