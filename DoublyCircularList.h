/*-- List.h ---------------------------------------------------------------
    This header file defines the data type List for processing Doubly Circular List.
    Basic operations are:
    no arg Constructor
    Destructor
    Copy constructor
    Assignment operator
    search: returns true if the item exists in the list
    isEmpty: Check if list is empty or not
    insertAtPosition: Insert an item
    insertAtEnd: insert an item at end
    insertAtBeginning: insert an item at the beginning
    deleteAtPosition: Remove an item
    deleteAvalue: deletes the node that contains the item data
    deleteBeforeAnElement: search for the item in the list and delete
                           the node before the node where data was found
    findAndDelete: deletes all the occurences of an item data
    removefirst: cuts the first node from the list and returns its data
    removeLast: cuts the last node from the list and returns its data
    deleteDuplicates: keeps only the first occurence of an element in
                      the list and removes all the others
    display: to display the content list
    «: Output operator << that calls the function display and
                          display the content of the list
-------------------------------------------------------------------------*/

#ifndef DCLIST
#define DCLIST

#include <iostream>

using namespace std;

typedef int ElementType;

// Declaration of the class
class DCList
{

private:
    /*** DoublyNode class ***/
    class DoublyNode
    {
    public:
    /***** Data Members *****/
        ElementType data; // data field of type ElementType
        DoublyNode *prev; // pointer to the previous node
        DoublyNode *next; // pointer to the next node

        // DoublyNode default constructor
        DoublyNode(ElementType n) : data(n), prev(NULL), next(NULL)
        {
        }
    };
    /******** Data Members of Doubly List class ********/
    typedef DoublyNode *NodePtr;

    NodePtr myFirst; // pointer myFirst to the first node of the list
    int mySize;      // represents the number of available elements in the DCList

    /*
    Delete the node that contains the item data

    Precondition: data is the value to be deleted from the list
    Postcondition: true is returned if data has been deleted from the list,
                    false if not (execution interrupted if list is empty).
    */
    bool deleteAValue(ElementType data);

    /*
    Search for the node that contains the item data

    Precondition: takes an item data of type ElementType
    Postcondition: returns a pointer to the node that contains this data,
                     (the function should return NULL if the item does
                      not exist or if the list is empty)
    */
    NodePtr searchNode(const ElementType data) const;

public:
    /*** DCList's function members ***/

    /*
    Construct a DCList object.

    Precondition: None
    Postcondition: an empty DCList object has been constructed;
                      mySize is 0 and myFirst is null
    */
    DCList();

    /***** Copy constructor *****/
    DCList(const DCList &orig);
    /*
    Construct a copy of DCList object.

    Precondition: A copy of orig is needed; orig is a const
                reference parameter.
    Postcondition:  A copy of orig has been constructed.
    */

    /*
    Destroys a DCList object.

    Precondition:  The life of a DCList object is over.
    Postcondition: The memory allocated by the constructor
    for the DCList object has been returned to the heap.
    */
    ~DCList();

    /***** Assignment operator *****/
    const DCList &operator=(const DCList &rightHandSide);
    /*
    Assign a copy of a DCList object to the current object.

    Precondition: none
    Postcondition: A copy of rightHandSide has been assigned to
            this object. A const reference to this DClist is returned.
    */

    //***** isEmpty operation *****
    bool isEmpty() const;
    /*
    Check if a list is empty or not.

    Precondition:  none
    Postcondition: true is returned if the list is empty, false otherwise.
    */

    /*
    Check if item exists in list

    Precondition: data is the value to search for in the list.
    Postcondition: return true if item is found, false otherwise.
                    (execution is interrrupted if the list is empty)
    */
    bool search(const ElementType &data) const;

    /*
    Insert an item into the DCList at a given position.

    Precondition:  data is the value to be inserted
    Postcondition: return true if the item has been inserted into the list at the position
                    determined by pos, false if not.
                    (if the position is not valid the function
                    should display an error message and return false)
    */
    bool insertAtPosition(ElementType data, int pos);

    /*
    Insert an item at the end of the DCList

    Precondition: data is the value to be inserted at the end of the DCList;
                  insertAtPosition() is invoked to insert data at end.
    Postcondition: returns true if data has been inserted into the
                    list at the end,false otherwise.
    */
    bool insertAtEnd(ElementType data);

    /*
    Insert an item at the beginning of the DCList

    Precondition: data is the value to be inserted at the beginning;
                  insertAtPosition() is invoked to insert data at beginning.
    Postcondition: returns true if data has been inserted into the
                    list at the beginning, false otherwise.
    */
    bool insertAtBeginning(ElementType data);

    /*
    Delete the node present at position passes as parameter

    Precondition: pos represents the position of the data to be deleted
    Postcondition: returns true if data at pos has been deleted from the list,
                    false if not (execution interrupted if list is empty).
    */
    bool deleteAtPosition(int pos);

    /*
    Search for the item in the DCList and delete the node before the node
         where data was found

    Precondition:  data is the value to be deleted from the list
    Postcondition: returns true if data is found and deleted from the list,
                    false if not (display an error message and
                    execution is interrupted if list is empty).
    */

    bool deleteBeforeAnElement(ElementType data);

    /*
    Deletes all the occurrences of an item data.

    Precondition: takes an item data of type ElementType
    Postcondition: The function should return the number of deleted nodes.
                    search() and deleteAValue() were invoked
    */
    int findAndDelete(const ElementType &data);

    /*
    Cut the first node from the list.

    Precondition: none
    Postcondition: cuts the first node from the list and returns its data.
                    (If the list is empty, the function should
                        interrupt the execution.)
    */
    ElementType removeFirst();

    /*
    Cut the last node from the list.

    Precondition: none
    Postcondition: cuts the last node from the list and returns its data.
                    (If the list is empty, the function should
                         interrupt the execution.)
    */
    ElementType removeLast();

    /*
    Keeps only the first occurrence of an element in the list
         and removes all the others

    Precondition: none
    Postcondition: returns the number of deleted repeated items.
                    (If the list is empty, the function should
                     interrupt the execution.)
    */
    int deleteDuplicates();

    /*
    Display the content of the list.

    Precondition:  The ostream out is open.
    Postcondition: The list represented by this DCList object has been
                    inserted into out.
    */
    void display(ostream &out) const;
};
//------ Prototype of output operator
ostream &operator<<(ostream &out, DCList &list);

#endif