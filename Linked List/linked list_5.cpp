//single linked list using STL

#include <iostream>
#include <forward_list>  //to create a singly linked list
using namespace std;
int main()
{
    forward_list <int> l; //creates an empty list
    l.assign({1,2,3}); //used to assign values to list
    cout<<"List created: "<<endl;
    for(auto i:l)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<"---------------------------------------------"<<endl;


    l.push_front(5); //used to insert value at front of list
    //can also use "emplace_front(val)" here to insert value at beginning.
    cout<<"List created: "<<endl;
    for(auto i:l)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<"---------------------------------------------"<<endl;

    
    l.pop_front(); //used to delete first element from list
    cout<<"List created: "<<endl;
    for(auto i:l)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<"---------------------------------------------"<<endl;


    forward_list <int> l1= {21,2,23,24};
    l1.reverse(); //reverses the list l1
    cout<<"List created: "<<endl;
    for(auto i:l1)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<"---------------------------------------------"<<endl;


    auto it= l1.insert_after(l1.begin(),9); //inserts 9 at the 2nd position, i.e after 21.
    //insert_after inserts value after the position where the iterator points at.
    //l1.begin() points at the first element,so 9 is inserted after the 1st element.

    cout<<"List created: "<<endl;
    for(auto i:l1)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<"---------------------------------------------"<<endl;


    forward_list <char> c={'a', 'd', 'r','d'};
    auto i=c.erase_after(c.begin()); //erase_after erases the element at the position next to that pointed by iterator
    cout<<"List created: "<<endl;
    for(auto i:c)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<"---------------------------------------------"<<endl;


    c.remove('d'); //remove(value) removes all the occurences of that "value" from list
    cout<<"List created: "<<endl;
    for(auto i:c)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<"---------------------------------------------"<<endl;

    c.clear(); //deleted the entire list 'c'
    if(c.empty()==true)
    {
        cout<<"list c is empty"<<endl;
    }
    else
    {
        cout<<"List c is not empty"<<endl;
    }

    forward_list <int> list1={-2,-1,3,67,90};
    forward_list <int> list2={100,28,-3,27};
    list1.sort(); //sort() is used to sort an unsorted list
    list2.sort();

    cout<<"List created: "<<endl;
    for(auto i:list1)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<"---------------------------------------------"<<endl;

    cout<<"List created: "<<endl;
    for(auto i:list2)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<"---------------------------------------------"<<endl;

    list1.merge(list2); //list 2 is merged into list1. 
    //merge is used to merge two sorted lists together

    cout<<"List created: "<<endl;
    for(auto i:list1)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<"---------------------------------------------"<<endl;

    return 0;

}
