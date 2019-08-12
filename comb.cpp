#include <iostream>
using namespace std;

int next_gap(int n){
	int gap = (n*10)/13;
	if (gap <1)
		return 1;
	return gap;
}

void comb_sort(int arr[], int n){
	int gap = n;
	
	while (gap != 1){
		gap = next_gap(gap);
		
		for (int i=0;i<n-gap; i++){
			if (arr[i]>arr[i+gap])
				swap(arr[i], arr[i+gap]);
		}
	}
}

int main() {
	int arr[] = {8, 4, 1, 56, 3, -44, 23, -6, 28, 0};
	int n = sizeof(arr)/sizeof(arr[0]);
	comb_sort(arr,n);
	cout<<"After sort:";
	for (int i=0;i<n;i++)
		cout<<arr[i]<<"\t";
	return 0;
}

//complexity: Best- O(n); Avg and worst case: O(n^2) (like bubble sort)