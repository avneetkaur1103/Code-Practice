#include <iostream>
#include <queue>
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

int maxDepth(Node* root){
	if (!root)
		return 0;

	queue<Node*> q;
	q.push(root);

	int height = 0;

	while(1){

		int nCount = q.size();
		if(nCount == 0)
			return height;

		height++;

		while(nCount>0){
			Node* tmp = q.front();
			q.pop();

			if(tmp->left)
				q.push(tmp->left);
		
			if(tmp->right)
				q.push(tmp->right);
			nCount--;
		}
	}
	return height;
}

int main(){
	Node *root =  newNode(15); 
    root->left = newNode(10); 
    root->right = newNode(20); 
    root->left->left = newNode(8); 
    root->left->right = newNode(12); 
    root->right->left = newNode(16); 
    root->right->right = newNode(25); 

    cout<<"Depth of tree: "<< maxDepth(root);
    return 0;
}

//Complexity:O(n)