
#ifndef HERCULIST_HERCULIST_HPP
#define HERCULIST_HERCULIST_HPP

#include "hydraNode.hpp"
#include <stdlib.h>
#include <string>

class Herculist {
    hydraNode *first;
    hydraNode *last;
    int size;
public:
    // methods
    Herculist();

    ~Herculist();

    void addTask(); // at index (call by value)
    void removeTask(); // at index (call by pointer)
    void completeTask(); // at index (call by reference)
};


#endif //HERCULIST_HERCULIST_HPP
