#include <iostream>
using namespace std;

void shell_sort(int arr[], int n){
	for(int gap = n/2; gap > 0; gap /= 2){
		for(int i = gap; i <n ; i++){
			int temp = arr[i];
			int j;
			for (j = i; j >= gap && arr[j-gap] > temp; j -= gap)
				arr[j] = arr[j-gap];
			arr[j] = temp;
			
		}
	}	
}

int main() {
	int arr[] = {10,8,43,21,89,65,34,78};
	int n = sizeof(arr)/sizeof(arr[0]);
	shell_sort(arr,n);
	cout<<"Sorted array: ";
	for(int i = 0; i<n;i++)
		cout<<arr[i]<<"\t";
	return 0;
}

//Complexity:o(n^2)