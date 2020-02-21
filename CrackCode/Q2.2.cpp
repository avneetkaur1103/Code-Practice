#include <iostream>

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

int NthElementFromLast(Node* root, int n){
	Node* fast = root, *slow = root;
	int count = 0;

	while(fast->next != NULL){
		if(count == n)
			break;
		else{
			count++;
		fast = fast->next;
		}	
	}
	
	while(fast != NULL){
		slow = slow->next;
		fast = fast->next;
	}

	return slow->data;

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
	root->next->next = newNode(13);
	root->next->next->next = newNode(14);
	root->next->next->next->next = newNode(15);
	root->next->next->next->next->next = newNode(16);
	root->next->next->next->next->next->next = newNode(17);
	int n = 2;
	printLL(root);
	cout<<NthElementFromLast(root,n);
	//printLL(root);
	return 0;
}

//COmplexity: O(n)