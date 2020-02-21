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

int sumOfLeftLeaves(Node* root, int &sum, bool isLeft = 0){
	if(!root)
		return 0;

	if(!root->left && !root->right && isLeft)
		sum += root->data;

	sumOfLeftLeaves(root->left,sum,1);
	sumOfLeftLeaves(root->right,sum,0);

	return sum;
}

int sumOfRightLeaves(Node* root, int &sum, bool isRight = 0){
	if(!root)
		return 0;

	if(!root->left && !root->right && isRight)
		sum += root->data;

	sumOfRightLeaves(root->left,sum,0);
	sumOfRightLeaves(root->right,sum,1);

	return sum;
}

int main(){
	struct Node *root         = newNode(20); 
    root->left                = newNode(9); 
    root->right               = newNode(49); 
    root->right->left         = newNode(23); 
    root->right->right        = newNode(52); 
    root->right->right->left  = newNode(50); 
    root->left->left          = newNode(5); 
    root->left->right         = newNode(12); 
    root->left->right->right  = newNode(12);

    int sum = 0;
    cout<<"Left Leaves sum: "<<sumOfLeftLeaves(root, sum)<<endl;

    Node *root1 = newNode(1); 
    root1->left = newNode(2); 
    root1->left->left = newNode(4); 
    root1->left->right = newNode(5); 
    root1->left->left->right = newNode(2); 
    root1->right = newNode(3); 
    root1->right->right = newNode(8); 
    root1->right->right->left = newNode(6); 
    root1->right->right->right = newNode(7); 

    int sum1=0;
    cout<<"Right Leaves sum: "<<sumOfRightLeaves(root1, sum1);

    return 0;
}

//complexity: O(n)