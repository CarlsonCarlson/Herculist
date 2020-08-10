
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
    // methods
    Herculist();

    ~Herculist();

    void addTask(int ind, string x); // at index (call by value)
    void removeTask(int ind); // at index (call by pointer)
    void completeTask(); // at index (call by reference)
};


#endif //HERCULIST_HERCULIST_HPP
