/**
 * CLion was used to compile
 * Artsem Holdvekht
 * CSC 340
 * Assignment 8
 * 18 November 2016
 */
#include <iostream>

using namespace std;

#ifndef _LIST_H_
#define _LIST_H_

class List
{
private:

    struct ListNode
    {
        // integer data in the node
        int item;

        // pointer to the next node
        ListNode *next;
    };

    // number of items in the list
    int size;

    // pointer to the first node
    ListNode *head;

public:

    /**
     * Destructor
     */
    ~List();

    /**
     * Default constructor
     */
    List();

    /**
     * Copy constructor
     * @param anotherList list to be copied
     */
    List(const List& anotherList);

    /**
     * Overloaded equal (=) operator
     * @param rhs other list to be assigned to the left ide
     * @return returns a copy of the rhs list
     */
    List operator=(const List& rhs);

    /**
     * Insert the number in the front of the list
     * @param number to be inserted
     */
    void insert(int number);
        //throw(ListIndexOutOfRangeException, ListException);

    /**
     * Removed a number where it can be found in the list
     * @param index number to be removed
     */
    void remove(int index);
        //throw(ListIndexOutOfRangeException, ListException);

    /**
     * Checks if the list contains specified number
     * @param number to be found
     * @return return true or false if the number was found
     */
    bool intCheck(int number) const;

    /**
     * retrieves the size of the list
     * @return the size of the list
     */
    int getLength() const;

    /**
     * Reverses the list and out puts it to the screen
     */
    void reverse();

    /**
     * Check if the list is empty
     * @return retun bollean if list is empty or not
     */
    bool isEmpty() const;

    /**
     * Clears the list relesing all the memomry
     */
    void clearList();


    /**
     * Overloading << (output operator)
     * @param out ostream
     * @param list list to be printed out
     * @return prints out the provided list
     */
    friend ostream &operator <<(ostream &out, List &list);


};





#endif