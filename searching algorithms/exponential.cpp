#include <iostream>
using namespace std;

int binary_search(int arr[],int l,int h, int x){
	if (h >= l){
		
		int mid = (l + (h - 1))/2;
		
		if (arr[mid] == x)
			return mid;
		
		if (arr[mid] > x)
			return binary_search(arr,l,mid-1,x);
		else
			return binary_search(arr,mid+1,h,x);
	}
	return -1;
}

int exponential_search(int arr[], int n, int x){
	if (arr[0] == x)
		return 0;
		
	int i = 1;
	while (i < n && arr[i] <= x)
		i = i*2;

	return binary_search(arr,i/2,min(i,n),x);
	
}

int main() {
	int arr[]={0,11,22,33,44,55,66};
	int n =sizeof(arr)/sizeof(arr[0]);
	int x =55;
	cout<<exponential_search(arr,n,x);
	return 0;
}
