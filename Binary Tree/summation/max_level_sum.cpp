#include <iostream>
#include <queue>
using namespace std;

int max_depth, sum;

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

int maxLevelSum(Node* root){
	if (!root)
		return 0;

	queue<Node*> q;
	q.push(root);

	int res = root->data;

	while(!q.empty()){
		int sum =0;
		int n = q.size();

		while(n){
			Node* curr = q.front();
			q.pop();

			sum += curr->data;

			if(curr->left)
				q.push(curr->left);

			if(curr->right)
				q.push(curr->right);

			n--;
		}
		
		res = max(res,sum);
	}

	return res;
}


int main() 
{ 
    struct Node *root = newNode(1); 
    root->left        = newNode(2); 
    root->right       = newNode(3); 
    root->left->left  = newNode(4); 
    root->left->right = newNode(5); 
    root->right->right = newNode(8); 
    root->right->right->left  = newNode(6); 
    root->right->right->right  = newNode(7);
    cout<<maxLevelSum(root);
    return 0;
}

//complexity: O(n)