#include <iostream>
#include <stack>
#include <string>
using namespace std;

struct Node
{
	int data;
	struct Node* left, *right;
};

struct Node* newNode(int data){
	struct Node* n = (struct Node*)malloc(sizeof(struct Node));
	n->data = data;
	n->left = n->right = NULL;
	return n;
}

int find_idx(string str, int s, int e){
	if(s>e)
		return -1;

	stack<char> st;
	for(int i=s;i<=e;i++){
		if(str[i] == '(')
			st.push(str[i]);
		else if (str[i] == ')'){
			if(st.top() == '('){
				st.pop();
				if(st.empty())
					return i;
			}
		}
	}
	return -1;
}

struct Node* build_tree(string str, int s, int e){
	if(s>e)
		return NULL;
	struct Node* root= newNode(str[s] - '0');
	int idx = -1;

	if(s+1<=e && str[s+1] == '('){
		idx = find_idx(str, s+1, e);
	}

	if(idx != -1){
		root->left = build_tree(str,s+2,idx-1);
		root->right = build_tree(str,idx+2,e-1);
	}
	return root;
}

void preorder(struct Node* root){
	if (!root)
		return;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}

int main(){
	string str = "4(2(3)(1))(6(5))";
	int len = str.length();
	struct Node* root = build_tree(str, 0,len-1);
	preorder(root);
	return 0;
}