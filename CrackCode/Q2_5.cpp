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

Node* sumList(Node* a, Node* b){
	Node* temp = NULL, *new_head = NULL;
	int carry = 0, val = 0;

	while(a != NULL || b!= NULL || carry != 0){
		val = carry;
		//cout<<"carry: "<<carry<<endl;
		if(a != NULL)
			val += a->data;
		if(b!= NULL)
			val += b->data;


		carry = val/10;
		val %= 10;
		//cout<<"val: "<<val<<endl;
		if(new_head == NULL){
			temp = newNode(val);
			new_head = temp;
			//res = res->next;
			//cout<<"In first if"<<endl;
		}
		else{
			
			Node* temp1 = newNode(val);
			temp->next = temp1;
			temp = temp->next;
			//res = res->next;
			//cout<<"In else"<<endl;
		}
		if(a!= NULL && b!= NULL){
			a = a->next;
			b = b->next;
		}
	}
	//res->next = NULL;
	return new_head;
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
	
	struct Node *root1 = newNode(2);
	root1->next = newNode(9);
	root1->next->next = newNode(5);

	//printLL(root);
	printLL(sumList(root,root1));
	//printLL(root);
	return 0;
}

//COmplexity: O(n)