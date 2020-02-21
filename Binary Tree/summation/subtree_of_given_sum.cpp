#include <iostream>
using namespace std;

struct Node{
	int data;
	struct Node* left, *right;
};

struct Node* newnode(int data){
	struct Node* n = (struct Node*)malloc(sizeof(struct Node));
	n->data = data;
	n->left = n->right = NULL;
	return n;
}

int sumSubtreeUtil(Node* root, bool &flag, int sum){
	if (!root){
		if(sum == 0)
			flag = 1;
		return 0;
	}

	int curr_sum = root->data + sumSubtreeUtil(root->left,flag,sum) + sumSubtreeUtil(root->right,flag,sum);

	if(sum == curr_sum)
		flag = 1;

	return curr_sum;
	
}

bool sumSubtree(Node* root,int sum){
	bool flag = 0;
	sumSubtreeUtil(root,flag,sum);
	return flag;
}

int main(){
	struct Node *root = newnode(8); 
    root->left    = newnode(5); 
    root->right   = newnode(4); 
    root->left->left = newnode(9); 
    root->left->right = newnode(7); 
    root->left->right->left = newnode(1); 
    root->left->right->right = newnode(12); 
    root->left->right->right->right = newnode(2); 
    root->right->right = newnode(11); 
    root->right->right->left = newnode(3); 
    int sum = 22; 
  
    if (sumSubtree(root, sum)) 
        cout << "Yes"; 
    else
        cout << "No"; 
    return 0; 
}

//Complexity: O(n)