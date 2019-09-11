#include <iostream>
using namespace std;

void max_heapify(int arr[], int size, int i){
	int large = i;
	int l = i*2+1;
	int r = i*2+2;
	
	if (l < size && arr[l] > arr[i])
		large = l;
	if (r < size && arr[r] > arr[large])
		large = r;
	if (large != i){
		swap(arr[i], arr[large]);
		max_heapify(arr,size,large);
	}
}

void heap_sort_rec(int arr[], int n){
	for (int i = n-1/2;i >= 0;i--){
		max_heapify(arr,n,i);
	}	
	
	for (int i=n-1;i >= 0; i--)
	{
		swap(arr[i], arr[0]);
		max_heapify(arr,i,0);
	}
}

void swap(int *x,int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}

void printarr(int arr[], int size){
	for (int i = 0; i < size; i++){
		cout<<arr[i]<<"\t";
	}
	cout<<endl;
}

int main() {
	int arr[] = {12, 11, 13, 5, 6, 7};
	int size = sizeof(arr)/sizeof(arr[0]);
	printarr(arr,size);
	heap_sort_rec(arr,size);
	printarr(arr,size);

	return 0;
}