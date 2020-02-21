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

/*struct ListNode{
	int data;
	struct ListNode *prev,*next;
};

struct ListNode* newLNode(int data){
	struct ListNode* n = (struct ListNode*)malloc(sizeof(struct ListNode));
	n->data = data;
	n->prev = n->next = NULL;
	return n;
}*/

void buildListFromTree(struct Node* root, struct Node** head){
	if(!root)
		return;

	static Node* prev = NULL;

	buildListFromTree(root->left, head);

	if(prev == NULL){
		*head = root;
	}
	else{
		root->left = prev;
		prev->right = root;
	}
	prev = root;

	buildListFromTree(root->right, head);
}

void printList(struct Node* head){
	if(!head)
		return;

	cout<<head->data<<" ";
	head = head->right;
	printList(head);
}


int main(){
	struct Node* root = newNode(10);
	root->left        = newNode(12); 
    root->right       = newNode(15); 
    root->left->left  = newNode(25); 
    root->left->right = newNode(30); 
    root->right->left = newNode(36);

    //struct ListNode* head = NULL;
    struct Node* head = NULL;
    buildListFromTree(root, &head);

    printList(head);
    return 0;
}

//Complexity: O(n)