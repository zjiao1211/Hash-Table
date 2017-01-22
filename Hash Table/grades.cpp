// Name: Zhe Jiao
// Loginid: zjiao
// CSCI 455 PA5
// Fall 2016

/*
 * grades.cpp
 * A program to test the Table class.
 * How to run it:
 *      grades [hashSize]
 * 
 * the optional argument hashSize is the size of hash table to use.
 * if it's not given, the program uses default size (Table::HASH_SIZE)
 *
 */

#include "Table.h"

// cstdlib needed for call to atoi
#include <cstdlib>

void readCommand(Table * grades);
void insert(Table * grades);
void change(Table * grades);
void lookup(Table * grades);
void remove(Table * grades);
void help();

int main(int argc, char * argv[]) {

  // gets the hash table size from the command line

    int hashSize = Table::HASH_SIZE;

    Table * grades;  // Table is dynamically allocated below, so we can call
                   // different constructors depending on input from the user.

    if (argc > 1) {
        hashSize = atoi(argv[1]);  // atoi converts c-string to int
        if (hashSize < 1) {
            cout << "Command line argument (hashSize) must be a positive number" << endl;
            return 1;
        }
        grades = new Table(hashSize);
    }
    else {   // no command line args given -- use default table size
        grades = new Table();
    }

    grades->hashStats(cout);

    // add more code here
    // Reminder: use -> when calling Table methods, since grades is type Table*

    readCommand(grades);
    
    return 0;
}

void readCommand(Table * grades) {
    
    while(true) {
        cout << "cmd>";
        string command;
        cin >> command;
        
        if (command == "insert") {
            insert(grades);
        } else if (command == "change") {
            change(grades);
        } else if (command == "lookup") {
            lookup(grades);
        } else if (command == "remove") {
            remove(grades);
        } else if (command == "print") {    // Prints out all names and scores in the table.
            grades->printAll();
        } else if (command == "size") {     // Prints out the number of entries in the table.
            cout << "the number of entries in the table is: " << grades->numEntries() << endl;
        } else if (command == "stats") {    // Prints out statistics about the hash table at this point.
            grades->hashStats(cout);
        } else if (command == "help") {
            help();
        } else if (command == "quit") {     // Exits the program.
            cout << "Exits the program" << endl;
            break;
        } else {
            cout << "ERROR: invalid command" << endl;
            help();
        }
    }
}


// Insert this name and score in the grade table.
// If this name was already present, print a message to that effect, and don't do the insert.
void insert(Table * grades) {
    string name;
    int score;
    cin >> name;
    cin >> score;
    grades->insert(name, score);
}


// Change the score for name. Print an appropriate message if this name isn't present.
void change(Table * grades) {
    string name;
    int score;
    cin >> name;
    cin >> score;
    int *val = grades->lookup(name);
    if(val == NULL) {
        cout << "this name isn't present" << endl;
    } else {
        *val = score;
    }
}


// Lookup the name, and print out his or her score,
// or a message indicating that student is not in the table.
void lookup(Table * grades) {
    string name;
    cin >> name;
    int *val = grades->lookup(name);
    if(val == NULL) {
        cout << "student is not in the table" << endl;
    } else {
        cout << name << ": "<< *val << endl;
    }
}


// Remove this student.
// If this student wasn't in the grade table, print a message to that effect.
void remove(Table * grades) {
    string name;
    cin >> name;
    bool result = grades->remove(name);
    if(result == false) {
        cout << "this student wasn't in the grade table" << endl;
    }
}


// Prints out a brief command summary.
void help() {
    cout << "You need to enter the following commands: " << endl;
    cout << "'insert'   insert name score" << endl;
    cout << "'change'   change name newscore" << endl;
    cout << "'lookup'   lookup name" << endl;
    cout << "'remove'   remove name" << endl;
    cout << "'print'    print" << endl;
    cout << "'size'     size" << endl;
    cout << "'stats'    stats" << endl;
    cout << "'help'     help" << endl;
    cout << "'quit'     quit" << endl;
}


