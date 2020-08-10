#ifndef HERCULIST_HYDRANODE_HPP
#define HERCULIST_HYDRANODE_HPP

#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

class hydraNode {
    friend class herculist;

    bool isComplete; // determines whether the task is marked as complete or not
    // TODO: possible try this
    //  https://stackoverflow.com/questions/8357203/is-it-possible-to-display-text-in-a-console-with-a-strike-through-effect

    string task; // the text that shows in the UI as the name of the task
    hydraNode *next;
    hydraNode *prev;
    // TODO: date field
    int priority; // 3 is highest priority and 1 is lowest priority (1-3)
public:
    //methods
    hydraNode(string task, int priority);

    ~hydraNode();

    void printNode();
};


#endif //HERCULIST_HYDRANODE_HPP
