#include <iostream>
#include <queue>

using namespace std;

struct listNode{
	int data;
	struct listNode* next;
};

struct treeNode{
	int data;
	struct treeNode* left, *right;
};

struct treeNode* newNode(int data){
	struct treeNode* n = (struct treeNode*)malloc(sizeof(struct treeNode));
	n->data = data;
	n->left = n->right = NULL;
	return n;
}

void pushTOList(struct listNode** head, int data){
	struct listNode* ll = (struct listNode*)malloc(sizeof(struct listNode));
	ll->data = data;
	ll->next = (*head);
	(*head) = ll;
}

void construct_list_to_tree(struct listNode* head, struct treeNode* &root){
	if(head == NULL){
		root = NULL;
		return;
	}
	struct treeNode *troot = newNode(head->data);
	queue<treeNode*> q;
	q.push(troot);

	head = head->next;

	while(head){
		struct treeNode* parent = q.front();
		q.pop();

		
		struct treeNode* lc = newNode(head->data);
		struct treeNode* rc = NULL;
		q.push(lc);
		head = head->next;

		if(head){
			rc = newNode(head->data);
			q.push(rc);
			head = head->next;
		}

		parent->left = lc;
		parent->right = rc;
	}
	root = troot;
	//cout<<"done";
}

void Inorder(struct treeNode* root){
	if(!root)
		return;

	Inorder(root->left);
	cout<<root->data<<" ";
	Inorder(root->right);
}



int main(){
	struct listNode* head = NULL;
	pushTOList(&head,36);
	pushTOList(&head,30);
	pushTOList(&head,25);
	pushTOList(&head,15);
	pushTOList(&head,12);
	pushTOList(&head,10);
	
	cout<<endl;
	struct treeNode* root;
	construct_list_to_tree(head, root);
	Inorder(root);
	return 0;
}

//Complexity: O(n)