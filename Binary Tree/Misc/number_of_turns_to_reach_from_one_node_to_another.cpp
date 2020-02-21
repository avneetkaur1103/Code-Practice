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

Node* findLCA(Node* root, int f, int s){
	if(!root)
		return NULL;
	if(root->data == f || root->data == s)
		return root;

	Node* left_lca = findLCA(root->left,f,s);
	Node* right_lca = findLCA(root->right,f,s);

	if(left_lca && right_lca)
		return root;

	if(!left_lca)
		return right_lca;
	else
		return left_lca;
}

bool countTurn(Node* root, int key, bool turn, int &count){
	if(root == NULL)
		return false;
	if(root->data == key)
		return true;

	if(turn){
		if(countTurn(root->left,key,turn,count))
			return true;
		if(countTurn(root->right,key,!turn,count)){
			count += 1;
			return true;
		}
	}
	else{
		if(countTurn(root->right,key,turn,count))
			return true;
		if(countTurn(root->left,key,!turn,count)){
			count += 1;
			return true;
		}
	}

	return false;
}

int NumberOFTurn(Node* root, int first, int second){
	if(!root)
		return 0;

	Node* LCA = findLCA(root, first,second);
	if(LCA == NULL)
		return -1;

	int count = 0;

	if(LCA->data != first && LCA->data != second){
		if(countTurn(LCA->right,second,false,count) || countTurn(LCA->left,second,true,count))
			;
		if(countTurn(LCA->left,first,true,count) || countTurn(LCA->right,first,false,count))
			;
		return count+1;
	}

	if(LCA->data == first){
		countTurn(LCA->right,second,false,count);
		countTurn(LCA->left,second,true,count);
		return count;
	}

	else{
		countTurn(LCA->right,first,false,count);
		countTurn(LCA->left,first,true,count);
		return count;
	}
}

int main(){
	Node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 
    root->left->left->left = newNode(8); 
    root->right->left->left = newNode(9); 
    root->right->left->right = newNode(10); 
  
    int turn = 0; 
    if ((turn = NumberOFTurn(root, 5, 10))) 
        cout << turn << endl; 
    else
        cout << "Not Possible" << endl; 
  
    return 0;
}

//Comlexity:O(n)