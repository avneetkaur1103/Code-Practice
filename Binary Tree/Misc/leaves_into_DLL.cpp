#include <iostream>
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

Node* extractLeafList(Node* root, Node** head){
	if(root == NULL)
		return NULL;
	if(root->left == NULL && root->right == NULL){
		root->right = *head;
		if(*head)
			(*head)->left = root;
		(*head) = root;
		return NULL;
	}

	root->right = extractLeafList(root->right, head);
	root->left = extractLeafList(root->left, head);
	return root;
}

void printList(Node* head){
	while(head){
		cout<<head->data<<" ";
		head = head->right;
	}
}

void inOrder(Node* root){
	if(!root)
		return;

	inOrder(root->left);
	cout<<root->data<<" ";
	inOrder(root->right);
}

int main(){
	Node *head = NULL;  
    Node *root = newNode(1);  
    root->left = newNode(2);  
    root->right = newNode(3);  
    root->left->left = newNode(4);  
    root->left->right = newNode(5);  
    root->right->right = newNode(6);  
    root->left->left->left = newNode(7);  
    root->left->left->right = newNode(8);  
    root->right->right->left = newNode(9);  
    root->right->right->right = newNode(10);

    root = extractLeafList(root, &head);
    printList(head);
    cout<<endl;
    inOrder(root);
    return 0;
}

//Complexity:O(n)