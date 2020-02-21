#include <iostream>
#include <string>

using namespace std;

struct Node{
	int data;
	struct Node* left, *right, *nextRight;
};

struct Node* newNode(int data){
	struct Node* n = (struct Node*)malloc(sizeof(struct Node));
	n->data = data;
	n->left = n->right = NULL;
	n->nextRight = NULL;
	return n;
}

int largestSubtreeUtil(Node* root, Node* &maxNode, string &str,int &maxSize){
	if(!root)
		return 0;

	string left,right;
	
	int lsize = largestSubtreeUtil(root->left,maxNode,left,maxSize);
	int rsize = largestSubtreeUtil(root->right,maxNode,right,maxSize);

	int size = lsize + rsize + 1;

	if(left.compare(right) == 0){
		if(size > maxSize){
			maxSize = size;
			maxNode = root;
		}
	}

	str.append("|").append(left).append("|");
	str.append("|").append(to_string(root->data)).append("|");
	str.append("|").append(right).append("|");

	return size;
}

int largestSubtree(Node* root, Node* &maxNode){
	int maxSize = 0;
	string str = "";
	largestSubtreeUtil(root,maxNode,str,maxSize);
	return maxSize;
}

int main(){
	Node* root = newNode(50); 
    root->left = newNode(10); 
    root->right = newNode(60); 
    root->left->left = newNode(5); 
    root->left->right = newNode(20); 
    root->right->left = newNode(70); 
    root->right->left->left = newNode(65); 
    root->right->left->right = newNode(80); 
    root->right->right = newNode(70); 
    root->right->right->left = newNode(65); 
    root->right->right->right = newNode(80);

    Node* maxNode = NULL;
    int maxSize = largestSubtree(root, maxNode);

    cout<<"Size: "<<maxSize;
    cout<<" at node: "<<maxNode->data<<endl;
    return 0;
}

//Cest Case Complexity:O(n) ; Worst Case: O(n^2)