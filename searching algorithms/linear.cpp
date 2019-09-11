#include <iostream>
using namespace std;

int Linear_search(int arr[], int n, int k){
	int i;
	for (i = 0; i < n; i++){
		if(arr[i] == k)
			return i;
	}
	return -1;
}
int main() {
	int arr[] = {2,5,14,23,31};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout<<Linear_search(arr,n,14)<<endl;
	cout<<Linear_search(arr,n,0)<<endl;
	
	return 0;
}

//Complexity: O(n)
