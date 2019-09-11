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

void heap_sort_itr(int arr[], int n){
	
	
	for (int i=n-1;i > 0; i--)
	{
		swap(arr[i], arr[0]);
		int j=0, index;
		
		do{
			index = j*2+1;
			
			if (arr[index] < arr[index+1] && index <i-1)
				index++;
			if(arr[j]<arr[index] && index < i)
				swap(arr[j],arr[index]);
			j = index;
			
		} while(index<i);
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
	max_heapify(arr,size,0);
	heap_sort_itr(arr,size);
	printarr(arr,size);

	return 0;
}