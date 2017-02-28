/**
 * CLion was used to compile
 * Artsem Holdvekht
 * CSC 340
 * Assignment 8
 * 18 November 2016
 */
#include "list.h"

/**
 * Destructor to release any used memory
 */
List::~List()
{
    ListNode *curr = head;
    while (curr != NULL)
    {
        head = curr->next;
        delete curr;
        curr = head;
        size--;
    }
}

void List::clearList()
{
    ListNode *curr = head;
    while(curr != NULL)
    {
        head = curr->next;
        delete curr;
        curr = head;
        size--;
    }
    head = NULL;

}

//Initializer for default constructor
List::List():size(0),head(NULL)
{}

List::List(const List &anotherList):size(anotherList.size)
{
    //if orginal list head is NULL set new list head to null and size to 0
    if(anotherList.head == NULL)
    {
        head = NULL;
        size = 0;
    }
    else
    {
        try
        {
        head = new ListNode;
        }
        catch (bad_alloc &ba)
        {
            cerr<<"List(const List &anotherList):size(anotherList.size)" <<endl;
        }

        head->item = anotherList.head->item;

        ListNode *newPtr = head;

        for(ListNode *origPtr = anotherList.head->next; origPtr != NULL; origPtr = origPtr->next)
        {
            try
            {
                newPtr->next = new ListNode;
            }
            catch (bad_alloc &ba)
            {
                cerr<<"List(const List &anotherList):size(anotherList.size)(inside the for loop)" <<endl;
            }
            newPtr = newPtr->next;
            newPtr->item = origPtr->item;
        }

        newPtr->next = NULL;


    }
}

List List::operator=(const List &rhs)
{
    (*this).clearList();

    if(rhs.head == NULL)
    {
        head = NULL;
        size = 0;
    }
    else
    {
        size = rhs.size;


            head = new ListNode;


        head->item = rhs.head->item;
        ListNode *newPtr = head;

        for(ListNode *origPtr = rhs.head->next; origPtr != NULL; origPtr = origPtr->next)
        {

                newPtr->next = new ListNode;

            newPtr = newPtr->next;
            newPtr->item = origPtr->item;
        }

        newPtr->next = NULL;
    }
    return (*this);
}

void List::insert(int number)
{
    try
    {
        ListNode *newNode = new ListNode;
        newNode->item = number;

        if(head == NULL)
        {
            newNode->next = NULL;
            head = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }

        size++;
    }
    catch(bad_alloc &ba)
    {
        cerr<<"operator=(const List &rhs)" <<endl;
    }


}

ostream& operator<<(ostream& out, List& list)
{
    List::ListNode *current = list.head;

    while(current != NULL)
    {
        if(current->next != NULL)
            cout << current->item << " -> ";
        else
            cout << current->item;

        current = current->next;
    }
    cout << endl;
    return out;
}

void List::reverse()
{
    if(size == 0)
    {
        cout<<"The list is empty"<<endl;
    }

    ListNode *first = NULL;
    ListNode *last = NULL;
    int middle = size/2;
    int start = 0;
    int end = size - 1;
    int tmp;

    first = head;

    //"split" the list in half
    while(start < middle)
    {
        //find the last node and store it in last
        last = head;
        int count = 0;
        while(count < end)
        {
            last = last->next;
            count++;
        }

        //swtich values of the first and the last nodes
        tmp = first->item;
        first->item = last->item;
        last->item = tmp;

        //move first pointer
        first = first->next;
        //increment start of the list counter
        start++;
        //decrement the end of the list counter
        end--;
    }
}

//removing the number in th elist
void List::remove(int number)
{

    ListNode *tmp = NULL;
    ListNode *prev = NULL;
    ListNode *curr = head;
    int count = 0;

    if(!intCheck(number))
    {
        cout<<"The value is not found!"<<endl;
        return;
    }


    if (head == NULL)
    {
        cout << "List is empty!" << endl;
        return;
    }

    if(size == 1 && head->item == number)
    {
        delete head;
        head = NULL;
        size = 0;
        cout<<"The element has been removed, the list is empty now."<<endl;
        return;
    }

    if(head->item == number)
    {
        tmp = head;
        head = tmp->next;
        count++;
        delete tmp;
    }

    while (curr->next != NULL)
    {
        prev = curr;
        curr = curr->next;

        if (curr->item == number)
        {
            //remove the number and release the memomery
            tmp = curr;
            prev->next = curr->next;
            curr = curr->next;
            size--;
            count++;
            delete tmp;
        }

    }

    cout<<"The value: "<<number<<" has occurred: "<< count<< " time(s). All occurrences have been deleted"<<endl;

}

//checks if the number is in the list
bool List::intCheck(int number) const
{
    ListNode *curr = head;
    while(curr->next != NULL)
    {
        if(curr->item == number)
        {
            return true;
        }
        curr = curr->next;
    }

    return false;
}

// Returns the length of the list
int List::getLength() const
{
    return size;
}

//checks if the list is empty
bool List::isEmpty() const
{
    return(size==0);
}