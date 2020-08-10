
#include "Herculist.hpp"
#include "hydraNode.hpp"
#include <iostream>
#include <stdlib.h>
using namespace std;

Herculist::~Herculist() {

}

Herculist::Herculist() {

}

void Herculist::addTask(int ind, string x) // at index (call by value)
{
	if(first == NULL)	// adds node to empty list
	{
		first = new hydraNode(x);
		last = first;
	}
	else
	{
		hydraNode* temp = first;
		int count = 1;
		while(count < ind && temp != NULL)
		{
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
	hydraNode* temp = first;
	string x = temp->task;
	int count = 0;
	while(count < ind && temp != NULL)
	{
		temp = temp->next;
		count+=1;
	}
	if(ind == 0)	// removes first node in list
	{
		first = first->next;
		if(first != NULL)
		{
			first->prev = NULL;
		}
		delete temp;
		size--;
	}
	else if(temp == last)	// removes last node in list
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



void Herculist::completeTask() // at index (call by reference)
{

}


