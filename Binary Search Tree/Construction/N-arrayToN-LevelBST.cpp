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

Node* convertToBST(int arr[], int n){
	Node* root = newNode(arr[0]);
	Node* temp = root;
	for (int i=1;i<n;i++){
		if(arr[i]<temp->data){
			temp->left = newNode(arr[i]);
			temp = temp->left;
		}
		else{
			temp->right = newNode(arr[i]);
			temp = temp->right;
		}
	}
	return root;
}

bool isBST(Node* root, int max,int min){
	if(root==NULL)
		return true;

	if(root->data <min || root->data > max)
		return false;

	return (isBST(root->left,root->data - 1, min) && isBST(root->right, max,root->data + 1));

}

int main(){
	int arr[] = { 512, 330, 78, 11, 8}; 
	//int arr[] = {100, 200, 90, 250,100};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node* root = NULL;
    root = convertToBST(arr,n);
    isBST(root,INT_MAX,INT_MIN) ? cout<<"Yes" : cout<<"No";
    return 0;
}