#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct Node{
	int data;
	struct Node* left, *right;
};

struct Node* getNode(int data){
	struct Node* n = (struct Node*)malloc(sizeof(struct Node));
	n->data = data;
	n->left = n->right = NULL;
	return n;
}

int SumOfAllNodesBT(int l){
	int numOfLeafNodes = pow(2, l-1);
	vector<int> v[l];

	for(int i=1;i<=numOfLeafNodes;i++){
		v[l-1].push_back(i);
	}

	for(int i=l-2;i>=0;i--){
		int k=0;

		while(k<v[i+1].size()-1){
			v[i].push_back(v[i+1][k] + v[i+1][k+1]);
			k += 2;
		}
	}

	int sum = 0;

	for(int i=0;i<l;i++){
		for(int j=0;j<v[i].size();j++){
			sum += v[i][j];
		}
	}
	return sum;
}

int main(){
	int l=3;
	cout<<SumOfAllNodesBT(l);
	return 0;
}
//Complexity: O(n)


/*
O(1) approach to solve this:

sum of last level = (numofLeafNode * (numOfLeafNode+1))/2;
sum of all levels = sum of last level * no. of levels
*/