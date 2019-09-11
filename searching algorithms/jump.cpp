#include <iostream>
#include <cmath>
using namespace std;

int jump_search(int arr[], int n, int x){
	int step = sqrt(n);
	int prev = 0;
	
	while (arr[min(step,n)-1] < x){
		prev = step;
		step += sqrt(n);
		
		if (prev >= n)
			return -1;
	}
	
	while (arr[prev] < x){
		prev++;
		if (prev == min(step,n))
			return -1;
	}
	
	if (arr[prev] == x)
		return prev;
	
	return -1;
}

int main() {
	int arr[]= {0,11,22,33,44,55,66,77,88,99};
	int n = sizeof(arr)/sizeof(arr[0]);
	int x = 44;
	cout<< jump_search(arr,n,x);
	return 0;
}

Complexity: o(sqrt(n))
