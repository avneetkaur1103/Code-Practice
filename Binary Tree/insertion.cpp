#include <iostream>
#include <queue>
using namespace std;

struct Node{
	int data;
	struct Node *left;
	struct Node *right;
};

struct Node* newNode(int data){
	struct Node* n = (struct Node*)malloc(sizeof(struct Node));
	n->data = data;
	n->left = n->right = NULL;
	return n;
}

void inorder(struct Node* n){
	if(n==NULL)
		return;
	inorder(n->left);
	cout<<n->data<<" ";
	inorder(n->right);
}

void insert(struct Node *temp, int data){
	queue<struct Node *> q;
	q.push(temp);

	while(!q.empty()){
		struct Node *n = q.front();
		q.pop();

		if(!n->left){
			n->left = newNode(data);
			break;
		}
		else
			q.push(n->left);

		if(!n->right){
			n->right = newNode(data);
			break;
		}
		else
			q.push(n->right);
	}
}

int main(){
	struct Node* root = newNode(10);
	root->left = newNode(11); 
    root->left->left = newNode(7); 
    root->right = newNode(9); 
    root->right->left = newNode(15); 
    root->right->right = newNode(8); 

    cout<<"Inorder before: ";
    inorder(root);
    cout<<endl;
    insert(root,12);

    cout<<"Inorder After: ";
    inorder(root);
	return 0;
}