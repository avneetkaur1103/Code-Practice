#include <iostream>
using namespace std;

int RotatedArrBinarySearch(int arr[], int x, int low, int high){
	if(low > high)
		return -1;

	int mid = (high+low)/2;

	if(arr[mid] == x)
		return mid;

	if(arr[low]<=arr[mid]){ //left is sorted
		if(arr[low]<=x && arr[mid] >x)
			return RotatedArrBinarySearch(arr,x,low,mid -1);
		else
			return RotatedArrBinarySearch(arr,x,mid+1,high);
	}
	else{//Right is sorted
		if(arr[mid] <=x && arr[high] >x)
			return RotatedArrBinarySearch(arr,x,mid+1,high);
		else
			return RotatedArrBinarySearch(arr,x,low,mid-1);
	}

	return -1;
}

int main(){
	int arr[] = {15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14};
	int x = 5;
	int n = sizeof(arr)/sizeof(arr[0]);
	cout<< RotatedArrBinarySearch(arr, x, 0,n-1);
	return 0;
}

//Complexity:O(logn)