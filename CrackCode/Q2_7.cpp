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

int getLength(Node* root){
	if(root == NULL)
		return 0;
	else 
		return 1+getLength(root->next);
}

int detectIntersectionUtil(int d, Node* root, Node* root1){
	int count = 0;
	while(count!= d && root != NULL){
		root = root->next;
		count++;
	}

	while(root!=NULL && root1 != NULL){
		if(root == root1){
			cout<<"Intersection found"<<endl;
			return root->data;
		}
		else{
			root = root->next;
			root1 = root1->next;
		}
	}

}

int detectIntersection(Node* root,Node* root1){
	int l1 = getLength(root);
	int l2 = getLength(root1);

	int d=0;

	if(l1>l2){
		d = l1-l2;
		return detectIntersectionUtil(d,root,root1);
	}
	else{
		d = l2-l1;
		return detectIntersectionUtil(d,root1,root);
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
	struct Node* root1 = newNode(10);
	Node* temp = newNode(5);
	root1->next = temp;
	root->next->next->next = temp;
	root->next->next->next->next = newNode(9);
	
	//printLL(root);
	cout<<detectIntersection(root,root1);
	//printLL(root);
	return 0;
}

//COmplexity: O(n)