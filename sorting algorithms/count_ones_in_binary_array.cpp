#include <iostream>
using namespace std;

int count_ones_binary_array_incr_order(int arr[], int n){
	if (arr[n-1] == 0)
		return 0;
	if (arr[0] == 1)
		return n;
	return (count_ones_binary_array_incr_order(arr,n/2) + count_ones_binary_array_incr_order(arr+n/2,n-n/2));
}

int count_ones_binary_array_decr_order(int arr[], int l, int r){
	if(r>=l){
		int mid = l+(r-l)/2;
		if((mid == r || arr[mid+1] == 0) && (arr[mid] == 1))
			return mid+1;
		else if (arr[mid] ==1)
			count_ones_binary_array_decr_order(arr,mid+1,r);
		else
			count_ones_binary_array_decr_order(arr,l,mid-1);
	}
}

int main() {
	int arr1[]={0,0,1,1,1,1,1,1};
	int n1= sizeof(arr1)/sizeof(arr1[0]);
	cout<<"count_ones_binary_array_incr_order: " << count_ones_binary_array_incr_order(arr1,n1)<<endl;
	int arr2[]={1,1,1,1,0};
	int n2= sizeof(arr2)/sizeof(arr2[0]);
	cout<<"count_ones_binary_array_decr_order: " << count_ones_binary_array_decr_order(arr2,0,n2-1)<<endl;
	return 0;
}

//Complexity: O(logn) for both
