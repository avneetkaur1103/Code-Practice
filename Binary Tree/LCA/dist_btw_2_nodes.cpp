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

Node* findLCA(Node* root, int n1, int n2){
	if(!root)
		return NULL;

	if(root->data == n1 || root->data == n2)
		return root;

	Node* ln = findLCA(root->left,n1,n2);
	Node* rn = findLCA(root->right,n1,n2);

	if (ln && rn)
		return root;

	if(!ln)
		return rn;
	else
		return ln;
}

int findLevel(Node* root, int n, int level){
	if(!root)
		return -1;
	if(root->data == n)
		return level;

	int ll = findLevel(root->left,n,level+1);

	if(ll == -1)
		ll = findLevel(root->right,n,level+1);

	return ll;
}

	/*Node* printKthAncestors(Node* root, int lca,int k){
	if(!root)
		return NULL;


	if((root->data == lca) || (printKthAncestors(root->left,lca,k) == NULL) || (printKthAncestors(root->right,lca,k)== NULL)){
		if(k>0)
			k--;
		else if (k==0){
			cout<<root->data<<" ";
			return NULL;
		}	
		return root;
	}
}
*/
bool printAncestors(Node* root, int lca){
	if(!root)
		return false;


	if(root->data == lca){
		cout<<root->data<<" ";
		return true;
	}

	if(printAncestors(root->left,lca) || printAncestors(root->right,lca)){
		cout<<root->data<<" ";
		return true;
	}
	return false;
}

int findDistance(Node* root, int n1,int n2){
	Node* lca = findLCA(root,n1,n2);
	if(!lca)
		return -1;

	int d1 = findLevel(lca,n1,0);
	int d2 = findLevel(lca,n2,0);
	cout<<"Print Ancestors.."<<endl;
	printAncestors(root,lca->data);
	cout<<endl;
	/*int k=1;
	cout<<"Print kth Ancestors.."<<endl;
	Node* n = printKthAncestors(root,lca->data,k);
	if(n)
		cout<<"-1";
	cout<<endl;*/
	return d1+d2;
}

int main(){
	Node * root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 
    root->right->left->right = newNode(8); 
    cout << "Dist(6, 7) = " << findDistance(root, 4, 5);
    return 0;
}

//Complexity:O(n)