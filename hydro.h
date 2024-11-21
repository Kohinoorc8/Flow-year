#ifndef HYDRO_H
#define HYDRO_H

#include "list.h"
#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <fstream>
using namespace std;

void displayHeader(){
	cout << "Program: Flow Studies, Fall 2020" << endl;
	cout << "Version: 1.0" << endl;
	cout << "Lab section: B01" << endl;
	cout << "Produced by: Kohinoor Chauhan and Erin Kim" << endl;
}

void pressEnter(){
	cout << "\n<<< Press Enter to Continue>>>>\n";
	cin.get();
}

int readData(ifstream& file, FlowList& list){
	int year;
    double flow;
    int count = 0;  // To count how many records were read and added

    // Read data from the file and add it to the list
    while (file >> year >> flow) {
        list.insert(year, flow);  // Call addData method of FlowList to insert the data
        count++;  // Increment the counter
    }

    return count;
}

#endif