#include <iostream>
using namespace std;

void insert_sort(int arr[],int n){
	int i,j,key;
	for (i=1; i<n; i++){
		key = arr[i];
		j = i-1;
		while (j>=0 && arr[j] > key){
			arr[j+1] = arr[j];
			j = j-1;
		}
		arr[j+1] = key;
	}
}

void print_arr(int arr[],int n){
	for (int i = 0;i<n; i++){
		cout<<arr[i]<<"\t";
	}
	cout<<endl;
}

int main() {
	int arr[]= {33,21,9,67,54,95,89};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout<<"Unsorted: ";
	print_arr(arr,n);
	insert_sort(arr,n);
	cout<<"Sorted: ";
	print_arr(arr,n);
	return 0;
}

//complexity: O(n*2)