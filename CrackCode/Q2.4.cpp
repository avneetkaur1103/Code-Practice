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

Node* PartitionLinkedList(Node* root, int x){
	Node* beforeStart = NULL;
	Node* beforeEnd = NULL;
	Node* afterStart = NULL;
	Node* afterEnd = NULL;

	Node* curr = root;

	while(curr != NULL){
		//Node* temp = curr;
		if(curr->data < x){
			if(beforeStart == NULL){
				beforeStart = curr;
				beforeEnd = beforeStart;
			}
			else{
				beforeEnd->next = curr;
				beforeEnd = beforeEnd->next;
			}
		}
		else{
			if(afterStart == NULL){
				afterStart = curr;
				afterEnd = afterStart;
			}
			else{
				afterEnd->next = curr;
				afterEnd = afterEnd->next;
			}
		}
		curr = curr->next;
	}

	afterEnd->next = NULL;

	if(beforeStart== NULL)
		return afterStart;

	beforeEnd->next = afterStart;
	return beforeStart;
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
	struct Node *root = newNode(3);
	root->next = newNode(5);
	root->next->next = newNode(8);
	root->next->next->next = newNode(5);
	root->next->next->next->next = newNode(10);
	root->next->next->next->next->next = newNode(2);
	root->next->next->next->next->next->next = newNode(1);
	int x = 5;
	printLL(root);
	PartitionLinkedList(root,x);
	printLL(root);
	return 0;
}

//COmplexity: O(n)