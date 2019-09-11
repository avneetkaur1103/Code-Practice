#include <iostream>
using namespace std;

int binary_search(int arr[], int start, int end, int k){
	int mid;
	if (end >= start){
		mid = start + (end -1) /2;
	
		if (arr[mid] == k)
			return mid;
		if (k < arr[mid])
			return binary_search(arr, start, mid -1, k);
		
		return binary_search(arr, mid+1,end, k);
	}
		return -1; 
}

int main() {
	int arr[] = {2,5,9,13,16,23};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout<<binary_search(arr,0, n-1,9)<<endl;
	return 0;
}

Complexity:O(logn)
