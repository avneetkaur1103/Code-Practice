#include <iostream>
using namespace std;
 
int search_in_nearly_sorted(int arr[], int l, int r, int x){
	int mid = l + (r-1)/2;
	if (arr[mid] == x)
		return mid;
	if(mid>l && arr[mid-1] == x)
		return mid-1;
	if(mid < r && arr[mid+1] == x)
		return mid+1;
 
	if (arr[mid]>x)
		return search_in_nearly_sorted(arr,l,mid-2,x);
	else
		return search_in_nearly_sorted(arr, mid+2,r,x);
}
 
int main() {
	int arr[]={0,10,20,40,30,70,90};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout<<search_in_nearly_sorted(arr,0,n-1,40);
	return 0;
}

//complexity: O(log n)
