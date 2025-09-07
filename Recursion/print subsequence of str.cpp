//to print all subsequences/subsets of a string
//This same logic can be used to find subset of an array

#include <iostream>
#include <string>
using namespace std;

void subSeq(string str, int idx, string newstring)
{
    if(idx==str.length())
    {
        cout<<newstring<<endl;
        return;
    }

    char current= str.at(idx);

    //each char has two choices: to be in the new string or to not be in the new string.

    //choice 1: char chooses to be in the new string
    subSeq(str, idx+1, newstring+current);


    //choice 2: char chooses to not be in the new string
    subSeq(str, idx+1, newstring);
}

int main()
{
    string str="abc";
    subSeq(str,0,"");

    return 0;
}