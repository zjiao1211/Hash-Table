// Name: Zhe Jiao
// Loginid: zjiao
// CSCI 455 PA5
// Fall 2016


#include <iostream>

#include <cassert>

#include "listFuncs.h"

using namespace std;

Node::Node(const string &theKey, int theValue) {
  key = theKey;
  value = theValue;
  next = NULL;
}

Node::Node(const string &theKey, int theValue, Node *n) {
  key = theKey;
  value = theValue;
  next = n;
}




//*************************************************************************
// put the function definitions for your list functions below


//initial the ListType to Null
void initList(ListType &list) {
    list = NULL;
}


//insert a couple of Key and Value into hashtable
void insertFront(ListType &list, string theKey, int theValue) {
    Node *newGuy = new Node(theKey, theValue, list);
    list = newGuy;
}


//remove the entry with Key of value target
bool listRemove(ListType &list, string target) {

    if(list == NULL) {
        return false;
    }
    Node *curr = list;
    if(curr->key == target) {
        list = list->next;
        delete curr;
        return true;
    }
    while(curr->next != NULL) {
        if(curr->next->key == target) {
            Node *temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
            return true;
        }
        curr = curr->next;
    }
    return false;
}


//print all list entries. If not null, print all entries
void printList(ListType list){
    if (list == NULL) {
        return;
    }
    Node *curr = list;
    while (curr != NULL) {
        cout << curr->key << " " << curr->value << endl;
        curr = curr->next;
    }
}


//look up if there is an entry with a Key of value target, return the pointer of int data
int* lookupList(ListType list, string target){
    if (list == NULL) {
        return NULL;
    }
    Node *curr = list;
    while (curr != NULL) {
        if(curr->key == target) {
            return &(curr->value);
        }
        curr = curr->next;
    }
    return NULL;
}


//calculate the number of Nodes of the list
int numNodes(ListType list) {
    int sum = 0;
    if(list == NULL) {
        return sum;
    }
    Node *curr = list;
    while (curr != NULL) {
        sum++;
        curr = curr->next;
    }
    return sum;
}





