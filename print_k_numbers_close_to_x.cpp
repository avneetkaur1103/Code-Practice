#include <iostream>
using namespace std;

int cross_point(int arr[], int l, int r, int x){
	if (arr[l] > x)
		return l;
	if (arr[r] <= x)
		return r;
	
	int mid = l + (r-l)/2;
	if (x >= arr[mid] && x < arr[mid+1])
		return mid;
	if (x < arr[mid])
		return cross_point(arr,l,mid-1,x);
	else if (x > arr[mid])
		return cross_point(arr,mid+1,r,x);
}

void print_K_numbers(int arr[], int n, int k, int x){
	int l = cross_point(arr,0,n-1,x);
	int r=l+1;
	int count = 0;
	if (arr[l] == x) l--;
	
	while (l>=0 && r<n && count <k){
		if (x-arr[l] < arr[r] -x)
			cout<<arr[l--]<<",";
		else
			cout<<arr[r++]<<",";
		count++;
	}
	
	while (count <k & l>=0){
		cout<<arr[l--]<<",";
		count++;
	}
	
	while(count <k && r<n){
		cout<<arr[r++]<<",";
		count++;
	}
}
int main() {
	int arr[] ={12, 16, 22, 30, 35, 39, 42, 
               45, 48, 50, 53, 55, 56}; 
   int n = sizeof(arr)/sizeof(arr[0]); 
   int x = 35, k = 4; 
   print_K_numbers(arr,n,k,x);
	return 0;
}