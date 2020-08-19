#include <iostream>
using namespace std;

class Node{
	int data;
	Node* next;
};

Node* newNode(int d){
	Node* n = new Node();
	n->data = d;
	n->next = NULL;
	return n;
}

Node* XOR(Node* a, Node *b){
	return ((Node*) ((uintptr_t)(a) ^ (uintptr_t)(b)));
}

void convert(Node *head){
	Node *curr = head;
	Node *prev = NULL;
	Node *next = NULL;
	while(curr){
		next = curr->next;
		curr->next = XOR(prev,next);
		prev = curr;
		curr = next;
	}
}

void print(Node *head){
	Node *curr = head;
	Node *prev = NULL;
	while(curr){
		cout<<curr->data<<" ";
		Node *temp = curr;
		curr = XOR(prev,curr->next);
		prev = temp;
	}
	
}

int main() {
	Node* head = newNode(1); 
    head->next = newNode(2); 
    head->next->next = newNode(3); 
    head->next->next->next = newNode(4);
    convert(head);
    print(head);
	return 0;
}
