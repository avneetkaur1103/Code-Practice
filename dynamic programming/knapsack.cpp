#include <iostream>
using namespace std;

int max(int a, int b){
	return (a>b)?a:b;
}

int knapsack(int W, int wt[], int val[], int n){
	int i,w;
	int kp[n+1][W+1];
	
	for (i=0;i<=n;i++){
		for (w=0;w<=W;w++){
			if(i==0 || w==0)
				kp[i][w] = 0;
			else if (wt[i-1]<W)
				kp[i][w] = max(kp[i-1][w], val[i-1]+kp[i-1][w-wt[i-1]]);
			else
				kp[i][w] = kp[i-1][w];
		}
	}
	return kp[n][W];
}

int main() {
	int val[]={60, 100, 120};
	int wt[]={10, 20, 30}; 
    int  W = 50; 
	int n =sizeof(val)/sizeof(val[0]);
	cout<<"0-1 knapsack: "<<knapsack(W,wt,val,n);
	return 0;
}

//complexity: O(n*W)