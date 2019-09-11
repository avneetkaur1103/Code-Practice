#include <iostream>
using namespace std;

int num_of_swaps(int arr[], int n){
	int i;
	int max=-1, min = arr[0], l=0, r=0;
	for (i=1;i<n;i++){
		if (arr[i] <= min){
			min = arr[i];
			r = i;
		}
		if(arr[i] >max){
			max = arr[i];
			l = i;
		}
	}
	
	if (l<r)
		return l+(n-r-1);
	else
		return l + (n-r-2);
}

int main() {
	int a[] = { 5, 6, 1, 3 }; 
    int n = sizeof(a)/sizeof(a[0]); 
    cout<<"Number of swaps: " << num_of_swaps(a,n);
	return 0;
}
