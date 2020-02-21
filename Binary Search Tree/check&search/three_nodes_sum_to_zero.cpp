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

void convertBSTtoDLL(Node* root, Node** head, Node**tail){
	if(!root)
		return;
	if(root->left)
		convertBSTtoDLL(root->left,head,tail);

	root->left = *tail;
	if(*tail)
		(*tail)->right = root;
	else
		(*head) = root;

	(*tail) = root;
	if(root->right)
		convertBSTtoDLL(root->right,head,tail);
}

bool isPresentInDLL(Node* head, Node* tail, int negSum){

	while(head != tail){
		int curr = head->data + tail->data;
		if(curr == negSum)
			return true;

		else if(curr > negSum)
			tail = tail->left;
		else
			head = head->right;
	}
	return false;
}

bool isTripletPresent(Node* root){
	if(!root)
		return false;

	Node* head = NULL, *tail = NULL;
	convertBSTtoDLL(root,&head,&tail);

	while(head->right != tail){
		if(isPresentInDLL(head->right,tail,-1*head->data))
			return true;
		else
			head = head->right;
	}
	return false;
}

int main(){
	Node* root = NULL;  
    root = insert(root, 6);  
    root = insert(root, -13);  
    root = insert(root, 14);  
    root = insert(root, -8);  
    root = insert(root, 15);  
    root = insert(root, 13);  
    root = insert(root, 7);  
    if (isTripletPresent(root))  
        cout << "Present";  
    else
        cout << "Not Present";  
    return 0;  
}

//Complexity: O(n^2)