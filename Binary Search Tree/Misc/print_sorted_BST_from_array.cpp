#include <iostream>
using namespace std;

void printSorted(int arr[], int s, int e){
	if(s>e)
		return;

	printSorted(arr,2*s+1,e);
	cout<<arr[s]<<" ";
	printSorted(arr,2*s+2,e);
}

int main() 
{ 
    int arr[] = {4, 2, 5, 1, 3}; 
    int arr_size = sizeof(arr)/sizeof(int); 
    printSorted(arr, 0, arr_size-1); 
    return 0; 
} 

//Complexity: O(n)