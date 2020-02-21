#include <iostream>
#include <vector>
using namespace std;

struct Node{
	int data;
	struct Node* left, *right;
};

struct Node* newNode(int data){
	struct Node* n = (struct Node*)malloc(sizeof(struct Node));
	n->data = data;
	n->left = n->right = NULL;
	return n;
}

void inOrder(struct Node* root, vector<int> &v){
	if(!root)
		return;
	inOrder(root->left, v);
	v.push_back(root->data);
	inOrder(root->right, v);
}

Node* cllFomBinaryTree(struct Node* root){
	if(!root)
		return NULL;

	vector<int> v;
	inOrder(root,v);

	struct Node* head = newNode(v[0]);
	struct Node* curr = head;
	struct Node* prev = NULL;

	for(int i =1;i<v.size();i++){
		prev = curr;
		curr->right = newNode(v[i]);
		curr = curr->right;
		curr->left = prev;
	}

	curr->right = head;
	head->left = curr;

	return head;
}

void printlist(Node* head){
	if(!head)
		return;
	Node* tmp = head;
	do{
		cout<<tmp->data<<" ";
		tmp = tmp->right;
	}while(tmp != head);
}

int main(){
	struct Node* root = newNode(10); 
    root->left = newNode(12); 
    root->right = newNode(15); 
    root->left->left = newNode(25); 
    root->left->right = newNode(30); 
    root->right->left = newNode(36);

    Node* head = cllFomBinaryTree(root);

    printlist(head);
    return 0;
}

//Complexity: O(n)