//FIRST UNIQUE CHARACTER IN A STRING (using queue)
//OR
//FIRST NON-REPEATING CHAR IN A STREAM

//Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

//Input: s = "leetcode"
//Output: 0
//Explanation: The character 'l' at index 0 is the first character that does not occur at any other index.

//Input: s = "aabb"
//Output: -1


//LOGIC:
//create an unordered_map<char,int> m, to store the freq of each char in the string.
//In the map m, the char becomes the key and that character's frequency becomes the value.
//We use queue here because it is FIFO, we want that the char which occurs first in the str should have higher priority.
//This ensures that if we have more than one unique char in the str then only the first char which is unique will be returned.

//queue is used to store idx of only the unique char of the string. If repeating el occurs, pop it.
//so our final ans (i.e, the first unique char) will be stored at the front of the queue.

//whenever in the map, the freq of any char becomes greater than 1, it means it is repeating. So pop that el from the queue.

//NOTE: we will store the idx of char in the queue and not the actual char.

#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

int firstUniqueChar(string s)
{
    unordered_map <char, int> m; //to store char and its corresponding freq
    queue <int> q;

    //push the idx of unique char in the queue:
    for(int i=0; i<s.size(); i++)
    {
        if(m.find(s[i]) == m.end())
        {
            q.push(i); //to push idx of the unique char in the queue
        }

        m[s[i]]++; //to update the freq of char

        //to remove the repeating values 
        while(q.size() > 0 && m[s[q.front()]] > 1) //s[q.front()] is the char and m[s[q.front()]] is its freq
        {
            q.pop();
        }
    }

    return q.empty() ? -1 : q.front(); //if queue is empty then ans is -1 else the unique char is at the front
}

int main()
{
    string s1 = "leetcode";
    cout << firstUniqueChar(s1) << endl;

    string s2 = "aabb";
    cout << firstUniqueChar(s2) << endl;

    return 0;
}