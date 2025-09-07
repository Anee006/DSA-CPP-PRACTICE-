//REMOVE ALL OCCURENCES OF A SUBSTRING

//given a string s="daabcbaabcbc", and part="abc".
//We need to find the part in the given string s, and remove all its occurences from s.

//So, after removing abc once we have: dabaabcbc
//After removing abc again we have: dababc
//After removing abc again we have: dab, which is our answer

//Functions that will be used in Q:
//str.find(substr) : This fn returns the starting position of the 1st occurence of substr, if it is found in the mainstring
//To check its validity use: str.find(substr) < str.length()

//str.erase( starting position from where u want to erase, length of substring you want to erase)
//so our starting pos will be: str.find(part) and length of substr is part.length() which we want to delete

#include <iostream>
#include <string>
using namespace std;

string removeOccurences(string s, string part)
{
    while(s.length()>0 && s.find(part) <s.length())
    {
        s.erase(s.find(part), part.length()); //s.find(part) returns the start point of the substr we need to erase, part.length() gives its length
    }
    return s;
}
int main()
{
    string s= "daabcbaabcbc";
    string part= "abc";

    cout<< removeOccurences(s,part) <<endl;
    return 0;
}