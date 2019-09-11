#include <iostream>
#include <climits>
using namespace std;

int max(int a, int b){
	return (a>b)?a:b;
}

int cutrod(int price[], int n){
	int val[n+1];
	int i,j;
	val[0]=0;
	
	for (i=1;i<=n;i++){
		int max_val = INT_MIN;
		for (j=0;j<i;j++)
			max_val = max(max_val, price[j] + val[i-j-1]);
		val[i] = max_val;
	}
	return val[n];
}

int main() {
	int arr[] = {1, 5, 8, 9, 10, 17, 17, 20};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout<<"The max value is: "<<cutrod(arr,n);
	return 0;
}

//complexity: O(n^2)