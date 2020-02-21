#include <iostream>
using namespace std;

struct Node{
	int data;
	struct Node* left, *right;
};

struct Node* getNode(int data){
	struct Node* n = (struct Node*)malloc(sizeof(struct Node));
	n->data = data;
	n->left = n->right = NULL;
	return n;
}

int sumSubtreeUtil(Node* root, int &num, int sum){
	if (!root){
		if(sum == 0)
			num = 1;
		return 0;
	}

	int curr_sum = root->data + sumSubtreeUtil(root->left,num,sum) + sumSubtreeUtil(root->right,num,sum);

	if(sum == curr_sum)
		num++;

	return curr_sum;
	
}

int sumSubtree(Node* root,int sum){
	int num = 0;
	sumSubtreeUtil(root,num,sum);
	return num;
}

int main(){
	struct Node* root = getNode(5); 
    root->left = getNode(-10); 
    root->right = getNode(3); 
    root->left->left = getNode(9); 
    root->left->right = getNode(8); 
    root->right->left = getNode(-4); 
    root->right->right = getNode(7);
    int sum = 7; 
  
    cout<<sumSubtree(root, sum);
    return 0; 
}

//Complexity: O(n)