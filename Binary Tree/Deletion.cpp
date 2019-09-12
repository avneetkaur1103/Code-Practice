#include <iostream>
#include <queue>
using namespace std;

struct Node{
	int data;
	struct Node *left;
	struct Node *right;
};

struct Node* newNode(int data){
	struct Node* n = (struct Node*) malloc(sizeof(struct Node));
	n->data = data;
	n->left = n->right = NULL;
	return n;
}
void DelNode(struct Node* root, struct Node* delnode){
	struct Node* temp;

	queue<struct Node*> q;
	q.push(root);

	while(!q.empty()){
		temp = q.front();
		q.pop();
		if(temp == delnode){
			temp = NULL;
			free(delnode);
			return;
		}

		if(temp->right){
			if(temp->right == delnode){
				temp->right = NULL;
				free(delnode);
				return;
			}
			else
				q.push(temp->right);
		}

		if(temp->left){
			if(temp->left == delnode){
				temp->left = NULL;
				free(delnode);
				return;
			}
			else
				q.push(temp->left);
		}

	}
}

void inorder(struct Node* root){
	if(root == NULL)
		return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

struct Node* Deletion(struct Node* root, int key){
	if (root == NULL)
		return NULL;
	if (root->left == NULL && root->right == NULL){
		if(root->data == key)
			return NULL;
		else
			return root;
	}

	struct Node* temp;
	struct Node* key_node = NULL;
	queue<struct Node*> q;
	q.push(root);
	while(!q.empty()){
		temp = q.front();
		q.pop();

		if(temp->data == key)
			key_node = temp;

		if(temp->left)
			q.push(temp->left);

		if(temp->right)
			q.push(temp->right);
	}

	if(key_node != NULL){
		int x = temp->data;
		DelNode(root, temp);
		key_node->data = x;
	}
	return root;
}

int main()
{
	struct Node* root = newNode(10);
	root->left = newNode(11); 
    root->left->left = newNode(7); 
	
    root->left->right = newNode(12); 
    root->right = newNode(9); 
    root->right->left = newNode(15); 
    root->right->right = newNode(8); 


    cout<<"Inorder traversal before: ";
    inorder(root);
    cout<<endl;
    int key = 11; 
    root = Deletion(root, key);

    cout<<"Inorder traversal after: ";
    inorder(root);
    cout<<endl;
	return 0;
}

//Complexity: 