/**
 * CLion was used to compile
 * Artsem Holdvekht
 * CSC 340
 * Assignment 8
 * 18 November 2016
 */

#include <iostream>
#include "list.h"

int main() {

    //instantiating the lists
    List list, list2, list3;

    //insert some values into the list
    list.insert(6);
    list.insert(5);
    list.insert(4);
    list.insert(3);
    list.insert(2);
    list.insert(1);
    cout << "List: " << list << endl;
    cout<<"---------------------------------------"<<endl;


    cout<<"Populating list2 with values"<<endl;

    list2.insert(8);
    list2.insert(99);
    list2.insert(67);
    list2.insert(99);
    list2.insert(32);
    list2.insert(23);
    list2.insert(99);
    list2.insert(144);
    list2.insert(99);

    cout<<list2;
    cout<<"---------------------------------------"<<endl;
    cout<<"The length of the List2 is: "<<endl;
    cout<<list2.getLength()<<endl;

    cout<<"---------------------------------------"<<endl;
    cout<<"Removing 99 from the list"<<endl;
    list2.remove(99);
    cout << "List2: " << list2 << endl;
    cout<<"---------------------------------------"<<endl;

    cout<<"Testing copy constructor."<<endl;
    list2 = list;
    cout << " New List2: " << list2 << endl;

    cout<<"--------------------------------"<<endl;

    cout<<"Reversing List 2."<<endl;
    list2.reverse();

    cout << " Reversed List2: " << list2 << endl;
    cout<<"-----------------------------------"<<endl;


    cout<<"Removing value 4 form List 2."<<endl;
    list2.remove(4);

    cout << "List2: " << list2 << endl;
    cout<<"-----------------------------------"<<endl;

    cout<<"Checking is list 2 is empty."<<endl;
    cout<<list2.isEmpty()<<endl;
    cout<<"-----------------------------------"<<endl;


    return 0;
}