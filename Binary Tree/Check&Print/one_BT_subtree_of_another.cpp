#include <iostream>
#include <queue>

using namespace std;

#define MAX 100

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

void Inorder(Node* root, char arr[], int &i){
	if(!root){
		arr[i++] = '$';
		return;
	}

	Inorder(root->left,arr,i);
	arr[i++] = root->data;
	Inorder(root->right,arr,i);
}

void Preorder(Node* root, char arr[], int &i){
	if(!root){
		arr[i++] = '$';
		return;
	}

	arr[i++] = root->data;
	Preorder(root->left,arr,i);
	Preorder(root->right,arr,i);
}

bool isSubtree(Node* T, Node* S){
	if(T == NULL)
		return false;
	if(S == NULL)
		return true;

	char inT[MAX], inS[MAX], preT[MAX], preS[MAX];
	int m=0,n=0;

	Inorder(T,inT,m);
	Inorder(S,inS,n);

	inT[m] = '\0';
	inS[n] = '\0';

	if(strstr(inT,inS) == NULL)
		return false;

	m=0,n=0;

	Preorder(T,preT,m);
	Preorder(S,preS,n);

	preT[m] = '\0';
	preS[n] = '\0';

	return (strstr(preT,preS) != NULL);
}

int main(){
	Node* T = newNode('a'); 
    T->left = newNode('b'); 
    T->right = newNode('d'); 
    T->left->left = newNode('c'); 
    T->right->right = newNode('e'); 
  
    Node* S = newNode('a'); 
    S->left = newNode('b'); 
    S->left->left = newNode('c'); 
    S->right = newNode('d'); 
  
    if (isSubtree(T, S))
    	cout<<"Yes";
    else
    	cout<<"No";

    return 0;
}

//complexity: O(n)