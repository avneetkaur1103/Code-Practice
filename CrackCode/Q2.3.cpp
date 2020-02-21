#include <iostream>
#include <unordered_set>

using namespace std;

struct Node{
	int data;
	struct Node *next;
};

struct Node* newNode(int d){
	Node *n = new Node;
	n->data = d;
	n->next = NULL;
	return n;
}

void removeMiddleElement(Node* node){
	if(node == NULL || node->next == NULL)
		return;
	swap(node->data,node->next->data);
	Node* temp = node->next;
	node->next = temp->next;
	free(temp);
	return;
}

void printLL(struct Node* head){
	if(head == NULL)
		return;

	while(head != NULL){
		cout<<head->data<<" ";
		head = head->next;
	}
	cout<<endl;
}

int main(){
	struct Node *root = newNode(10);
	root->next = newNode(12);
	root->next->next = newNode(11);
	root->next->next->next = newNode(11);
	root->next->next->next->next = newNode(12);
	root->next->next->next->next->next = newNode(11);
	root->next->next->next->next->next->next = newNode(10);
	removeMiddleElement(root->next->next->next);
	return 0;
}

//Complexity: 