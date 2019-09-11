#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

struct Node{
	char c;
	struct Node *left, *right;
};

struct Node* newNode(char c){
	struct Node* n = (struct Node*) malloc(sizeof(struct Node));
	n->c = c;
	n->left = n->right = NULL;
	return n;
}

void inorder(struct Node *root){
	if(root){
		inorder(root->left);
		cout<<root->c<<" ";
		inorder(root->right);
	}
}

bool isOperator(char pf){
	if(pf =='+' || pf == '-' || pf == '*' || pf == '/' || pf == '^')
		return true;

	return false;
}

struct Node* construct_expr_tree(char postfix[]){
	stack<struct Node*> st;
	Node* t, *t1, *t2;
	int len = strlen(postfix);

	for(int i=0;i<len;i++){
		if (!isOperator(postfix[i])){
			t = newNode(postfix[i]);
			st.push(t);
			cout<<"Operand call"<<endl;
		}
		else
		{
			t = newNode(postfix[i]);
			t1 = st.top();
			st.pop();
			t2  = st.top();	
			st.pop();

			t->left = t1;
			t->right = t2;

			st.push(t);
			cout<<"operator call"<<endl;
		}

	}

	t = st.top();
	st.pop();

	return t;
}

int main(){
	char postfix[] = "ab+ef*g*-";
	struct Node* root = construct_expr_tree(postfix);
	inorder(root);
	return 0;
}