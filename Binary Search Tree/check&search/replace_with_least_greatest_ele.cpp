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

void insert(Node* &root, int key, Node*& succ){
	if(!root)
		root = newNode(key);

	if(key < root->data){
		succ = root;
		insert(root->left,key,succ);
	}
	else if(key > root->data)
		insert(root->right,key,succ);
}

void replace(int arr[], int n){
	Node* root = NULL;
	for(int i=n-1;i>=0;i--){
		Node* succ = NULL;
		insert(root,arr[i],succ);

		if(succ)
			arr[i] = succ->data;
		else
			arr[i] = -1;
	}
	
}

int main(){
	int arr[] = { 8, 58, 71, 18, 31, 32, 63, 92, 
                  43, 3, 91, 93, 25, 80, 28 }; 
    int n = sizeof(arr)/ sizeof(arr[0]); 
  
    replace(arr, n); 
  
    for (int i = 0; i < n; i++) 
        cout << arr[i] << " "; 
  
    return 0;
}

//Complexity (Worst Case): O(n^2)
//O(nlogn), if using Balanced Trees