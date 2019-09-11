#include <iostream>
using namespace std;

void count_sort(int arr[], int n, int exp){
	int output[n];
	int count[n];
	
	for(int i=0;i<n;i++)
		count[i] = 0;
	
	for (int i=0;i<n;i++){
		count[(arr[i]/exp)%n]++;
	}
	
	for (int i=1;i<n; i++)
		count[i] += count[i-1];
		
	for (int i = n-1; i>=0; i--){
		output[count[(arr[i]/exp)%n]-1] = arr[i];
		count[(arr[i]/exp)%n]--;
	}
	
	for (int i=0;i<n; i++)
		arr[i] = output[i];
}

void sort_in_range_1tosqrofn(int arr[], int n){
	count_sort(arr,n,1); //one's place
	count_sort(arr, n,n); //10s place
}

void print_arr(int arr[], int n){
	for (int i=0;i<n;i++)
		cout<<arr[i]<<"\t";
		
	cout<<endl;
}

int main() {
	int arr[]={40, 12, 45, 32, 33, 1, 22};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout<<"Unsorted array: ";
	print_arr(arr,n);
	sort_in_range_1tosqrofn(arr,n);
	cout<<"Sorted array: ";
	print_arr(arr,n);
	return 0;
}

//complexity: 
