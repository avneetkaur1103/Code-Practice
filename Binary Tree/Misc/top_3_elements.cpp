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

int findDistance(Node* root, int key){
	if(!root)
		return -1;

	if(root->data == key)
		return 0;

	int ldist = findDistance(root->left,key);
	if(ldist >= 0)
		return 1+ldist;
	else{
		int rdist = findDistance(root->right,key);
		if(rdist>=0)
			return 1+rdist;
	}
	return -1;
}

void topThreeElements(Node* root, int &f, int &s, int &t){
	if(!root)
		return;

	int curr = root->data;

	if(curr > f){
		t=s;
		s=f;
		f = curr;

	}

	else if(curr> s && curr <f){
		t=s;
		s = curr;
	}

	else if(curr >t && curr < f && curr <s)
		t = curr;

	topThreeElements(root->left,f,s,t);
	topThreeElements(root->right,f,s,t);
}

int main(){
  struct Node *root = newNode(1); 
  root->left = newNode(2); 
  root->right = newNode(3); 
  root->left->left = newNode(4); 
  root->left->right = newNode(5); 
  root->right->left = newNode(4); 
  root->right->right = newNode(5); 
  
  int first=0, second=0, third=0;
  topThreeElements(root,first,second,third);
  cout<<"Top 3 elements are: "<<first<<", "<<second<<" and "<<third<<endl;
  return 0;
}

//Complexity:O(n)

//Complexity:O(n)