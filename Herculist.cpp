
#include "Herculist.hpp"
#include "hydraNode.hpp"
#include <iostream>
#include <stdlib.h>
using namespace std;

Herculist::~Herculist() {
    // destructor
}

Herculist::Herculist() {
    // Constructor
    first = NULL;
    last = NULL;
    size = 0;
}

Herculist::Herculist(string text) {
    hydraNode *node = new hydraNode(text);
    first = node;
    last = node;
    size = 1;
}

void Herculist::addTask(int ind, string x) // at index (call by value)
{
    if (ind > size) {
        // catches if ind given doesn't exist
        cout << "Error: index doesn't exist in Herculist size of " << size << endl;
        return;
    }
    if (ind < 0) {
        // catches if ind is a negative number
        cout << "Error: Enter a positive number" << endl;
        return;
    }
    if (first == NULL)    // adds node to empty list
    {
        first = new hydraNode(x);
        last = first;
    } else {
        hydraNode *temp = first;
        int count = 1;
        while (count < ind && temp != NULL) {
            temp = temp->next;
			count+=1;
		}
		if(ind == 0)	// adds node to front of list
		{
			hydraNode *newNode = new hydraNode(x);
			newNode->next=first;
			newNode->prev = NULL;
			first->prev=newNode;
			first=newNode;
		}
		else if(temp == last)	// adds node to end of list
		{
			hydraNode *newNode = new hydraNode(x);
			newNode->next = NULL;
			newNode->prev=last;
			last->next=newNode;
			last = newNode;
		}
		else if(temp != NULL)
		{
			hydraNode* newNode = new hydraNode(x);
			newNode->next = temp->next;
			newNode->prev = temp;
			if(temp->next != NULL)
			{
				temp->next->prev = newNode;
			}
			temp->next = newNode;
		}
	}
	size+=1;
}



void Herculist::removeTask(int ind) // at index (call by pointer)
{
    if (first == NULL) {
        cout << "List is empty - cannot remove a task that doesn't exist!" << endl;
        return;
    }
    if (ind + 1 > size) {
        // catches if ind given doesn't exist
        cout << "Error: index doesn't exist in Herculist size of " << size << endl;
        return;
    }
    if (ind < 0) {
        // catches if ind is a negative number
        cout << "Error: Enter a positive number" << endl;
        return;
    }
    hydraNode *temp = first;
    string x = temp->task;
    int count = 0;
    while (count < ind && temp != NULL) {
        temp = temp->next;
        count += 1;
    }
    if (ind == 0 && temp == last) { // remove only node in list
        // TODO: only node in list
        first = NULL;
        last = NULL;
        delete temp;
        size--;
//        if(first != NULL)
//        {
//            first->prev = NULL;
//        }
//        last = last->prev;
//        if(last != NULL)
//        {
//            last->next = NULL;
//        }
    } else if (ind == 0)    // removes first node in list
    {
        first = first->next;
        if (first != NULL) {
            first->prev = NULL;
        }
        delete temp;
        size--;
    } else if (temp == last)    // removes last node in list
	{
		hydraNode *temp = last;
		string x = temp->task;
		last = last->prev;
		if(last != NULL)
		{
			last->next = NULL;
		}
		delete temp;
		size--;
	}
	else if(temp != NULL)
	{
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		delete temp;
		size--;
	}
}


void Herculist::completeTask(int ind) // at index (call by reference)
{
    if (first == NULL) {
        cout << "List is empty - cannot complete a task that doesn't exist!" << endl;
        return;
    }
    if (ind + 1 > size) {
        // catches if ind given doesn't exist
        cout << "Error: index doesn't exist in Herculist size of " << size << endl;
        return;
    }
    if (ind < 0) {
        // catches if ind is a negative number
        cout << "Error: Enter a positive number" << endl;
        return;
    }
    // traverses list to index ind
    hydraNode *temp = first;
    int count = 0;
    while (count < ind && temp != NULL) {
        temp = temp->next;
        count += 1;
    }
    temp->isComplete = true;
}

void Herculist::insertAtEnd(hydraNode *node) {
    // TODO: new constructor for isComplete may be needed
    hydraNode *newNode = new hydraNode(node->task, node->priority, node->isComplete);
    if (size > 0) {
        newNode->next = NULL;
        newNode->prev = last;
        last->next = newNode;
        last = newNode;
    } else {
        // inserting first node in list
        first = newNode;
        last = newNode;
    }
    size++;
}

void Herculist::removeNode(hydraNode *node) {
    if (node == first)    // removes first node in list
    {
        first = first->next;
        if (first != NULL) {
            first->prev = NULL;
        }
        delete node;
        size--;
    } else if (node == last)    // removes last node in list
    {
        node = last;
        last = last->prev;
        if (last != NULL) {
            last->next = NULL;
        }
        delete node;
        size--;
    } else if (node != NULL) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        delete node;
        size--;
    }
}

//getters
hydraNode *Herculist::getFirst() {
    // TODO: is that right ?
    return first;
}

hydraNode *Herculist::getLast() {
    // TODO: is that right ?
    return last;
}

int Herculist::getSize() {
    return size;
}

void Herculist::printList(hydraNode *currNode, int &count) {
    // recursive
    if (currNode->next == NULL) {
        // base case
        currNode->printNode(count);
        return;
    }
    currNode->printNode(count);
    count++;
    printList(currNode->next, count);
}


