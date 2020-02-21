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

Node* insert(Node* root, int key){
	if(!root)
		return newNode(key);

	if(key<root->data)
		root->left = insert(root->left,key);
	if(key>root->data)
		root->right = insert(root->right,key);

	return root;
}

int countNodes(Node* root){
	if(!root)
		return 0;

	Node* curr = root, *pre;
	int count = 0;

	while(curr != NULL){
		if(curr->left == NULL){
			count++;
			curr = curr->right;
		}
		else{
			pre = curr->left;

			while(pre->right != NULL && pre->right != curr)
				pre = pre->right;

			if(pre->right == NULL){
				pre->right = curr;
				curr = curr->left;
			}
			else{
				pre->right = NULL;
				count++;
				curr = curr->right;
			}
		}
	}
	return count;
}

int findMedian(Node* root){
	if(!root)
		return 0;

	Node* curr = root;
	int count = countNodes(root);
	int currCount = 0;
	Node* prev = NULL, *pre;

	while(curr != NULL){
		if(curr->left == NULL){
			currCount++;
			if((count % 2 != 0) && (currCount == (count+1)/2))
				return curr->data;
			else if((count%2 == 0) && (currCount == (count/2)+1))
				return (curr->data + prev->data)/2;

			prev = curr;
			curr = curr->right;
		}
		else{
			pre = curr->left;

			while(pre->right != NULL && pre->right != curr)
				pre = pre->right;

			if(pre->right == NULL){
				pre->right = curr;
				curr = curr->left;
			}
			else{
				pre->right = NULL;
				currCount++;
				prev = pre;
				if((count % 2 != 0) && (currCount == (count+1)/2))
					return curr->data;
				else if((count%2 == 0) && (currCount == (count/2)+1))
					return (curr->data + prev->data)/2;
				prev = curr;
				curr = curr->right;
			}
		}
	}
	cout<<countNodes(root);
	return 0;
}

int main(){
	struct Node* root = NULL;
	root = insert(root, 50); 
    root = insert(root, 30); 
    root = insert(root, 20); 
    root = insert(root, 40); 
    root = insert(root, 70); 
    root = insert(root, 60); 
    root = insert(root, 80); 
  
    cout << "Median of BST is "<< findMedian(root); 
    return 0; 
}

//Time ComplexitY:O(n)
//Space Complexity: O(1)