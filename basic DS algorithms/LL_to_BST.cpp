#include <iostream>
using namespace std;

struct Lnode{
	int data;
	struct Lnode *next;
};

struct Bnode{
	int data;
	struct Bnode *left, *right;
};

struct Bnode* new_Bnode(int data){
	Bnode *bn = new Bnode();
	bn->data = data;
	bn->left = NULL;
	bn->right = NULL;
	return (bn);
}

int countLLnodes(struct Lnode *head){
	struct Lnode *curr = head;
	int count = 0;
	while (curr != NULL){
		curr = curr->next;
		count ++;
	}
	return count;
}

struct Bnode* LLtoBSTrecr(struct Lnode** head, int n){
	if (n <= 0 )
		return NULL;
	
	Bnode *left1 = LLtoBSTrecr(head, n/2);
	Bnode *root = new_Bnode((*head)->data);
	root->left = left1;
	(*head) = (*head)->next;
	//Bnode *right1 = LLtoBSTrecr(head, n - n/2 - 1);
	root->right = LLtoBSTrecr(head, n - n/2 - 1);
	return root;
//return left1;
}


struct Bnode* LLtoBST(struct Lnode *head){
		int n = countLLnodes(head);
		return LLtoBSTrecr(&head, n);
}

void InsertInLL(struct Lnode** head, int key){
	struct Lnode* new_node = new Lnode();
	new_node->data = key;
	new_node->next = *head;
	*head = new_node;
}

void PrintLL(struct Lnode *head){
	struct Lnode *curr= head;
	while(curr!= NULL){
		cout<<curr->data << " " ;
		curr = curr->next;
	}
}

void PreOrder(struct Bnode* root){
	if (root == NULL)
		return;
		
	cout<<root->data << " ";
	PreOrder(root->left);
	PreOrder(root->right);
}

int main() {
	struct Lnode *head = NULL;
	//InsertInLL(&head,8);
	InsertInLL(&head,7);
	InsertInLL(&head,6);
	InsertInLL(&head,5);
	InsertInLL(&head,4);
	InsertInLL(&head,3);
	InsertInLL(&head,2);
	InsertInLL(&head,1);
	PrintLL(head);
	printf("\n");
	struct Bnode *root = LLtoBST(head);
	PreOrder(root);
	return 0;
}

Complexity: O(n)