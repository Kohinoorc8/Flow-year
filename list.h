//Lab 9, part 2

#ifndef LIST_H
#define LIST_H

struct ListItem {
int year;
double flow;
};

struct Node {
ListItem item;
Node *next;
};

class FlowList {
private:
    Node* head;
	//void destroy(); 
	
public:
    FlowList(): head(nullptr) {}      
    ~FlowList();
	void insert(int year, double flow);
	
};

#endif