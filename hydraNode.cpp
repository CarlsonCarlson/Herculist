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

hydraNode::hydraNode(string text, int stars, bool taskComplete) {
    // Constructor
    next = NULL;
    prev = NULL;
    task = text;
    priority = stars;
    isComplete = taskComplete;
}

hydraNode::~hydraNode() {
    // destructor
	// cout << "Deleted: '" << task << "'" << endl;
}

void hydraNode::printNode(int count) {
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
        if (isComplete) {
            cout << "#" << count << ": " << "-----" << task << "-----" << endl;
        } else {
            cout << "#" << count << ": " << task << endl;
        }
    } else {
        if (isComplete) {
            cout << "#" << count << ": " << "----- " << priorityText << " " << task << "-----" << endl;
        } else {
            cout << "#" << count << ": " << priorityText << " " << task << endl;
        }
    }
}

hydraNode *hydraNode::getNext() {
    return next;
}

int hydraNode::getPriority() {
    return priority;
}

void hydraNode::setPriority(int star)
{
	priority = star;
}
