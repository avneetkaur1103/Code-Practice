#include <iostream>
using namespace std;

/*void swap(int a, int b){
	int temp = a;
	a = b;
	b = temp;
}*/

void cycle_sort(int arr[], int n){
	int write = 0;
	
	for (int cycle_start = 0; cycle_start <= n-2; cycle_start++){
		int pos = cycle_start;
		int item = arr[cycle_start];
		
		for (int i = cycle_start+1; i<n; i++){
			if (arr[i]<item)
				pos++;
		}
		
		if (pos == cycle_start)
			continue;
		
		while(item == arr[pos])
			pos += 1;
			
		if(pos != arr[pos]){
			swap(item,arr[pos]);
			write++;
		}
		
		while(pos != cycle_start){
			pos = cycle_start;
			for (int i = cycle_start+1; i<n; i++)
				if (arr[i] < item)
					pos += 1;
					
			while (item == arr[pos])
				pos += 1;
				
			if(item != arr[pos]){
				swap(item, arr[pos]);
				write++;
			}
		}
	}
	
	cout<<"write: " <<write << endl;
}

int main() {
	int arr[]= {5,2,27,15,92};
	int n = sizeof(arr)/sizeof(arr[0]);
	cycle_sort(arr,n);
	cout<<"After sort: ";
	for(int i = 0;i<n;i++)
		cout<<arr[i]<<"\t";
	return 0;
}
