//VALID PARENTHESES
//using stack

//Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

//An input string is valid if:
//Open brackets must be closed by the same type of brackets.
//Open brackets must be closed in the correct order.
//Every close bracket has a corresponding open bracket of the same type.


//Input: s = "()[]{}"
//Output: true

//Input: s = "([])"
//Output: true

//Input: s = "(]"
//Output: false


//LOGIC:
//the order in which the brackets are opened is the opposite of the way in which they are closed.
//The last bracket while opening should be the first bracket while closing.
//Example in "({[]})", ( is opened first and then { and then in the last [.
//so while closing, ] is closed first, then } and then in the last ).
//If these conditions are met, then only it is a valid string.

//whenever we want that the last thing added should occur first while checking, we use a stack (as it works on LIFO).
//Using stack we can say that the bracket which appears at the top of the stack, must be the bracket that was added at the last while opening
//and it's matching bracket should be closed first, for it to be a valid string.

#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isValid(string str)
{
    stack <char> s; //creating stack of char

    for(int i=0; i<str.size(); i++)
    {
        //for checking if the char we have is an opening bracket
        if(str[i] == '(' || str[i] == '{' || str[i] == '[')
        {
            s.push(str[i]);
        }
        else //means the char we have is a closing bracket
        {
            if(s.size() == 0) //if stack size becomes 0: return false
            {
                return false;
            }

            //to check if we have an exact match of opening & closing brackets or not
            if((s.top() == '(' && str[i] == ')') || (s.top() == '{' && str[i] == '}') || (s.top() == '[' && str[i] == ']')) 
            //both should be true for it to be true
            {
                s.pop(); //remove a pair after match has been found
            }
            else
            {
                return false;
            } 
        }
    }
    return s.size() == 0; //if this is true means our string is valid as no remaining brackets are there, else returns false
}

int main()
{
    string s1 = "()[]{}";
    cout << "Is s1 a valid string ? " << "\t" << isValid(s1) <<endl;

    string s2 = "([])";
    cout << "Is s2 a valid string ? " << "\t" << isValid(s2) <<endl;

    string s3 = "(]";
    cout << "Is s3 a valid string ? " << "\t" << isValid(s3) <<endl;

    return 0;
}

//TC = O(n)
//SC = O(n)  ,[as we created an extra stack]