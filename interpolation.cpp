#include <iostream>
using namespace std;

int interpolation_search(int arr[], int n , int x){
	int low = 0, high = n-1;
	
	while (low <= high && x > arr[low] && x < arr[high] ){
		if (low == high){
			if (x == arr[low])
				return low;
			else
				return -1;
		}
		
		int pos = low + (((double)(high - low) / (arr[high] - arr[low])) * (x - arr[low]));
		if (arr[pos] == x)
			return pos;
		
		if (x > arr[pos])
			low = pos +1;
		else
			high = pos -1;
	}
	
	return -1;
}

int main() {
	int arr[]={0,11,22,33,44,55,66,77,88,99};
	int n = sizeof(arr)/sizeof(arr[0]);
	int x = 55;
	cout<<interpolation_search(arr,n,x);
	return 0;
}

Complexity: o(log log n)