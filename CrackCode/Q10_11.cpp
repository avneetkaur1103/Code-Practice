#include <iostream>
using namespace std;

void swap(int *arr, int i, int max_idx){
	int temp = arr[max_idx];
	arr[max_idx] = arr[i];
	arr[i] = temp;
}

int _max(int *arr, int a, int b){
	return(arr[a]>arr[b] ? a:b);
}

void SortValleyPeak(int *arr, int n){
	for(int i=1;i<n;i += 2){
		int max_idx = -1;
		max_idx = _max(arr,i-1,_max(arr,i,i+1));
		//max_idx = _max(arr,i,i+1);
		//cout<<max_idx<<endl;
		if(i != max_idx){
			// /cout<<"going to swap"<<endl;
			swap(arr,i,max_idx);
		}
	}
}

int main(){
	int arr[] = {5,3,1,2,3};
	int n = sizeof(arr)/sizeof(arr[0]);
	SortValleyPeak(arr,n);
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	return 0;
}

//Complexity: O(n)