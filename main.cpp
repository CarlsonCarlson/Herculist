#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "Herculist.hpp"
#include "hydraNode.hpp"

using namespace std;

Herculist sortByPriority(Herculist *currList) {
    // must not unsort an already sorted list if given one
    // must be able to sort a reverse sorted list
    // needs to sort lost that has duplicates
    // needs to sort chainsaw pattern up/down
    // TODO: make exception that doesn't allow it it sort an empty list
    Herculist *newList = new Herculist();
    while (currList->getSize() > 0) {
        // iterate through original list until no nodes are left
        hydraNode *max = currList->getFirst();
        hydraNode *temp = currList->getFirst();
        while (temp != NULL) {
            // find max priority
            if (temp->getPriority() > max->getPriority()) {
                max = temp;
            }
//            if (temp != NULL) {
            temp = temp->getNext();
//            }
        }
        // insert max to end of new list
        newList->insertAtEnd(max);
        // remove max from currList
        // TODO: remove function that is part of Herculist
        //  takes in a node
        currList->removeNode(max);
    }
    return *newList;


}

// TODO: maybe later
//Herculist sortByDate() {
//
//}

string askTask() {
    cout << "Enter task: ";
    string task;
    getline(cin, task);
    return task;
}

int askIndex() {
    cout << "Enter line number: ";
    string index;
    getline(cin, index);
    return stoi(index);
}

int main() {
    bool running = true;
    string initialText;
    initialText = askTask();
    Herculist *currList = new Herculist(initialText);
    cout << endl;
    int firstCount = 0;
    currList->printList(currList->getFirst(), firstCount);
    cout << endl;
    while (running) {
        string optionChosen;
        cout
                << "Add Task (a) --- Complete Task (c) --- Delete Task (d) ---  Set Priority (p)  --- Sort by Priority (s) --- Exit Herculist (e)"
                << endl;
        cout << "Option: ";
        getline(cin, optionChosen);
        if (optionChosen == "e" || optionChosen == "E") {
            running = false;
        } else if (optionChosen == "a" || optionChosen == "A") {
            // TODO: add at bottom and add at top
            string task = askTask();
            int index = askIndex();
            currList->addTask(index, task);
        } else if (optionChosen == "d" || optionChosen == "D") {
            int index = askIndex();
            currList->removeTask(index);
        } else if (optionChosen == "p" || optionChosen == "P") {
            bool indexIsValid = false;
            int index;
            while (!indexIsValid) {
                index = askIndex();
                if (index + 1 > currList->getSize()) {
                    // catches if ind given doesn't exist
                    cout << "Error: index doesn't exist in Herculist size of " << currList->getSize() << endl;
                } else if (index < 0) {
                    // catches if ind is a negative number
                    cout << "Error: Enter a positive number" << endl;
                } else {
                    indexIsValid = true;
                }
            }
            hydraNode *temp = currList->getFirst();
            int count = 0;
            while (count < index && temp != NULL) {
                temp = temp->getNext();
                count += 1;
            }
            bool isValid = false;
            while (!isValid) {
                cout << "Enter priority (*) from 0-3: ";
                // TODO: give error message if not 0-3
                string star;
                getline(cin, star);
                if ((stoi(star) >= 0 && stoi(star) <= 3)) {
                    isValid = true;
                    temp->setPriority(stoi(star));
                }
            }
        } else if (optionChosen == "s" || optionChosen == "S") {
            *currList = sortByPriority(currList);
        } else if (optionChosen == "c" || optionChosen == "C") {
            int index = askIndex();
            currList->completeTask(index);
        }

        if (currList->getFirst() == NULL && currList->getLast() == NULL) {
            cout << endl;
            cout << "Empty Herculist..." << endl;
            cout << endl;
        } else {
            cout << endl;
            int printCount = 0;
            currList->printList(currList->getFirst(), printCount);
            cout << endl;
        }
    }
    return 0;
}
