#include <iostream>
using namespace std;

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int arr[],int l,int r){
	int pi = arr[r];
	
	int i,j;
	i=l-1;
	for (j=l;j<=r-1;j++){
		if(arr[j]<=pi){
			i++;
			swap(&arr[j],&arr[j]);
		}
	}
	
	swap(&arr[i+1],&arr[r]);
	return (i+1);
}

void quick_sort(int arr[], int l, int r){
	if (r>l){
	int pivot = partition(arr,l,r);
	
	quick_sort(arr,l,pivot-1);
	quick_sort(arr,pivot+1,r);
	}
}

void print_arr(int arr[],int n){
	for (int i=0;i<n;i++)
		cout<<arr[i]<<"\t";
	cout<<endl;
}

int main() {
	int arr[]={89,4,35,29,65,43,1};
	int n= sizeof(arr)/sizeof(arr[0]);
	print_arr(arr,n);
	quick_sort(arr,0,n-1);
	print_arr(arr,n);
	return 0;
}
