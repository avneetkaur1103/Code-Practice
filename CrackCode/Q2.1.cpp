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

void removeDuplicates(Node* root){
	unordered_set<int> s;

	Node* curr = root;
	Node* prev = NULL;

	while(curr != NULL){
		if(s.find(curr->data) != s.end()){
			prev->next = curr->next;
			delete(curr);
		}
		else{
			s.insert(curr->data);
			prev = curr;
		}
		curr = prev->next;
	}
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
	printLL(root);
	removeDuplicates(root);
	printLL(root);
	return 0;
}

//COmplexity: O(n)