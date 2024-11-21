//Lab 9 Part 2

#include "list.h"
#include "hydro.h"
#include <iostream>
#include <stdlib.h>

//FlowList::~FlowList(){
	//destory();
//}

void FlowList::insert(int year, double flow){
	Node* newnode = new Node;
	newnode->item.year = year;
	newnode->item.flow = flow;
	newnode->next = nullptr;
	
	if (head == nullptr) { //when there is no other value in list
		head = newnode;
	} 
	else {
		Node* current = head;
		Node* before = nullptr;
		
		while (current != nullptr && current->item.year < year) {
		//current cant be nullptr and the year cant be less than value
			before = current;
			current = current->next;
		}
		
		if (before == nullptr) { //when list has values but in order to put in ascending order 
		// we need to put the new values at the start
			newnode->next = head;
			head = newnode;
		}
		else {
			before->next = newnode;
			newnode->next = current;
		}
	}
	
}