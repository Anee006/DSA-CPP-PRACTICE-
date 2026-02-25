//to print a string in reverse order

#include <iostream>
#include <string>
using namespace std;
void print_reverse(string str, int idx) //str is the string to be reversed and idx is the variable to store the index.
{
    if(idx == 0) //base case
    {
        cout << str.at(idx);
        return;
    }

    cout << str.at(idx); //to print the character at that particular index
    print_reverse(str, idx-1); //as we want to print in reverse order
}
int main()
{
    string str = "abcd";
    print_reverse(str, str.length()-1);
    
    return 0;
}