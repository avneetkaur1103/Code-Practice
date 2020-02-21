#include <iostream>
#include <climits>
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

void constructTree(int d, int n, int h){
	if(d==1){
		if(n==2 && h==1)
			cout<<"1 2"<<endl;
		else
			cout<<"-1"<<endl;
	}
	if(d>2*h)
		cout<<"-1"<<endl;

	for(int i=1;i<=h;i++){
		cout<<i<<" "<<i+1<<endl;
	}

	if(d>h){
		cout<<"1 "<<h+2<<endl;
		for(int i=h+2;i<=d;i++)
			cout<<i<<" "<<i+1<<endl;
	}

	for(int i=d+1;i<n;i++){
		int k=1;
		if(d==h)
			k=2;
		cout<<k<<" "<<i+1<<endl;
	}
}

int main(){
	int d=3, n=5, h=2;
	constructTree(d,n,h);
	return 0;
}

//Complexity:O(n)