/**
This file was created by Arnav Saxena. This code defines a structure for a linked list node and further a class that uses this structure to implement some basic features of linked list.
This linked list class is able to  create, insert nodes and display the values inside a linked list
**/
#include <iostream>
using namespace std;

// structure for linked list node
struct LinkedListNode
{
    int value; // this node is capable of storing integer values
    LinkedListNode *next = NULL;
};

class LinkedList
{
private:
    // inital node of the list should point to null
    LinkedListNode *head = NULL;
    // reference to the last node in the list
    LinkedListNode *currentNode = head;
    // stores the numver of elements currently in the list
    int numberOfElements = 0;

public:
    // Constructors for the list
    LinkedList();                       // default constructor to initalise the object
    LinkedList(int val);                // initalise the list with a value
    LinkedList(int values[], int size); // initialise the list with an array
    void insertValue(int value);        // method to insert an element into the linked list
    LinkedListNode *listHead();         // function to return the head of the list (getter function)
    void displayList();                 // function to display the elements in the list
};

LinkedList::LinkedList() {}

LinkedList::LinkedList(int val)
{                              // constructor that initialises the linked list with a single value
    head = new LinkedListNode; // create a new linkedListNode to store the value in and assign it to the head pointer of the linked list
    head->value = val;         // push the value into the node
    numberOfElements++;        // update the number of elements present inside of the linked list
}

LinkedList::LinkedList(int value[], int size)
{ // constructor that initialises the linked list with the values recieved from an array
    for (int i = 0; i < size; i++)
    {
        LinkedList::insertValue(value[i]); // insert values inside the list one by one
    }
}

LinkedListNode *LinkedList::listHead()
{
    return head;
}

void LinkedList::insertValue(int value)
{

    // creating a new node by getting a pointer to suffiicient memory from the heap
    LinkedListNode *newNode = new LinkedListNode;
    newNode->value = value; // assigning new value to the new node
    if (head == NULL)
    {
        head = newNode;
        currentNode = head;
        return;
    }

    currentNode->next = newNode;
    currentNode = currentNode->next; // current node pointer shifts to the end of the list, thus pointing to the latest node that was added to the linked lsit
}

void LinkedList::displayList()
{
    LinkedListNode *temp = listHead(); // get the head of the list
    while (temp != NULL)
    {                        // traverse the list
        cout << temp->value; // display the value of the current node
        if (temp->next != NULL)
        { // if the next is not null, show an arrow for linked list
            cout << "-->";
        }
        temp = temp->next; // move on to the next node
    }
}