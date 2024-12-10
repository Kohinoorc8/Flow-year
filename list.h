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
	
public:
    FlowList(): head(nullptr) {}      
    ~FlowList();
	void insert(int year, double flow);

	void displayLL()const;
	double averageLL() const;
	
	int insertnew(int year, double flow);
	void saveLL();
	void removeLL(int year);
};

#endif
