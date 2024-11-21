//Lab 9 

#include "hydro.h"

#include <stdlib.h>
#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std; 

int readData(ifstream& file, FlowList& list);
//that reads records years and flows from input file (flow.txt), inserts them into
//the list, and returns the number of records in the file
int menu();
//that displays a menu and returns the user’s choice (an integer 1 to 5)
void display(const FlowList& list);
//that displays years and flows, and shows the average of the flows in the list
void addData(FlowList& list, int year, double flow);
//that prompts the user to enter new data, inserts the data into the linked list, and
//updates the number of records
void removeData(FlowList& list, int year);
//that prompts the user to indicate what year to be removed, removes a single
//record from the list, and updates the number of record
double average(const FlowList& list);
//that returns the flow average in the given list
void saveData(FlowList& data, ofstream& file);
//that opens the flow.txt file for writing and writes the contents of the linked list
//(annual flow records) into the file
void pressEnter();
//that displays <<<Press Enter to Continue>>>, and waits for the user
//to press the <Return Key> .
void displayHeader();

int main(){
	displayHeader();
	
	pressEnter(); 
	
	ifstream in_stream("flow.txt"); //opening file to read
	if (!in_stream) {
        cout << "Error: Could not open file flow.txt for reading." << endl;
        exit(1);
    }
	
	FlowList data; // FlowList object to store data
	
	int number_record = readData(in_stream, data); //read from file
	
	in_stream.close(); //close file
}