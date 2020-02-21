#include <iostream>
using namespace std;

int depth_util(char pre[], int len, int idx){
	if(idx == len || pre[idx] == 'l')
		return 0;

	idx++;
	int ld = depth_util(pre,len,idx);

	idx++;
	int rd = depth_util(pre,len,idx);

	return (max(ld,rd)+1);

}

int depth(char pre[], int len){
	return depth_util(pre,len,0);
}

int main(){
	char preorder[]="nlnnlll";
	int len = strlen(preorder);
	int d = depth(preorder, len);
	cout<<"Depth: "<<d;
	return 0;
}