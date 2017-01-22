// Name: Zhe Jiao
// Loginid: zjiao
// CSCI 455 PA5
// Fall 2016


//*************************************************************************
// Node class definition 
// and declarations for functions on ListType

// Note: we don't need Node in Table.h
// because it's used by the Table class; not by any Table client code.


#ifndef LIST_FUNCS_H
#define LIST_FUNCS_H
  
using namespace std;

struct Node {
  string key;
  int value;

  Node *next;

  Node(const string &theKey, int theValue);

  Node(const string &theKey, int theValue, Node *n);
};


typedef Node * ListType;

//*************************************************************************
//add function headers (aka, function prototypes) for your functions
//that operate on a list here (i.e., each includes a parameter of type
//ListType or ListType&).  No function definitions go in this file.


//initial the ListType to Null
void initList(ListType &list);


//insert a couple of Key and Value into hashtable
void insertFront(ListType &list, string theKey, int theValue);


//remove the entry with Key of value target
bool listRemove(ListType &list, string target);


//print all list entries
void printList(ListType list);


//look up if there is an entry with a Key of value target, return the pointer of int data
int* lookupList(ListType list, string target);


//calculate the number of Nodes of the list
int numNodes(ListType list);





// keep the following line at the end of the file
#endif
