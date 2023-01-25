/*
 * The purpose of this project is:
 * -to implement a Doubly Circular Linked List
 *  and allow the the user to interact with it.
 * -Creating and storing user-defined Objects in a Doubly Circular Linked List.
 * -Implementing a well-designed CLI menu for programs.
 * -----------------------------------------------------------
 * File: DCListtester.cpp
 * Author: Wael Mattar
 * Created on October 18, 2022
 */

#include "DoublyCircularList.h"

using namespace std;

void menu();

int main()
{
    // Test the class constructor
    DCList myTestList;
    int choice; // choice of the user
    int pos;
    int input;

    menu();        // display the menu infront of the user to choose an option
    cin >> choice; // choice entered by the user

    // while loop to check that choice!=11
    while (choice != 11)
    {

        switch (choice)
        {

        case 1:
        {
            cout << "Input element to insert at beginning:" << endl;
            cin >> input;

            if (myTestList.insertAtBeginning(input))
            {
                cout << "Element was successfully inserted  "
                     << "at the beginning of the list." << endl;
            }

            cout << myTestList; // printing the list after the operation

            break;
        }

        case 2:
        {
            cout << "Input element to insert at end:" << endl;

            cin >> input; // input choice

            if (myTestList.insertAtEnd(input))
            {
                cout << "Element was successfully inserted "
                     << "at the end of the list" << endl;
            }
            cout << myTestList; // printing the list after the operation
            break;
        }

        case 3:
        {
            cout << "Please enter the position of the list "
                    "you would like to insert an element at (any value >= 1)"
                 << endl;
            cin >> pos; // specified position by the user

            cout << "Please enter the element you like to insert: " << endl;
            cin >> input; // input choice

            if (myTestList.insertAtPosition(input, pos - 1))
            {
                cout << "Element was successfully inserted at position "
                     << pos << endl;
            }

            cout << myTestList; // printing the list after the operation

            break;
        }

        case 4:
        {
            cout << "Please enter position of the list  "
                    "you would like to delete an element at (any value >= 1)"
                 << endl;
            cin >> pos; // input position
            //if element was deleted
            if (myTestList.deleteAtPosition(pos - 1))
            {
                cout << "Element was successfully removed from position "
                     << pos << endl
                     << "\n";
            }

            cout << myTestList; // printing the list after the operation

            break;
        }

        case 5:
        {
            //if list empty
            if (myTestList.isEmpty())
            {
                cout << "The list is Empty." << endl;
            }
            cout << "Please enter the value you want to delete "<<
             "the one before it: "<< endl;
            cin >> input; // input choice

            if (myTestList.deleteBeforeAnElement(input))
            {
                cout << "Element before " << input <<
                             " was deleted successfully\n";
            }

            cout << myTestList; // printing the list after the operation
            break;
        }
        case 6:
        {
            cout << "Please enter the value you want to search for it " << endl;
            cin >> input; // input choice

            if (myTestList.search(input))//if element was found
            {
                cout << input << " exists in the list" << endl;
            }
            else
            {

                cout << input << " does not exist in the list" << endl;
            }
            break;
        }
        case 7:
        {
            //if list empty
            if (myTestList.isEmpty())
            {
                cout << "The list is Empty." << endl;
            }

            cout << "Please enter the value you want to delete all its occurences: " << endl;
            cin >> input; // input choice

            myTestList.findAndDelete(input);

            cout << myTestList << endl; // printing the list after the operation

            break;
        }
        case 8:
        {
            if (myTestList.isEmpty())//if list empty
            {
                cout << "The list is Empty." << endl;
            }
            //store the value from the deleted node
            ElementType value = myTestList.removeFirst();
            cout << "The value of the element that was deleted is " << value << "\n";
            break;
        }

        case 9:
        {
            //if list empty
            if (myTestList.isEmpty())
            {
                cout << "The list is Empty." << endl;
            }
            //store the value from the deleted node
            ElementType value = myTestList.removeLast();
            cout << "The value of the element that was deleted is " << value << "\n";
            cout << myTestList;
            break;
        }
        case 10:
        {
            //if list empty
            if (myTestList.isEmpty())
            {
                cout << "The list is Empty." << endl;
            }
            ElementType value = myTestList.deleteDuplicates();
            cout << "The number of deleted elements are " << value << endl;
            cout << myTestList; // printing the list after the operation
            break;
        }

        default:
            cout << "Invalid choice" << endl;
            break;
        }
        menu();        // displaying the menu
        cin >> choice; // input choice
    }

    // printing a respectful message for the user after using this program
    cout << "Thank you for using this program" << endl
         << endl;

    return 0;
}
// a function named menu() to diplay the menu infront of the user
void menu()
{
    cout << "\nWelcome to Doubly-Circular Linked List Test program." << endl
         << "An Empty DCList of integers has been created for you. " << endl
         << "Please choose one of the following options:" << endl
         << "1-   Insert at beginning" << endl
         << "2-   Insert at end" << endl
         << "3-   Insert at position" << endl
         << "4-   Delete at position" << endl
         << "5-   Delete before an element" << endl
         << "6-   Search element" << endl
         << "7-   Find and delete" << endl
         << "8-   Remove first element" << endl
         << "9-   Remove last element" << endl
         << "10-  Delete duplicated elements" << endl
         << "11-  Exit" << endl
         << endl;
}
