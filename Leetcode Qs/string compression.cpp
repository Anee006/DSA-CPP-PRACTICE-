//STRING COMPRESSION problem

//Given, chars = ["a","a","b","b","c","c","c"]. We need to compress this vector and return its size. The changes should be in-place.

//RULEs for compressing :
//1. If a char occurs more than once, write the char along with the no. of times it occurs like,
//here, 'a' occurs twice so we write it as: "a2"
//2. If a char occurs only once we'll write it only once, like if 'a' occurs only once we'll write it as: "a"

//So, after compressing the given vector according to the given conditions we'll have: "a2b2c3".
//After making in-place changes we'll have, ['a', '2', 'b', '2', 'c', '3'].Here, we have 6 char, so our ANS IS 6.

//Another example, if we have a vector ['a', 'b', 'b', 'a', 'a']. After compressing we'll have: "ab2a2" so size=5.

//STEPS:
//1. count the no. of occurences of consecutive (i.e, same) char in the vector
//2. if count=1, simply replace the ch in the original vector. If count>1, then it has to be stored as: "ch count".
//so, we need to convert "count" to string first using "to_string(count)", calculate it's individual digits and then store it in the given vector.
//3. Create another index called "idx" to track the original index where we need to make the changes. idx helps in adding new char/string into the same vector.
//4. At the end of loop do i--, so that due to i-- we can go to prev idx and due to i++ of the for loop we can come back at the same idx, and start counting for that idx.
//agar i-- nhi likhne ka mann kare toh for loop mai se i++ hata do.

#include <iostream>
#include <vector>
using namespace std;

int compress(vector <char> &chars)
{
    int n=chars.size();
    int idx=0; //used to track changes. helps in adding new values to the vector

    for(int i=0; i<n; i++)
    {
        char ch= chars[i]; //used to store the char
        int count=0; //used to count the total occurences of the same char

        while(i<n && chars[i]==ch) //this is to find the count of consecutive char
        {
            count++;
            i++;
        }
        if(count==1) //means if char occurs only once
        {
            chars[idx++]=ch; //to store the char in the vector
        }
        else
        {
            chars[idx++]=ch;

            //to store the count: we need to convert it to string first and then find its individual digits

            string str= to_string(count); //converts count to a string
            for(char digits: str) //to find individual digits
            {
                chars[idx++]=digits; //to store digit in the vector
            }
        }
        i--; //to counter the i++
    }

    chars.resize(idx); //idx helps in giving the size of the compressed vector
    return idx;
}

int main()
{
    vector <char> chars= {'a','a','b','b','c','c','c'};
    cout<< compress(chars) <<endl;

    return 0;
}
