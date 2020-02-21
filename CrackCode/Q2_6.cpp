#include <iostream>
#include <stack>

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

bool palindrome(Node* root){
	stack<int> s;
	s.push(root->data);

	Node* curr = root->next;
	
	while(curr != NULL){
		s.push(curr->data);
		curr = curr->next;
	}

	while(!s.empty()){
		int temp = s.top();
		s.pop();
		if(temp != root->data)
			return false;
		else
			root = root->next;
	}

	return true;
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
	root->next->next->next = newNode(1);
	root->next->next->next->next = newNode(6);

	printLL(root);
	palindrome(root)?cout<<"Yes":cout<<"No";
	//printLL(root);
	return 0;
}

//COmplexity: O(n)