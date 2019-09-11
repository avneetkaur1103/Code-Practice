#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void bucket_sort(float arr[], int n){
	vector<float> v[n];
	
	for (int i=0;i<n; i++){
		int j = (arr[i]*n);
		v[j].push_back(arr[i]);
	}
	
	for (int i=0; i<n; i++)
		sort(v[i].begin(),v[i].end());

	int index=0;
	for (int i=0; i<n; i++){
		for(int k=0; k<v[i].size(); k++){
			arr[index++] = v[i][k];
		}
	}
}

int main() {
	float arr[] = {0.56, 0.93, 0.01, 0.75, 0.47, 0.66, 0.27};
	int n = sizeof(arr)/sizeof(arr[0]);
	bucket_sort(arr,n);
	cout<<"Sorted array: ";
	for (int i = 0; i<n; i++)
		cout<<arr[i]<<"\t";
	return 0;
}
