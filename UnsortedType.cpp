#include <stdio.h>
#include <iostream>
#include "UnsortedType.h"
using namespace std;

//complexity = O(1)
UnsortedType::UnsortedType()
{
    length = 0;
    start = NULL;
}

//complexity = O(n)
void UnsortedType::makeEmpty()
{
    Node* temp;
    while(start != NULL)
    {
        temp = start;
        start = start->next;
        delete temp;
    }
    length = 0;
    cout << "The List is Empty Now !!!" << endl;
}

//complexity = O(1)
bool UnsortedType::isFull() const
{
    Node* location;
    try
    {
            location = new Node;
            delete location;
            return false;
    }
    catch(bad_alloc exception)
    {
        return true;
    }
}

//complexity = O(1)
int UnsortedType::getLength() const
{
    return length;
}

//complexity = O(1)
void UnsortedType::insertData(int  value)
{
    Node* temp = new Node;
    temp->data = value;
    temp->next = start;
    start = temp;
    length++;
}

//complexity = O(n)
void UnsortedType::removeData(int  value)
{
    if (start == NULL)
    {    
        cout << "The List is Empty !!!" << endl;
        return;
    }
    Node* temp1 = start;
    if (start->data == value)
    {
        start = start->next;
        delete temp1;
        cout << "Item '" << value << "' Deleted !!!" << endl;
        length--;
    }
    else
    {
            Node* temp2 = start->next;
            while (temp2 != NULL)
            {
                    if (temp2->data == value)
                    {
                        temp1->next = temp2->next;
                        delete temp2;
                        cout << "Item '" << value << "' Deleted !!!" << endl;
                        length--;
                        return;
                    }
                    temp1 = temp2;
                    temp2 = temp2->next;
            }
            cout << "Item '" << value << "' Not Found !!!" << endl;
    }
}

//complexity = O(n)
void UnsortedType::display()
{
    cout << endl << "List :" << endl;
    cout << "List Length : " << getLength() << endl;
    Node* temp = start;
    while (temp != NULL)
    {
            cout << temp->data << endl;
            temp = temp->next;
    }
    cout << endl;
}

//complexity = O(n)
UnsortedType::~UnsortedType()
{
    makeEmpty();
}