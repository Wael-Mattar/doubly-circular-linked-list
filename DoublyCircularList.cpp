#include "DoublyCircularList.h"

// DCList non-arg constructor
DCList::DCList()
{
    myFirst = NULL; // Assigning myFirst to NULL
    mySize = 0;     // the list is empty right now
}
//--- Definition of searchNode()
DCList::NodePtr DCList::searchNode(const ElementType data) const
{
    // if list is empty
    if (isEmpty())
    {
        return NULL;
    }
    NodePtr tempPtr = myFirst;
    for (int i = 0; i < mySize; i++)
    {
        if (tempPtr->data == data) // if data is found
        {
            return tempPtr; // return the pointer
        }
        tempPtr = tempPtr->next; // move temp to the next node
    }

    return NULL;
}
//---Definition of search()
bool DCList::search(const ElementType &data) const
{
    // if list is empty
    if (isEmpty())
    {
        cerr << "**List is empty** " << endl; // error message
        exit(1);
    }

    NodePtr temp = myFirst;
    for (int i = 0; i < mySize; i++)
    {
        if (temp->data == data)
        { // if data is found
            return true;
        }
        temp = temp->next; // move temp to the next node
    }
    // data is not found
    return false;
}

//--- Definition of class copy constructor
DCList::DCList(const DCList &original)
{
    myFirst = NULL;
    mySize = 0;

    // interrupt execution if original list is empty
    if (original.isEmpty())
    {
        return;
    }

    NodePtr tempPtr = original.myFirst;
    for (int i = 0; i < original.mySize; i++)
    {
        insertAtEnd(tempPtr->data);
        tempPtr = tempPtr->next; // move temp to the next node
    }
}
//--- Definition of class destructor
DCList::~DCList()
{
    // list is empty
    if (isEmpty())
        return;

    // list is not  empty
    NodePtr tempPtr; // pointer for traversal

    for (int i = 0; i < mySize; i++)
    {
        tempPtr = myFirst;       // temp starts at myFirst
        myFirst = myFirst->next; // myFirst moves to the next node
        delete tempPtr;          // delete temp
    }
}
//--- Definition of assignment operator
const DCList &DCList::operator=(const DCList &rightHandSide)
{
    if (this == &rightHandSide) // check if it is self assigned
        return *this;

    this->~DCList();
    mySize = 0;
    myFirst = NULL;

    // after deleting this list
    // if rightHandSide list is empty
    if (rightHandSide.isEmpty())
        return *this; // return *this

    // make new node and assign it to myFirst
    NodePtr temp = rightHandSide.myFirst;

    for (int i = 0; i < rightHandSide.mySize; i++) // to traverse through the list
    {
        insertAtEnd(temp->data);
        temp = temp->next; // move temp along the list
    }
    return *this;
}
// //--- Definition of isEmpty()
bool DCList::isEmpty() const
{
    return mySize == 0; // or myFirst == NULL;
}
//--- Definition of insertAtPosition()
bool DCList::insertAtPosition(ElementType data, int pos)
{
    // check if position is invalid
    if (pos < 0 || pos > mySize)
    {
        cerr << "**Position is invalid.**\n"
             << "The list remains intact\n"; // error message
        return false;
    }
    // position is valid
    NodePtr newPtr = new DoublyNode(data); // declaring a newPtr with data

    // list is empty
    if (isEmpty())
    {
        myFirst = newPtr;
        myFirst->next = myFirst;
        myFirst->prev = myFirst;
        mySize++; // increment mySize after inserting a new element
        return true;
    }
    NodePtr predPtr = myFirst;
    // list is not empty and we insert at beginning
    if (pos == 0)
    {
        predPtr = myFirst->prev;
        newPtr->next = myFirst;
        newPtr->prev = predPtr;
        myFirst->prev = newPtr;
        predPtr->next = newPtr;
        myFirst = newPtr;
        mySize++; // increment mySize after inserting a new element
        return true;
    }
    // list not empty and we're inserting in middle or end

    for (int i = 1; i < pos; i++)
    {
        predPtr = predPtr->next;
    }
    newPtr->next = predPtr->next;
    newPtr->prev = predPtr;
    predPtr->next->prev = newPtr;
    predPtr->next = newPtr;

    mySize++; // increment mySize after insertion
    return true;
}
//--- Definition of insertAtEnd()
bool DCList::insertAtEnd(ElementType data)
{
    return insertAtPosition(data, mySize); // invoke insertAtPosition()
}
//--- Definition of insertAtBeginning()
bool DCList::insertAtBeginning(ElementType data)
{
    return insertAtPosition(data, 0); // invoke insertAtPosition()
}
//--- Definition of deleteAtPosition()
bool DCList::deleteAtPosition(int pos)
{
    // if list empty
    if (isEmpty())
    {
        cout << "list is empty";
        exit(1);
    }
    if (pos < 0 || pos >= mySize) // position is invalid
    {
        cerr << "Invalid position\n\n"; // error message
        return false;
    }
    // if there is only one node in the list
    if (mySize == 1)
    {
        NodePtr temp = myFirst;
        myFirst = NULL; // point myFirst to NULL
        delete temp;    // delete the node
        mySize--;
        return true;
    }

    NodePtr predPtr = myFirst;

    if (pos == 0) // if we are deleting the first node
    {
        NodePtr toDelete = myFirst;
        predPtr = myFirst->prev;
        predPtr->next = myFirst->next;
        myFirst = myFirst->next;
        myFirst->prev = predPtr;
        delete toDelete;
        mySize--; // decrement mySize after deletion
        return true;
    }

    // for loop to iterate over the nodes
    for (int i = 1; i < pos; i++)
    {
        predPtr = predPtr->next; // move predPtr to the next node
    }
    NodePtr ptr = predPtr->next;
    NodePtr succPtr = ptr->next;

    predPtr->next = succPtr;
    succPtr->prev = predPtr;
    delete ptr; // delete ptr
    mySize--;   // decrement mySize after deletion
    return true;
}
//--- Definition of deleteAValue()
bool DCList::deleteAValue(ElementType data)
{
    // if the list is empty
    if (isEmpty())
    {
        cerr << "***List is empty.\nNo data to delete***" << endl;
        exit(1);
    }
    NodePtr ptr = searchNode(data);
    if (ptr == NULL) // if the pointer to the node is NULL
    {
        cerr << "***Data was not found***" << endl; // error message
        return false;
    }
    // if there is only one element in the list
    if (mySize == 1)
    {
        NodePtr ptr = myFirst; // make ptr points to myFirst
        myFirst = NULL;        // make myFirst point to NULL
        delete ptr;            // delete ptr
        mySize--;              // decrement mySize after deletion
        return true;
    }

    if (ptr == myFirst)
        myFirst = myFirst->next;
    NodePtr predPtr = ptr->prev;
    NodePtr succPtr = ptr->next;

    predPtr->next = succPtr;
    succPtr->prev = predPtr;
    delete ptr; // delete the pointer
    mySize--;   // decrement mySize
    return true;
}
//--- Definition of deleteBeforeAnElement
bool DCList::deleteBeforeAnElement(ElementType data)
{
    // if the list is empty
    if (isEmpty())
    {
        cerr << "***List is empty.***" << endl;
        exit(1); // interrupt execution
    }
    // if list has only one element
    if (mySize == 1)
    {
        cerr << "***The list has only one element***"
             << "***Can't delete before it***"
             << endl; // error message
    }
    // search for item data in the list
    NodePtr succPtr = searchNode(data);
    if (succPtr == NULL) // if the pointer to the node is NULL
    {
        cout << "Element not found in your DCList\n " << endl;
        return false;
    }
    NodePtr ptr = succPtr->prev;

    if (ptr == myFirst)
    {
        myFirst = succPtr;
    }

    succPtr->prev = ptr->prev;
    ptr->prev->next = succPtr;
    delete ptr; // delete ptr
    mySize--;   // decrement mySize
    return true;
}
//--- Definition of findAndDelete()
int DCList::findAndDelete(const ElementType &data)
{
    // if list is empty
    if (isEmpty())
    {
        exit(1);
    }
    int count = 0; // to count the number of deleted nodes
    int originalSize = mySize;
    // to traverse through the list
    for (int i = 0; i < originalSize; i++)
    {
        if (searchNode(data) != NULL) // if data is found
        {
            deleteAValue(data); // delete the data
            count++;            // increment count
        }
        else
        {
            break;
        }
    }
    return count; // return number of deleted nodes
}
//--- Definition of removeFirst()
ElementType DCList::removeFirst()
{
    // if list empty
    if (isEmpty())
    {
        exit(1); // interrupt execution
    }
    ElementType data = myFirst->data;
    deleteAtPosition(0); // invoke deleteAtPosition()
    return data;         // return the data of the first node
}
//--- Definition of removeLast()
ElementType DCList::removeLast()
{
    // if list empty
    if (isEmpty())
    {
        exit(1); // interrupt execution
    }
    ElementType data = myFirst->prev->data;
    deleteAtPosition(mySize - 1); // invoke deleteAtPosition
    return data;                  // return the data of the last node
}
//--- Definition of deleteDuplicates()
ElementType DCList::deleteDuplicates()
{
    // if list empty
    if (isEmpty())
    {
        cerr << "List is empty." << endl;
        exit(1);
    }
    int count = 0; // to count the number of deleted duplicates
    int i, j = 0;
    NodePtr current = myFirst;    // set current ptr to myFirst
    NodePtr temp = myFirst->next; // set temp ptr to the node after myFirst
    while (current->next != myFirst)
    {
        i = j + 1;
        while (temp->next != myFirst->next)
        {
            // if the duplicate data was found, delete it
            if (temp->data == current->data)
            {
                temp = temp->next; // move temp to next node
                deleteAtPosition(i);
                count++; // increment the number of deleted duplicates
            }
            // if duplicate not found
            else
            {
                temp = temp->next;
                i++; // increment i
            }
        }
        current = current->next; // move temp to next node
        temp = current->next;
        j++;
    }
    return count; // return number of deleted duplicates
}
//--- Definition of display()
void DCList::display(ostream &out) const
{
    // if list is empty
    if (isEmpty())
    {
        out << "Empty list." << endl;
        return;
    }
    NodePtr tempPtr = myFirst;

    // to display The list is: 2, 3
    out << "The list is: " << myFirst->data;

    // to traverse the list
    for (int i = 1; i < mySize; ++i)
    {
        // move the tempPtr to the next node
        tempPtr = tempPtr->next;
        out << ", " << tempPtr->data;
    }
    out << endl;
}
//--- Definition of output operator
ostream &operator<<(ostream &out, DCList &list)
{
    list.display(out); // display the list
    return out;
}