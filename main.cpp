#include <iostream>
#include <stdlib.h>
#include "Herculist.hpp"
#include "hydraNode.hpp"
using namespace std;

int main() {
    bool running = true;
    string initialText;
    cout << "Enter your first task" << endl;
    cin >> initialText;
    Herculist *currList = new Herculist(initialText);
    while (running) {
        currList->printList(currList->getFirst());
        string stopProgram;
        cout << "Do you want to stop the program? (y/n)" << endl;
        cin >> stopProgram;
        if (stopProgram == "y" || stopProgram == "Y") {
            running = false;
        }
    }
    return 0;
}

Herculist sortByPriority() {
    //must not unsort an already sorted list if given one
    // must be able to sort a reverse sorted list
    // needs to sort lost that has duplicates
    // needs to sort chainsaw pattern up/down
}

Herculist sortByDate() {
}

