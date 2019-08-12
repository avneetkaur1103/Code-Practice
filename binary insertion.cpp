#include <iostream>
using namespace std;

int binary_search(int arr[], int l, int r, int x){
	if (r<=l)
		return (arr[l]<x)?(l+1):l;
		
	int mid = l+(r-l)/2;
	if (arr[mid] == x)
		return (mid+1);
	if (arr[mid] < x)
		return binary_search(arr, mid+1,r,x);
	return binary_search(arr,l,mid-1,r);
}

void binary_insertion_sort(int arr[], int n){
	int i,key,j,loc;
	for (i=1;i<n;++i){
		key = arr[i];
		j=i-1;
		loc = binary_search(arr,0,j,key);
		while(j>=loc){
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1] = key;
	}
}

int main() {
	int a[] = {37, 23, 0, 17, 12, 72, 31, 46, 100, 88, 54};
	int n = sizeof(a)/sizeof(a[0]);
	binary_insertion_sort(a,n);
	cout<<"Sorted array: ";
	for (int i=0;i<n;i++)
		cout<<a[i]<<"\t";
	return 0;
}

//Complexity:O(logn)