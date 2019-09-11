#include <iostream>
#include <climits>
using namespace std;

int minimum(int a, int b){
	return (a<b)?a:b;
}

int min_jumps(int arr[], int n){
	int jumps[n];
	int i,j;
	if(n==0 || arr[0] == 0)
		return INT_MAX;
		
	jumps[0] = 0;
	for (i=1;i<n;i++){
		jumps[i] = INT_MAX;
		for (j=0;j<i;j++){
			if(arr[j]+j >= i && jumps[j] != INT_MAX)
				jumps[i] = minimum(jumps[i], jumps[j]+1);
		}
	}
	return jumps[n-1];
}

int main() {
	int arr[] = {1, 3, 6, 1, 0, 9};  
    int n = sizeof(arr)/sizeof(arr[0]);  
    cout<<"Minimum number of jumps to reach end: "<<min_jumps(arr,n);
	return 0;
}

//Complexity: O(n^2)