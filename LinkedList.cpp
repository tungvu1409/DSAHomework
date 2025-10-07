#include <iostream>

using namespace std;
struct node{
	int data;
	node* next;
};

struct LinkedList {
	node* head;
	
	LinkedList() {
		head = nullptr;
	}
	
	// chen 1 ptu vao da (do phuc tap o(1))
	void insertFirst(int x) {
		node* newNode = new node;
		newNode->data = x;
		newNode->next = head;
		head = newNode;
	}
	// chen 1 ptu vao cuoi (do phuc tap o(n) )
	void insertLast(int x) {
		node* newNode = new node;
		newNode->data = x;
		newNode->next = nullptr;
		
		if(head == nullptr) {
			head = newNode;
		}else {
			node* temp = head;
			while(temp->next != nullptr) {
				temp = temp->next;
			}
			temp->next = newNode;
		}
	}
	// chen 1 ptu vao vi tri bat ki 
	void insertAt(int k, int x){
    	if (k == 0){ 
        	insertFirst(x);
        	return;
    	}
    	node* temp = head;
    	int i = 0;
    	while (i < k - 1 && temp != nullptr) {
        	temp = temp->next;
        	i++;
    	}
    	if (temp == nullptr) {
        	cout << "Vi tri khong hop le" << endl;
        	return;
    	}
    	node* newNode = new node;
    	newNode->data = x;
    	newNode->next = temp->next;
    	temp->next = newNode;
	}
	// xoa ptu o dau (do phuc tap o(1) );
	void deleteFirst(){
		if(head == nullptr){
			return;
		}
		node* temp = head;
		head = head->next;
		delete temp;
	}
	// xoa ptu o cuoi (do phuc tap o(n))
	void deleteLast(){
		if(head == nullptr){
			return;
		}
    	if(head->next == nullptr){ 
        	delete head;
        	head = nullptr;
        	return;
    	}
    	node* temp = head;
    	while(temp->next->next != nullptr){
        	temp = temp->next;
    	}

    	delete temp->next;  
    	temp->next = nullptr; 

	}
	// xoa ptu o vi tri bat ki
	void deleteAt(int k){
    	if(head == nullptr){
			return; 
		}
    	if(k == 0){ 
        	deleteFirst();
        	return;
    	}
    	node* temp = head;
    	int i = 0;
    	while(i < k-1 && temp != nullptr){
        	temp = temp->next;
        	i++;
    	}
    	if(temp == nullptr || temp->next == nullptr){
        	cout << "Vi tri k HOP LE";
        	return;
    	}
    	node* dNode = temp->next;      
    	temp->next = dNode->next;     
    	delete dNode;                
	}

	// duyet xuoi
	void print() {
		node* temp = head;
		while(temp != nullptr) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}
	node* getNodeAt(int k){
    	node* temp = head;
    	int i = 0;
    	while(temp != nullptr && i < k){
        	temp = temp->next;	
        	i++;
    	}
    	if(temp == nullptr){
        	return nullptr;
    	}
    	return temp; 
	}
};
int main(){
	LinkedList ll;
	ll.insertFirst(10);
	ll.insertFirst(20);
	ll.insertFirst(40);
	ll.insertLast(30);
	ll.insertAt(2, 50);
	ll.deleteFirst();
	ll.deleteLast();
	ll.deleteAt(1);
	ll.print();
	node* ll1 = ll.getNodeAt(0); 
    cout << "Node thu 0 co gia tri: " << ll1->data << endl; 
    
}
