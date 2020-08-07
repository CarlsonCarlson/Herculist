#ifndef HERCULIST_HYDRANODE_HPP
#define HERCULIST_HYDRANODE_HPP

#include <iostream>
#include <string>

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
};


#endif //HERCULIST_HYDRANODE_HPP
