#include <iostream>
using namespace std;

int maxDiff(int arr[], int n){
	if (n == 0 || n == 1)
		return -1;
		
	int max_diff = arr[1] - arr[0];
	int min_so_far  = arr[0];
	
	for(int i=0;i<n;i++){
		if(max_diff < arr[i] - min_so_far)
			max_diff = arr[i] - min_so_far;
			
		if(arr[i] < min_so_far)
			min_so_far = arr[i];
	}
	
	return max_diff;
}

int main() 
{ 
  int arr[] = {1, 2, 90, 10, 110}; 
  int n = sizeof(arr) / sizeof(arr[0]); 
    
  // Function calling 
  cout << "Maximum difference is " << maxDiff(arr, n); 
  
  return 0; 
} 
 //TC: O(n)
 //SC: O(1)
