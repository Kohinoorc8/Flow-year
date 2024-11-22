#include "hydro.h"
#include "list.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

// Definitions of functions mentioned in hydro.h
void displayHeader() {
	cout << "Program: Flow Studies, Fall 2020" << endl;
    cout << "Version: 1.0" << endl;
    cout << "Lab section: B01" << endl;
    cout << "Produced by: Kohinoor Chauhan and Erin Kim" << endl;
}

void pressEnter() {
    cout << "\n<<< Press Enter to Continue>>>>\n";
    cin.get();
}

int readData(ifstream& file, FlowList& list) {
    int year;
    double flow;
    int count = 0;  // To count how many records were read and added

    // Read data from the file and add it to the list
    while (file >> year >> flow) {
		//cout << "Read data: Year = " << year << ", Flow = " << flow << endl; debug print
        list.insert(year, flow);
        count++;  // Increment the counter
    }

    return count;
}

void display(const FlowList& list){
	list.displayLL();
	double averageF = average(list);
	cout<<"The annual average of the flow is: " << averageF << " billions of cubic meter" << endl;
}

double average(const FlowList& list) {
	double av = list.averageLL();
	return av;
}

int menu(){
	int choice;
	cout <<"Please select on the following operations"<<endl;
	cout<<"1. Display flow list, and the average"<<endl;
	cout<<"2. Add data"<<endl;
	cout<<"3. Save data into the file"<<endl;
	cout<<"4. Remove data"<<endl;
	cout<<"5. Quit"<<endl;
	cout<<"Enter your choice (1, 2, 3, 4 or 5)"<<endl;
	cin>>choice;
	
	return choice;
}

int addData(FlowList& list, int year, double flow){
	int x = list.insertnew(year, flow);
	return x;
}

void saveData(FlowList& list){
	list.saveLL();
	cout<<"Data are saved into the file"<<endl;
}

void removeData(FlowList& list, int year){
	list.removeLL(year);
}


// Main function
int main(){
    displayHeader();
    pressEnter(); 
    ifstream in_stream("flow.txt");  // Open file to read
    if (!in_stream) {
        cout << "Error: Could not open file flow.txt for reading." << endl;
        exit(1);
    }
    FlowList data;  // FlowList object to store data
    int numRecords = readData(in_stream, data);  // Read data from file
    in_stream.close();  // Close file
	
	int num;
	int quit = 0;
	while(1){
		switch(menu()){
			// call display function, call pressEnter;
			case 1:
				display(data);
				pressEnter();
				break;
			case 2: // call addData function, call pressEnter;
				int newyear, newflow;
				cout<<"Please enter a year"<<endl;
				cin>>newyear;
				
				cout<<"please enter the flow"<<endl;
				cin>>newflow;
				num = addData(data, newyear, newflow);
				if (num == 0){
					numRecords += 1;
				}
				pressEnter;
				break;
			case 3: //call saveData function, call pressEnter;
				saveData(data);
				pressEnter;
				break;
			case 4:// call removeData, call presenter
				int removeYear;
				cout<<"Please enter the year that you want to remove: ";
				cin >> removeYear;
				removeData(data, removeYear);
				pressEnter;
				break;
			
			case 5:
				cout << "\nProgram terminated!\n\n";
				quit = 1;
				break;
			default:
				cout << "\nNot a valid input.\n";
				pressEnter();
		}
	if(quit == 1) break;
	}
	
	
	return 0;
}
