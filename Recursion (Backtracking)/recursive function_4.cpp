//to print the "index" of first occurance and last occurance of a character in a string

#include <iostream>
#include <string>
using namespace std;

static int first = -1; //to store the idx of first occurance
static int last = -1;  //to store the idx of last occurance
//declaring them as static as we don't want its value to change in each call

void find_Occurance(string str, int idx, char element) //char element is the char we want to track
{

    if(idx==str.length()) //base case
    {
        cout<<"First occurence: "<<first<<endl;
        cout<<"Last occurance: "<<last<<endl;
    }

    char current= str.at(idx); //to find the current char where we are at
    if(current==element)
    {
        if(first==-1)  //means we have found the "first" occurance of the req char
        {
            first=idx; //storing the index where we found the first occurance
        }
        else
        {
            last=idx; //we are assuming that all the rest occurances are last 
        }
    }

    find_Occurance( str, idx+1, element); // "idx+1" as we are traversing the string in forward direction
}

int main()
{
    string str="aabcdeah";
    find_Occurance(str, 0, 'a'); //we need to find the first and last ocuurance of 'a'

    return 0;
}

