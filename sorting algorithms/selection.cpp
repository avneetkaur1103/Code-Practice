#include <iostream>
using namespace std;

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void selection_sort(int arr[], int n){
	int i,j, min;
	for (i=0; i<n-1; i++){
		min = i;
		for(j=i+1; j<n; j++){
			if(arr[min] > arr[j])
				min = j;
		}
		swap(&arr[min],&arr[i]);
	}
}

void printarr(int arr[], int n){
	for (int i = 0; i<n; i++){
		cout<<arr[i]<<"\t";
	}
	cout<<endl;
}

int main() {
	int arr[]={9,2,45,39,12,1,67};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout<<"Unsorted: ";
	printarr(arr,n);
	selection_sort(arr,n);
	cout<<"Sorted: ";
	printarr(arr,n);
	return 0;
}

//Complexity: o(n^2)
