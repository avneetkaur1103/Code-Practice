#include <iostream>
using namespace std;

void swap(int *a, int*b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void bubble_sort(int arr[], int n){
	int i,j;
	bool swapped;
	for (int i=0; i<n-1; i++){
		swapped = false;
		for(int j=0;j<n-1-i;j++){
			if (arr[j]>arr[j+1]){
				swap(&arr[j],&arr[j+1]);
				swapped = true;
			}
		}
		
		if (!swapped)
			break;
	}
}

void printarr(int arr[], int n){
	for (int i=0;i<n;i++){
		cout<<arr[i]<<"\t";
	}
	cout<<endl;
}

int main() {
	int arr[] = {43,67,12,34,90,2,17};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout<<"Unsorted: ";
	printarr(arr,n);
	bubble_sort(arr,n);
	cout<<"Sorted: ";
	printarr(arr,n);
	return 0;
}

//Complexity:
//Best Case: O(n)
//Worst Case: O(n*n)