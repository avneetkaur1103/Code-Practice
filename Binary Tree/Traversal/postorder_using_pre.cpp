#include <iostream>
#include <climits>
using namespace std;

void printPostOrderUtil(int pre[],int n, int minval, int maxval, int &preindex){
	//cout<<"Util called for "<<pre[preindex]<<endl;

	if(preindex == n)
		return;
	if(pre[preindex] < minval || pre[preindex] > maxval)
		return;

	int val = pre[preindex];
	preindex++;

	printPostOrderUtil(pre,n,minval,val,preindex);
	printPostOrderUtil(pre,n,val,maxval,preindex);
	cout<<val<<" ";
}

void printPostOrder(int pre[], int n){
	int preindex = 0;
	printPostOrderUtil(pre,n,INT_MIN,INT_MAX,preindex);
}

int main(){
	int pre[] = {40,30,35,80,100}; 
    int n = sizeof(pre) / sizeof(pre[0]); 
    cout << "Postorder traversal " << endl; 
    printPostOrder(pre, n); 
    return 0;
}

//Complexity: O(n)