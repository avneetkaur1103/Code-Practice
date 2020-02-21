#include <iostream>
#include <stack>

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

void leafNode(int pre[], int n){
	int i,j;
	stack<int> s;

	for(i=0,j=1;j<n;i++,j++){
		bool found = false;

		if(pre[i] > pre[j]){
			s.push(pre[i]);
		}
		else{
			while(!s.empty()){
				if(pre[j] > s.top()){
					s.pop();
					found = true;
				}
				else
					break;
			}

		}
		if(found)
			cout<<pre[i]<<" ";
	}
	cout<<pre[n-1]<<" "; 
}

int main(){
	int preorder[] = { 890, 325, 290, 530, 965 }; 
    int n = sizeof(preorder)/sizeof(preorder[0]); 
  
    leafNode(preorder, n); 
    return 0; 
}

//Complexity: O(n)