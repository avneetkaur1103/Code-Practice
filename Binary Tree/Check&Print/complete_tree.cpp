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

bool isCompleteBinaryTree(Node* root){
	if(!root)
		return true;
	queue<Node*> q;
	q.push(root);

	bool flag = false;

	while(!q.empty()){
		Node* tmp = q.front();
		q.pop();

		if(!tmp->left && !tmp->right)
			continue;

		if(tmp->left){
			if(flag == true)
				return false;
			q.push(tmp->left);
		}
		else
			flag = true;

		if(tmp->right){
			if(flag == true)
				return false;
			q.push(tmp->right);
		}
		else
			flag = true;
	}
	return true;
}

int main(){
	Node *root = newNode(1);  
    root->left     = newNode(2);  
    root->right = newNode(3);  
    root->left->left = newNode(4);  
    root->left->right = newNode(5);  
    root->right->right = newNode(6);
    //root->right->left = newNode(6); 
     
    if(isCompleteBinaryTree(root))
    	cout<<"True";
    else
    	cout<<"False";

    return 0;
}

//complexity: O(n)