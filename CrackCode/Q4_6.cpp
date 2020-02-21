#include <iostream>
using namespace std;

struct Node{
	int data;
	struct Node* left, *right, *parent;
};

Node* createNode(int d){
	Node* n = new Node;
	n->data = d;
	n->left = n->right = n->parent = NULL;
	return n;
}

Node* push(Node* head, int _data){
	if(head == NULL)
		head = createNode(_data);
	else{


		if (head->data >= _data){
			Node* temp = push(head->left,_data);
			head->left = temp;
			temp->parent = head;
		}
		else{
			Node* temp = push(head->right,_data);
			head->right = temp;
			temp->parent = head;
		}
	}
	return head;
}

Node* minValLeft(Node* temp){
	
	while(temp->left != NULL){
		temp = temp->left;
	}
	return temp;
}

Node* inOrderSucc(Node* node){
	if(node->right!= NULL){
		return minValLeft(node->right);
	}
	Node* p = node->parent;
	while(p!= NULL && node == p->right){
		node=p;
		p = p->parent;
	}
	return p;
}

int main(){
	Node* head = NULL;
	head = push(head,20);
	head = push(head,8);
	head = push(head,22);
	head = push(head,4);
	head = push(head,12);
	head = push(head,10);
	head = push(head,14);
	//head = push(head,12);

	Node* temp = head->left->right->right;
	Node* succ = inOrderSucc(temp);
	if(succ)
		cout<<succ->data<<endl;
	else
		cout<<"No successor"<<endl;
	return 0;
}