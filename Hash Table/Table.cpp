// Name: Zhe Jiao
// Loginid: zjiao
// CSCI 455 PA5
// Fall 2016

// Table.cpp  Table class implementation


/*
 * Modified 11/22/11 by CMB
 *   changed name of constructor formal parameter to match .h file
 */

#include "Table.h"

#include <iostream>
#include <string>
#include <cassert>

using namespace std;
// listFuncs.h has the definition of Node and its methods.  -- when
// you complete it it will also have the function prototypes for your
// list functions.  With this #include, you can use Node type (and
// Node*, and ListType), and call those list functions from inside
// your Table methods, below.

#include "listFuncs.h"


//*************************************************************************


// create an empty table with size of HASH_SIZE
Table::Table() {
    hashSize = HASH_SIZE;
    data = new ListType[hashSize];
    for(int i = 0; i < hashSize; i++) {
        initList(data[i]);
    }
}

// create an empty table with size of hSize
Table::Table(unsigned int hSize) {
    hashSize = hSize;
    data = new ListType[hashSize];
    for(int i = 0; i < hashSize; i++) {
        initList(data[i]);
    }
}


// returns the address of the value or NULL if key is not present
int * Table::lookup(const string &key) {
    ListType curr = data[hashCode(key)];
    return lookupList(curr, key);
}


// remove an element
bool Table::remove(const string &key) {
    ListType &curr = data[hashCode(key)];
    return listRemove(curr, key);
    
}


// insert a new pair into the table
bool Table::insert(const string &key, int value) {
    ListType &curr = data[hashCode(key)];
    if(lookupList(curr, key) != NULL) {
        cout << key << " is already present, don't do the insert" << endl;
        return false;
    } else {
        insertFront(curr, key, value);
        return true;
    }
}


// number of entries in the table
int Table::numEntries() const {
    int sum = 0;
    for(int i = 0; i < hashSize; i++) {
        ListType temp = data[i];
        int val = numNodes(temp);
        sum += val;
    }
    return sum;
}


// print out all the entries in the table, one per line.
void Table::printAll() const {
    for(int i = 0; i < hashSize; i++) {
        ListType temp = data[i];
        printList(temp);
    }
}


// prints out info to let us know if we're getting a good distribution
// of values in the hash table.
void Table::hashStats(ostream &out) const {
    int nonEmptyBuckets = 0;
    int longestChain = 0;
    for(int i = 0; i < hashSize; i++) {
        ListType temp = data[i];
        int length = numNodes(temp);
        if( length != 0) {
            nonEmptyBuckets++;
        }
        if(length > longestChain) {
            longestChain = length;
        }
    }
    out << "number of buckets: " << hashSize << endl;
    out << "number of entries: " << numEntries() << endl;
    out << "number of non-empty buckets: " << nonEmptyBuckets << endl;
    out << "longest chain: " << longestChain << endl;
   
}
    

// add definitions for your private methods here


