#include <iostream>
using namespace std;

bool printLeavesUtil(int pre[], int &i, int n, int min, int max){
	if(i>=n)
		return false;
	if(pre[i] > min && pre[i] < max){
		i++;
	
		bool left = printLeavesUtil(pre,i,n,min,pre[i-1]);
		bool right = printLeavesUtil(pre,i,n,pre[i-1],max);

		if(!left && !right)
			cout<<pre[i-1]<<" ";

		return true;
	}
	return false;
}

void printLeaves(int pre[], int n){
	int i=0;
	printLeavesUtil(pre,i,n,INT_MIN, INT_MAX);
}

int main(){
	int preorder[] = { 890, 325, 290, 530, 965 }; 
    int n = sizeof(preorder)/sizeof(preorder[0]); 
    printLeaves(preorder, n);     
    return 0; 
}