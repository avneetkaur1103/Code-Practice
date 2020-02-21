#include <iostream>
#include <cfloat>

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

int Height_size(struct Node* root, int &size){

	if(!root)
		return 0;

	int lh = Height_size(root->left, size);
	int rh = Height_size(root->right, size);
	size++;
	return (lh>rh?lh+1:rh+1);
}

int main(){
	struct Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	int size = 0;
	int h = Height_size(root, size);
	cout<<"Height: "<<h<< " and size: "<<size<<endl;
	float d = size/h;
	cout<<"Density: "<<d;
	return 0;
}

//COMPLEXITY: O(n)