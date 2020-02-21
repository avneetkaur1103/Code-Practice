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

int detectLoop(Node* root){
	Node *fast= root, *slow = root;

	while(fast && slow && fast->next != NULL){
		fast = fast->next->next;
		slow = slow->next;
		if(fast == slow){
			cout<<"Loop detected."<<endl;
			return slow->data;
		}
	}

	return -1;
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
	struct Node *root = newNode(6);
	root->next = newNode(1);
	root->next->next = newNode(7);
	root->next->next->next = newNode(5);
	root->next->next->next->next = newNode(9);
	root->next->next->next->next->next = root->next->next;

	//printLL(root);
	cout<<detectLoop(root);
	//printLL(root);
	return 0;
}

//COmplexity: O(n)