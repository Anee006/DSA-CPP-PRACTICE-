//to move all "x" from string "axabdcxxg" to the end.
//so the new string now becomes: "aabdcgxxx".

#include <iostream>
#include <string>
using namespace std;

void move_X(string str,int idx, int count, string newString) //"count" tracks the no. of 'x' on the given string
{
    if(idx==str.length()) //base case
    {
        for(int i=0; i<count; i++)
        {
            newString= newString+ 'x'; //adding x to the end of the string "count" no. of times
        }
        cout<<newString<<endl;
        return;
    }

    char current= str.at(idx);
    if(current=='x')
    {
        count++;
        move_X(str,idx+1,count, newString);
    }
    else
    {
        newString=newString+current; //or use +=
        move_X(str,idx+1,count, newString);
    }
}

int main()
{
    string str= "axabdcxxg";
    move_X(str, 0, 0, " "); //at beginning newString will be empty

    return 0;
}
