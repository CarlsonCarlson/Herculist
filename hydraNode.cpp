#include <stdlib.h>
#include <iostream>
#include "hydraNode.hpp"
using namespace std;


hydraNode::hydraNode(string text) {
    // Constructor
    next = NULL;
    prev = NULL;
    task = text;
    priority = NULL;
    isComplete = false;
}

hydraNode::hydraNode(string text, int stars) {
    // Constructor
    next = NULL;
    prev = NULL;
    task = text;
    priority = stars;
    isComplete = false;
}

hydraNode::~hydraNode() {
    // destructor
    cout << "Deleted: '" << task << "'" << endl;
}

void hydraNode::printNode(int count) {
    // TODO: include something that shows if the task is complete or not
    string priorityText;
    if (priority == 3) {
        priorityText = "***";
    } else if (priority == 2) {
        priorityText = "**";
    } else if (priority == 1) {
        priorityText = "*";
    } else {
        priorityText = "";
    }

    if (priorityText == "") {
        cout << "#" << count << ": " << task << endl;
    } else {
        cout << "#" << count << ": " << priorityText << " " << task << endl;
        // TODO: add date on second line
    }
}

hydraNode *hydraNode::getNext() {
    return next;
}
