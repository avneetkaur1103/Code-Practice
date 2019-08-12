#include <iostream>
using namespace std;

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void sort_in_wave(int arr[], int n){
	int i;
	for (i= 0; i<n; i += 2){
		if (i >0 && arr[i]<arr[i-1])
			swap(&arr[i],&arr[i-1]);
		if(i<n-1 && arr[i] < arr[i+1] )
			swap(&arr[i],&arr[i+1]);
	}
}

int main() {
	int arr[]={90,23,56,12,33,45,87,1,67};
	int n = sizeof(arr)/sizeof(arr[0]);
	sort_in_wave(arr,n);
	cout<<"Wave sorted array: "<<endl;
	for (int i=0;i<n;i++)
		cout<<arr[i]<<"\t";
	return 0;
}

complexity:: O(n)