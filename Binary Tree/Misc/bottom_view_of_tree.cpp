#include <iostream>
#include <map>
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

void bottomViewUtil(Node* root,int curr,int hd,map<int,pair<int,int> > &m){
	if(root == NULL)
		return;

	if(m.find(hd) == m.end()){
		m[hd] = make_pair(root->data,curr);
	}
	else{
		//pair<int,int> p = m[hd];
		if(m[hd].second <= curr){
			m[hd].second = curr;
			m[hd].first = root->data;
		}
	}

	bottomViewUtil(root->left,curr+1,hd-1,m);
	bottomViewUtil(root->right,curr+1,hd+1,m);

}

void bottomView(Node* root){
	map<int, pair<int,int> > m;
	bottomViewUtil(root,0,0,m);

	map<int, pair<int,int> >::iterator it;
	for(it=m.begin(); it!= m.end(); it++){
		pair<int,int> p = it->second;
		cout<<p.first<<" ";
	}

}

int main(){
	Node * root = newNode(20); 
    root -> left = newNode(8); 
    root -> right = newNode(22); 
    root -> left -> left = newNode(5); 
    root -> left -> right = newNode(3); 
    root -> right -> left = newNode(4); 
    root -> right -> right = newNode(25); 
    root -> left -> right -> left = newNode(10); 
    root -> left -> right -> right = newNode(14); 
    bottomView(root);
    return 0;
}

//Complexity: O(n)