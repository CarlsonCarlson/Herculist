
#ifndef HERCULIST_HERCULIST_HPP
#define HERCULIST_HERCULIST_HPP

#include "hydraNode.hpp"
#include <iostream>
#include <stdlib.h>
using namespace std;

class Herculist {

    hydraNode *first;
    hydraNode *last;
    int size;
public:
    // constructor
    Herculist();
    Herculist(string text);
    ~Herculist();

    // methods
    void addTask(int ind, string x); // at index (call by value)
    void removeTask(int ind); // at index (call by pointer)
    void completeTask(int ind); // at index (call by reference)
    void insertAtEnd(hydraNode *node);
    void removeNode(hydraNode *node);

    // getter
    hydraNode *getFirst();
    hydraNode *getLast();
    int getSize();

    // Print
    void printList(hydraNode *currNode, int &count);

};


#endif //HERCULIST_HERCULIST_HPP
