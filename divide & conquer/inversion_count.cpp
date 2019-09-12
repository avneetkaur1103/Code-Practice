#include <iostream>
using namespace std;

int merge(int arr[], int temp[], int l,int mid, int r){
	int i,j,k,inv_count = 0;
	i = l;
	j = mid;
	k = l;

	while(i<=mid-1 && j<=r){
		if(arr[i] <= arr[j])
			temp[k++] = arr[i++];
		else{
			temp[k++] = arr[j++];
			inv_count += mid - i;
		}
	}

	while(i<=mid-1)
		temp[k++] = arr[i++];
	while(j<=r)
		temp[k++] = arr[j++];

	for(i = l;i<=r;i++)
		arr[i] = temp[i];

	return inv_count;
}

int _mergesort(int arr[], int temp[], int l, int r){
	int mid, inv_count =0;

	if(r > l){
		 mid = (r+l)/2;
		

		inv_count += _mergesort(arr,temp,l,mid);
		inv_count += _mergesort(arr,temp,mid+1,r);

		inv_count += merge(arr,temp,l,mid+1,r);
	}

	return inv_count;
}

int mergesort(int arr[], int n){
	int temp[n];
	return _mergesort(arr,temp,0,n-1);
}

int main(){
	int arr[] =  {1, 20, 6, 4, 5 };  
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<< "No. of inversions: " <<mergesort(arr,n)<<endl;
    return 0;
}

//Complexity: O(nlogn)