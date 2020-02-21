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

int KSmallestUsingMorris(Node* root, int k){
	Node* curr = root;
	int ksmall = INT_MIN;
	int count = 0;

	while(curr != NULL){
		if(curr->left == NULL){
			count++;
			if(count == k)
				ksmall = curr->data;
			curr = curr->right;
		}
		else{
			Node* pre = curr->left;

			while(pre->right != NULL && pre->right != curr)
				pre = pre->right;

			if(pre->right == NULL){
				pre->right = curr;
				curr = curr->left;
			}
			else{
				pre->right = NULL;
				count++;
				if(count == k)
					ksmall = curr->data;
				curr = curr->right;
			}
		}
	}
	return ksmall;
}

int main(){
	  Node *root = NULL; 
    root = insert(root, 50); 
    insert(root, 30); 
    insert(root, 20); 
    insert(root, 40); 
    insert(root, 70); 
    insert(root, 60); 
    insert(root, 80); 
  
    for (int k=1; k<=7; k++) 
       cout << KSmallestUsingMorris(root, k) << " "; 
  
    return 0;
}

//Time ComplexitY:O(n)
//Space Complexity: O(1)