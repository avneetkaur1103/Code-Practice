#include <iostream>
#include <vector>
using namespace std;

void pigeonhole_sort(int arr[], int n){
	int min = arr[0], max = arr[0];
	for (int i = 0; i<n; i++){
		if (arr[i] < min)
			min = arr[i];
		if (arr[i] > max)
			max = arr[i];
	}
	int range = max - min + 1;
	vector<int> holes[range];
	
	for (int i = 0; i < n; i++)
		holes[arr[i] - min].push_back(arr[i]);
		
	int index = 0;
	for (int i=0; i< range; i++){
		for (vector<int>::iterator it = holes[i].begin(); it != holes[i].end();it++){
			arr[index++] = *it;
		}
	}	
}

int main() {
	int arr[] = {9,3,7,1,5,0,8};
	int n = sizeof(arr)/sizeof(arr[0]);
	pigeonhole_sort(arr,n);
	cout<<"Sorted array: ";
	for (int i =0; i<n; i++)
		cout<<arr[i]<<"\t";
	return 0;
}

//Complexity: O(n+range) (like count sort)