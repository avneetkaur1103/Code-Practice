#include <iostream>
#include <queue>
#include <climits>
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

bool isSorted(Node* root){
	if(!root)
		return true;

	queue<Node*> q;
	q.push(root);

	int prevMax = INT_MIN;
	int currMin, currMax;

	while(!q.empty()){
		int n = q.size();
		currMin = INT_MAX;
		currMax = INT_MIN;

		while(n>0){
			Node* tmp = q.front();
			q.pop();

			currMin = min(currMin,tmp->data);
			currMax = max(currMax, tmp->data);

			n--;

			if(tmp->left)
				q.push(tmp->left);

			if(tmp->right)
				q.push(tmp->right);
		}
		
		if(prevMax<currMin)
			prevMax = currMax;
		else
			return false;	
	}
	return true;
}

int main(){
	Node* root = newNode(1); 
    root->left = newNode(4); 
    root->left->right = newNode(6); 
    root->left->right->left = newNode(8); 
    root->left->right->right = newNode(9); 
    root->left->right->left->left = newNode(12); 
    root->left->right->right->right = newNode(10);

    if(isSorted(root))
    	cout<<"Sorted";
    else
    	cout<<"Not Sorted";

    return 0;
}

//Complexity: O(n)