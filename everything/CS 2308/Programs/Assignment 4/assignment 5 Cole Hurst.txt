/****************************************************
File Name: assign5_cbh65.cpp

Author: Cole Hurst
Date: 4.16.2018
Assignment Number: 5
CS 2308.262 Spring 2018
Lecture Instructor: Yijuan Lu


*****************************************************/

#include <iostream>
using namespace std;

#include "StringList.h"

/*****************************************************
StringList :: StringList(): a function calls to the
constructor and creates the first node to a new linked list.
*****************************************************/
StringList :: StringList()
{
    head = NULL;
}

/*****************************************************
StringList :: ~StringList(): a function that calls to the linked list
and deletes all nodes in said linked list until it is wiped from the memory
*****************************************************/
StringList :: ~StringList()
{
    StringNode *p;
    p = head;

    while (p) {

        delete p;
        p = p->next;
    }
}

/*****************************************************
int StringList :: count(): A function then, when called to, will display the
number of nodes within a linked list at that given time.
Returns: integer of the number of nodes 0 or more.
*****************************************************/
int StringList :: count()
{
    StringNode *p;
    p = head;
    int listcount = 0;   //establishes a variable to count with
    while(p != NULL)
    {
        p = p->next;
        listcount++;
    }

    return listcount;    //returns the count variable
}

/*****************************************************
void StringList :: add(string dot): A void function that takes a new string
variable and adds it to a new node within a linked list.
string dot: the new string that is being added.
*****************************************************/
void StringList :: add(string dot)
{
    StringNode *newNode = new StringNode;   //creating the new node.
    newNode ->data = dot;
    newNode->next = NULL;
    newNode->next = head;
    head = newNode;  //appoints the new node to the head of the linked list.
}

/*****************************************************
bool StringList :: remove(string dot): a bool function that removes a specific
node from the linked list and returns a true or false if it was found and deleted.
string dot: the string variable that is being searched for to be deleted.
return: true statement for a completed deletion. false for failure to find the
string and no deletion took place.
*****************************************************/
bool StringList :: remove(string dot)
{
    StringNode *p;
    p = head;
    StringNode *n;
    n = NULL;

    while ((p!= NULL) && ((p->data != dot))) //while loop that searches the list
    {
        n = p;
        p = p->next;
    }

    if (p != NULL)
    {
        if(p == head) //if the variable in question was the head, would allocate
                      //a new head
        {
            head = p->next;
            delete p;
            return true;
        }
        else
        {
            n->next = p->next;
            delete p;
            return true;
        }
    }
    else
        return false;  //if the string was not found and deleted, returns false.
}

/*****************************************************
void StringList:: display(): displays the data within each node until the linked
list is over.
*****************************************************/
void StringList:: display()
{
    StringNode *p;
    p = head;
    while(p != NULL)
    {
        cout << p->data << endl;
        p = p->next;
    }
}

/*****************************************************
string StringList :: minimum(): a function that searches through the linked list
and returns the string that would occur first in alphabetical order.
return: string in the linked list that occurs first in alphabetical order
*****************************************************/
string StringList :: minimum()
{
    StringNode *p = head;
    string mini = p->data; //assigns the mini variable to the head node

    while(p->next != NULL)
    {
        p = p->next;
        if(p->data < mini) //if the string being compared to mini occurs first
            mini = p->data;//the new node data is assigned to mini.
    }
    return mini;
}

/*****************************************************
void StringList :: sort(): A function that creates a new linked list by comparing
the new list to the current list. The new list is a duplicate of the current,
but all the node's data is in alphabetical order.
*****************************************************/
void StringList :: sort()
{
    StringNode *newHead = NULL;
    string minData = "NULL";

    while (head != NULL)
        {
            minData = minimum();
            if(minData == "NULL") //
                cout << "The old list was empty." << endl;
            remove (minData);

            if(newHead == NULL)
            {
                StringNode *newN = new StringNode;
                newN->data = minData;
                newN->next = NULL;
                newHead = newN;
            }
            else
            {
                StringNode *newN = new StringNode;
                newN->data = minData;
                newN->next = NULL;
                StringNode *p = newHead;

                while(p->next != NULL)
                    p = p->next;

                p->next = newN;
            }
        }
    head = newHead; //assigns new head to the old head.
}

