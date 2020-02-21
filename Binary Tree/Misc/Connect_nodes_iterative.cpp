#include <iostream>
using namespace std;

struct Node{
	int data;
	struct Node* left, *right, *nextRight;
};

struct Node* newNode(int data){
	struct Node* n = (struct Node*)malloc(sizeof(struct Node));
	n->data = data;
	n->left = n->right = NULL;
	n->nextRight = NULL;
	return n;
}

Node* getNextRight(Node* q){
	Node* temp = q->nextRight;

	while(temp != NULL){
		if(temp->left)
			return temp->left;
		if(temp->right)
			return temp->right;
		temp = temp->nextRight;
	}

	return NULL;
}

void connectIter(Node* p){
	if(!p)
		return;
	p->nextRight = NULL;

	while(p != NULL){
		Node* q = p;

		while(q!= NULL){
			if(q->left){
				if(q->right)
					q->left->nextRight = q->right;
				else
					q->left->nextRight = getNextRight(q);
			}
			if(q->right)
				q->right->nextRight = getNextRight(q);

			q = q->nextRight;
		}

		if(p->left)
			p = p->left;
		else if(p->right)
			p = p->right;
		else
			p = getNextRight(p);
	}
}

int main(){
	Node *root = newNode(10);  
    root->left = newNode(8);  
    root->right = newNode(2);  
    root->left->left = newNode(3);  
    root->right->right     = newNode(90);  
  
    connectIter(root);  
  
    cout << "Following are populated nextRight pointers in the tree"
        " (-1 is printed if there is no nextRight) \n";  
    cout << "nextRight of " << root->data << " is "
        << (root->nextRight? root->nextRight->data: -1) <<endl;  
    cout << "nextRight of " << root->left->data << " is "
        << (root->left->nextRight? root->left->nextRight->data: -1) << endl; 
    cout << "nextRight of " << root->right->data << " is "
        << (root->right->nextRight? root->right->nextRight->data: -1) << endl; 
    cout << "nextRight of " << root->left->left->data<< " is "
        << (root->left->left->nextRight? root->left->left->nextRight->data: -1) << endl; 
    cout << "nextRight of " << root->right->right->data << " is "
        << (root->right->right->nextRight? root->right->right->nextRight->data: -1) << endl; 
    return 0; 
}

//complexity: O(n)

//Read Recursive too; similar implementation