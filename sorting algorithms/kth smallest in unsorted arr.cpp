#include <iostream>
#include <algorithm>
using namespace std;
 
int Kthsmallest(int arr[], int n, int k){
	sort(arr,arr+n);
	return arr[k-1];
}
 
int main() {
	int arr[] = {67,55,90,3,14,25,38,1,77};
	int n = sizeof(arr)/sizeof(arr[0]);
	int k=4;
	cout<<"Kthsmallest: "<<Kthsmallest(arr,n,k);
	return 0;
}

//complexity:O(nlogn)
