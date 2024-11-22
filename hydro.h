
#ifndef HYDRO_H
#define HYDRO_H

#include "list.h"
#include <iostream>
#include <fstream>

using namespace std;

// Function declarations 
int readData(ifstream& file, FlowList& list);  // Function to read data from the file
int menu();  // Displays a menu and returns the user’s choice
void display(const FlowList& list);  // Displays years and flows, and average

int addData(FlowList& list, int year, double flow);  // Adds data to the list
void removeData(FlowList& list, int year);  // Removes data from the list

double average(const FlowList& list);  // Returns the flow average in the list

void saveData(FlowList& list);  //opens file for writing
void pressEnter();  // Prompts the user to press Enter
void displayHeader();
int menu();

#endif 