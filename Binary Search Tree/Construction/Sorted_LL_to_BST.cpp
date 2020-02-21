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

struct LNode{
	int data;
	struct LNode* next;
};

void push(LNode** head, int data){
	LNode* newnode = new LNode();
	newnode->data = data;
	newnode->next = (*head);
	(*head) = newnode;
}

void preOrder(Node* root){
	if(!root)
		return;

	cout<<root->data<<" ";
	preOrder(root->left);
	preOrder(root->right);
}

int countListNodes(LNode* head){
	int count = 0;
	while(head){
		head = head->next;
		count++;
	}
	return count;
}

Node* sortedListToBSTUtil(LNode** head, int n){
	if(n<=0)
		return NULL;

	Node* left = sortedListToBSTUtil(head,n/2);
	Node* root = newNode((*head)->data);
	root->left = left;
	*head = (*head)->next;
	root->right = sortedListToBSTUtil(head,n-n/2-1);
	return root;
}

Node* sortedListToBST(LNode* head){
	int n = countListNodes(head);
	return sortedListToBSTUtil(&head, n);
}

int main(){
	LNode*  head = NULL;
	push(&head, 7);  
    push(&head, 6);  
    push(&head, 5);  
    push(&head, 4);  
    push(&head, 3);  
    push(&head, 2);  
    push(&head, 1);  
  	Node *root = sortedListToBST(head);

  	preOrder(root);
  	return 0;
}

//Complexity:O(n)