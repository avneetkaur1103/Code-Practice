#include <iostream>
using namespace std;

int max_in_arr(int arr[], int n){
	int m = arr[0];
	for (int j=1; j<n; j++){
		if(arr[j] > m)
			m = arr[j];
	}
	
	return m;
}

void count_sort(int arr[], int n , int place){
	int output[n];
	int count[10] = {0};
	
	for(int i=0; i<n; i++)
		count[(arr[i]/place)%10]++;
	
	for (int i=1; i<10; i++)
		count[i] += count[i-1];
		
	for (int i = n-1; i >=0; i--){
		output[count[(arr[i]/place)%10] -1] = arr[i];
		count[(arr[i]/place)%10]--;
	}
	
	for (int i=0; i<n; i++)
		arr[i] = output[i];
}

void radix_sort(int arr[], int n){
	int max = max_in_arr(arr,n);
	
	
	for (int i=1; max/i > 0; i *= 10){
		count_sort(arr,n,i);
	}
}

int main() {
	int arr[]={30,12,7,50,35,77,86};
	int n = sizeof(arr)/sizeof(arr[0]);
	radix_sort(arr,n);
	cout<<"After Sort: ";
	for (int i=0; i<n; i++)
		cout<<arr[i]<<"\t";
	return 0;
	
}

//Complexity: O(d*(n+b)), where d= max no of digits present in input integers, n = no of elements in array and b is base of input numbers (like for decimal it is 10)