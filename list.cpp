#include "list.h"
#include "hydro.h"
#include <iostream>
#include <stdlib.h>
#include <fstream>
using namespace std;

FlowList::~FlowList(){
	if (head == nullptr) { //If there is nothing in list
		return;
	}
	
	Node* current = head;
	while (current != nullptr) { //deleting elements starting from head
		Node* temp = current;
		current = current->next;
		delete temp;
	}
	
	head = nullptr;// setting head to nullptr
}

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

void FlowList:: displayLL()const {
	Node* current = head;
	if (head == nullptr) {
    cout << "No data available." << endl;
    return;  // Exit if the list is empty
	}
	cout<<"Year\tFlow (in billions of cubic meters)"<<endl;
	while (current != nullptr) {
		cout<<current->item.year<<"\t"<<current->item.flow<< endl;
		current = current->next;
	}
}

double FlowList::averageLL() const{
	Node* current = head;
	double sum = 0;
	int num=0;
	while (current != nullptr) {
		sum += current->item.flow;
		current = current->next;
		num++;
	}
	
	double av = sum/num;
	return av;
}

int FlowList::insertnew(int year, double flow) {
	Node* newnode = new Node;
	newnode->item.year = year;
	newnode->item.flow = flow;
	newnode->next = nullptr;
	
	Node* temp = head;
	while (temp != nullptr) {
		if (temp->item.year == year) {
			cout<<"Error: duplicate data."<<endl;
			return 1;
		}	
		temp = temp->next;
	}

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
	
	cout<<"New record inserted successfully."<<endl;
	return 0;
}

void FlowList::saveLL() {
	ofstream out_stream("flow.txt");  // Open file to write
    if (!out_stream) {
        cout << "Error: Could not open file flow.txt for writing." << endl;
        exit(1);
    }
	
	Node* current = head;
	while (current != nullptr){
		out_stream<<current->item.year << " " << current->item.flow <<endl;
		current = current->next;
	}
	out_stream.close();
}

void FlowList::removeLL(int year) {
	if (head == nullptr) { //when there is nothing in list
		cout<< "Error: No such a data" << endl;
		return;
	}
	
	if (head->item.year == year) { //when head ptr already points to value we need to delete
		Node* temp = head;
		head = head->next;
		delete temp;
		cout<<"Record was successfully removed."<< endl;
		return;
	}
	
	Node* current = head; //None of the above situations fit, we tranverse through list to find the exact list
	Node* before = nullptr;
	while (current != nullptr && current -> item.year != year) { //transverse through linked list
		before = current;
		current = current->next; 
	}
	if (current != nullptr) {//deletes the specific node
		before->next = current->next;
		delete current;
		cout<<"Record was successfully removed."<< endl;
		return;
	}
	
	cout << "Error: No such a data" << endl;
}
