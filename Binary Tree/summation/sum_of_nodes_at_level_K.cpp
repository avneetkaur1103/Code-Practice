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

int sumAtKthLevel(string str, int k){
	int level = -1, sum =0;

	for(int i=0;i<str.length();i++){
		if(str[i] == '(')
			level++;
		else if(str[i] == ')')
			level--;
		else{
			if(level == k)
				sum += str[i] - '0';
		}
	}
	return sum;
}

int main() 
{ 
    string tree = "(0(5(6()())(4()(9()())))(7(1()())(3()())))"; 
    int k = 2; 
    cout << sumAtKthLevel(tree, k); 
    return 0; 
} 

//Complexity:O(n)