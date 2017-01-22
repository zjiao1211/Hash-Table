// Name: Zhe Jiao
// loginid: zjiao
// CS 455 PA5

// pa5list.cpp
// a program to test the linked list code necessary for a hash table chain

// You are not required to submit this program for pa5.

// We gave you this starter file for it so you don't have to figure
// out the #include stuff.  The code that's being tested will be in
// listFuncs.cpp, which uses the header file listFuncs.h

// The pa5 Makefile includes a rule that compiles these two modules
// into one executable.

#include <iostream>
#include <string>
#include <cassert>

using namespace std;

#include "listFuncs.h"


int main() {
    cout << "老子要奋战到洛杉矶凌晨四点！！！" << endl;
    
    
    Node *list;
    initList(list);
    listRemove(list, "apple");
    printList(list);
    insertFront(list, "apple", 12);
    insertFront(list, "banana", 17);
    insertFront(list, "orange", 5);
    printList(list);
    cout << "apple有多少个: " << *lookupList(list, "apple") << endl;
    cout << "banana有多少个: " << *lookupList(list, "banana") << endl;
    cout << "orange有多少个: " << *lookupList(list, "orange") << endl;
    
    
    if(lookupList(list, "orange") == NULL) {
        cout << "orange有多少个: " << "0" << endl;
    } else {
        cout << "orange有多少个: " << *lookupList(list, "orange") << endl;

    }
    
    
    cout << "当前有多少个Node: " << numNodes(list) <<endl;
    printList(list);
    
    listRemove(list, "apple");
    cout << "after remove element from this list: " << endl;
    printList(list);
    
    
    cout << "remove banana 成功了没: " << listRemove(list, "banana") << endl;
    cout << "after remove element from this list: " << endl;
    printList(list);
    
    cout << "remove grape 成功了没: " << listRemove(list, "grape") << endl;
    cout << "after remove element from this list: " << endl;
    printList(list);
    cout << endl;

  return 0;
}
