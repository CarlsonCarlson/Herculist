#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "Herculist.hpp"
#include "hydraNode.hpp"

using namespace std;

Herculist sortByPriority() {
    //must not unsort an already sorted list if given one
    // must be able to sort a reverse sorted list
    // needs to sort lost that has duplicates
    // needs to sort chainsaw pattern up/down
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
        cout << "Add task (a) --- Delete task (d) --- Close Herculist (c)" << endl;
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
        }

        if (currList->getFirst() == NULL && currList->getLast() == NULL) {
            cout << endl;
            cout << "Empty Herculist..." << endl;
            cout << endl;
//            string otherText;
//            otherText = askTask();
//            Herculist *currList = new Herculist(otherText);
//            cout << endl;
//            currList->printList(currList->getFirst());
//            cout << endl;
        } else {
            cout << endl;
            currList->printList(currList->getFirst(), 0);
            cout << endl;
        }
    }
    return 0;
}
