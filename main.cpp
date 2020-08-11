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
    for (int i = 0; i < currList->getSize(); i++) {
        // iterate through original list until no nodes are left
        hydraNode *max = currList->getFirst();
        for (int j = 0; j < currList->getSize(); i++) {
            // find max priority
            hydraNode *temp = currList->getFirst();
            if (temp->getPriority() > max->getPriority()) {
                max = temp;
            }
        }
        // insert max to end of new list
        newList->insertAtEnd(max);
        // remove max from currList
        // TODO: remove function that is part of Herculist
        //  takes in a node
        currList->removeNode(max);
    }
    return *currList;


}

Herculist sortByDate() {

}

string askTask() {
    cout << "Enter task: ";
    string task;
    getline(cin, task);
    return task;
}

int askIndex() {
    cout << "Enter line number: ";
//    cin >> index;
    string index;
    getline(cin, index);
    return stoi(index);
}

int main() {
    bool running = true;
//    string initialText;
//    cout << "Enter your first task" << endl;
//    getline(cin, initialText);
    string initialText;
    initialText = askTask();
    Herculist *currList = new Herculist(initialText);
    cout << endl;
    currList->printList(currList->getFirst(), 0);
    cout << endl;
    while (running) {
        string optionChosen;
        cout
                << "Add Task (a) --- Delete Task (d) ---  Set Priority (p)  --- Sort by Priority (s) --- Close Herculist (c)"
                << endl;
        getline(cin, optionChosen);
        if (optionChosen == "c" || optionChosen == "C") {
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
        }

        if (currList->getFirst() == NULL && currList->getLast() == NULL) {
            cout << endl;
            cout << "Empty Herculist..." << endl;
            cout << endl;
        } else {
            cout << endl;
            currList->printList(currList->getFirst(), 0);
            cout << endl;
        }
    }
    return 0;
}
